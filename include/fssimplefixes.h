// ============================================================================================== //
// Primary author: Casey Walker
//
// The window library provided by this class is a bit finicky and odd to work with. The wrappers
// below address that issue and make the interface a bit nicer to work with. Enums and constants are
// defined as well since the library doesn't define them.
// ============================================================================================== //

#if !defined(FSSIMPLEFIXES_H)
#define FSSIMPLEFIXES_H

#include <set>

#include "fssimplewindow.h"

namespace FSSimple_Fixes {
    enum fsbuffer_mode {
        DOUBLE_BUFFER = 1,
        SINGLE_BUFFER = 0,
    };

    enum fs_state {
        PRESSED  =  1,
        RELEASED =  0,
        UNKNOWN  = -1,
    };

    bool is_state_pressed(fs_state state);
    bool is_state_released(fs_state state);
    bool is_state_unknown(fs_state state);

    // Coerce an integer (usually returned by one of the fssimplewindow functions) into one of the
    // above enums. Any value not defined in the enum will be coerced to UNKNOWN.
    fs_state coerce(int state);

    // Query the key state of a key using one of the fssimplewindow key defines, coercing to an
    // fs_state enum.
    fs_state get_key_state(int key);

    struct Window {
        struct {
            int x;
            int y;
        } aspect_ratio;

        int w;
        int h;

        struct {
            int x;
            int y;
            int w;
            int h;
        } viewport;

        Window(int arx, int ary);
        void open(fsbuffer_mode mode = fsbuffer_mode::DOUBLE_BUFFER);

        // Update the members by querying the fssimplewindow library for window information.
        void update();

        // Set the OpenGL viewport based on the aspect_ratio member, scaling appropriately based on
        // scaling that each dimension can accommodate (in other words, scale the viewport at the
        // aspect ratio such that neither width nor height exceeds the window's dimensions).
        void update_viewport();

        // Convert x and y coordinates from fssimplewindow coordinates to viewport coordinates such
        // that offsets from the window edges are accounted for.
        void fs_coords_to_viewport_coords(int& x, int& y);
    };

    // Struct that can be subclassed to keep track of a pushbutton-style state. This is useful when
    // some like a keyboard key or mouse button state needs to be tracked and monitored. Especially
    // since fssimplewindow doesn't expose events, this can help simplify the polling process.
    struct Button {
        fs_state curr_state;
        fs_state past_state;

        Button();

        bool is_pressed();
        bool is_released();

        bool was_pressed();
        bool was_released();

        bool has_changed();
        bool has_changed_to_pressed();
        bool has_changed_to_released();

        void update(fs_state state);
    };

    // A class to help keep track of keyboard key states instead of using the fssimplewindow
    // interface. The downside to this method is that keys are queried for their state on demand
    // instead of queuing up change events or having event callbacks, so it is probably possible
    // that a key state change event is missed if the key is tapped extremely quickly, but so far
    // it hasn't been an issue.
    //
    // Note that before calling the update() member function, FsPollDevice() must be called in order
    // to update the fssimplewindow information which is queried by the update() call.
    struct Key: public Button {
        int code; // one of the defined FSKEY_* values from fssimplewindow

        static void update();
        Key(int code);
        ~Key();
    
    private:
        static std::set<Key*> keys;
    };

    // Similar to the Key class, this is to help streamline accessing mouse/cursor information, and
    // before update() is called FsPollDevice() must be called.
    struct Mouse {
        Button left;
        Button mid;
        Button right;
        int x;
        int y;

        void update();
    };
}

#endif // !defined(FSSIMPLEFIXES_H)
