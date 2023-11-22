// ============================================================================================== //
// Primary author: Casey Walker
//
// There are various places in the project that thing such as colors and line widths, cell heights,
// etc. can be tweaked. This is where those things are configured.
// ============================================================================================== //

#if !defined(CONFIG_H)
#define CONFIG_H

#include "rgba.h"

namespace RGBA_Colors = Colors;

namespace Config {
    namespace Colors {
        static const auto bg = RGBA_Colors::black;
        static const auto text = RGBA_Colors::white;
        static const auto text_active = RGBA_Colors::red;
        static const auto cell_border = RGBA_Colors::white;
        static const auto node = RGBA_Colors::black;
    }

    namespace Table {
        static const double cell_w = 200.0;
        static const double cell_h = 40.0;
        static const double cell_bw = 2.0;
    }
}

#endif // !defined(CONFIG_H)

