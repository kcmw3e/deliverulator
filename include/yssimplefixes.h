// ============================================================================================== //
// Primary author: Casey Walker
//
// The PNG library provided by this class is a bit weird and odd to work with, so here are some
// wrappers that address that issue and make the interface a bit nicer to work with.
// ============================================================================================== //

#if !defined(YSSIMPLEFIXES_H)
#define YSSIMPLEFIXES_H

#include <string>
#include <cstdint>

#include "yspng.h"

using uint8_t = std::uint8_t;

namespace YSSimple_Fixes {
    struct Raw_rgba_img {
        const uint8_t* rgba;
        const size_t w;
        const size_t h;
        double x = 0.0;
        double y = 0.0;

        static Raw_rgba_img from_file(std::string filename);

        Raw_rgba_img(size_t w, size_t h, uint8_t* rgba);
        ~Raw_rgba_img();
        void draw() const;
    };

}

#endif // !defined(YSSIMPLEFIXES_H)
