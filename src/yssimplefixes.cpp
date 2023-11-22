// ============================================================================================== //
// Primary author: Casey Walker
// ============================================================================================== //

#include <cstring>

#include "fssimplewindow.h" // for OpenGL, takes care of finding headers on different OSes

#include "yssimplefixes.h"

using uint8_t = std::uint8_t;

static const size_t rgba_size = 4;

namespace YSSimple_Fixes {
    Raw_rgba_img Raw_rgba_img::from_file(std::string filename) {
        YsRawPngDecoder png;
        png.Decode(filename.c_str());
        png.Flip();

        return Raw_rgba_img(png.wid, png.hei, png.rgba);
    }

    Raw_rgba_img::Raw_rgba_img(size_t w, size_t h, uint8_t* rgba)
    : w(w),
      h(h) {
        size_t len = this->w*this->h*rgba_size;
        auto new_rgba = new uint8_t[len];

        std::memcpy(new_rgba, rgba, len*sizeof(*rgba));

        this->rgba = new_rgba;
    }

    Raw_rgba_img::~Raw_rgba_img() {
        delete this->rgba;
    }

    void Raw_rgba_img::draw() const {
        glRasterPos2d(this->x, this->y);
        glDrawPixels(this->w, this->h, GL_RGBA, GL_UNSIGNED_BYTE, this->rgba);
    }
}
