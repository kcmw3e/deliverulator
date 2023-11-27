// ============================================================================================== //
// Primary author: Casey Walker
// ============================================================================================== //

#include <cmath>

#include "fssimplefixes.h"

namespace FSSimple_Fixes {
    bool is_state_pressed(fs_state state) {
        return state == fs_state::PRESSED;
    }

    bool is_state_released(fs_state state) {
        return state == fs_state::RELEASED;
    }

    bool is_state_unknown(fs_state state) {
        return state == fs_state::UNKNOWN;
    }

    fs_state coerce(int state) {
        if (state == 0)
            return fs_state::RELEASED;
        else if (state == 1)
            return fs_state::PRESSED;
        return fs_state::UNKNOWN;
    }

    fs_state get_key_state(int key) {
        return coerce(FsGetKeyState(key)); 
    }

    Window::Window(int arx, int ary)
    : aspect_ratio{arx, ary} { }   

    void Window::open(fsbuffer_mode mode) {
        FsOpenWindow(0, 0, this->aspect_ratio.x, this->aspect_ratio.y, mode);
    }

    void Window::update() {
        FsGetWindowSize(this->w, this->h);
    }

    void Window::update_viewport() {
        auto& ar = this->aspect_ratio;
        int w = this->w;
        int h = this->h;

        // if width is correct size already, this is what height needs to change to be
        int sxh = w*ar.y/ar.x;

        // if height is correct size already, this is what width needs to change to be
        int syw = h*ar.x/ar.y;

        int nw = w; // new width starting as w but may change if width needs to be scaled
        int nh = h; // new height starting as h but may change if height needs to be scaled
        
        if (sxh > h)  // means scaling for width makes height too tall
            nw = syw; // so scale by height instead
        else          // otherwise scaling for height makes width too wide
            nh = sxh; // so scale by width instead
        
        // correct x and y position of viewport to be centered in width and height
        // (one of them will be 0 since either nw == w or nh == h)
        int x = (w - nw)/2;
        int y = (h - nh)/2;
        w = nw;
        h = nh;

        glViewport(x, y, w, h);

        auto& vp = this->viewport;
        vp.x = x;
        vp.y = y;
        vp.w = w;
        vp.h = h;
    }

    void Window::fs_coords_to_viewport_coords(int& x, int& y) {
        auto& ar = this->aspect_ratio;
        int w = this->w;
        int h = this->h;

        // if height is correct size already, this is what width needs to change to be
        int sxh = w*ar.y/ar.x;

        // if width is correct size already, this is what height needs to change to be
        int syw = h*ar.x/ar.y;

        y = h - y; // fssimplewindow uses y = 0 as the top of the screen, so flip it
        if (sxh > h)  // means scaling for width makes height too tall
            x = x - std::abs(w - syw)/2;
        else          // otherwise scaling for height makes width too wide
            y = y - std::abs(h - sxh)/2;
    }

    Button::Button()
    : curr_state(fs_state::UNKNOWN),
      past_state(fs_state::UNKNOWN) { }

    bool Button::is_pressed() {
        return is_state_pressed(this->curr_state);
    }

    bool Button::is_released() {
        return is_state_released(this->curr_state);
    }

    bool Button::was_pressed() {
        return is_state_pressed(this->past_state);
    }

    bool Button::was_released() {
        return is_state_released(this->past_state);
    }

    bool Button::has_changed() {
        return !is_state_unknown(this->curr_state)
            && !is_state_unknown(this->past_state)
            && this->curr_state != this->past_state;
    }

    bool Button::has_changed_to_pressed() {
        return this->has_changed() && is_state_pressed(this->curr_state);
    }

    bool Button::has_changed_to_released() {
        return this->has_changed() && is_state_released(this->curr_state);
    }

    void Button::update(fs_state state) { 
        this->past_state = this->curr_state;
        this->curr_state = state;
    }

    std::set<Key*> Key::keys = std::set<Key*>();

    Key::Key(int code)
    : code(code) {
        Key::keys.insert(this);
    }

    Key::~Key() {
        Key::keys.erase(this);
    }

    void Key::update() {
        for (auto key: Key::keys)
            static_cast<Button*>(key)->update(get_key_state(key->code));
    }

    void Mouse::update() {
        int l;
        int m;
        int r;

        FsGetMouseState(l, m, r, this->x, this->y);

        this->left.update(coerce(l));
        this->mid.update(coerce(m));
        this->right.update(coerce(r));
    }
}
