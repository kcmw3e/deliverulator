// ============================================================================================== //
// Primary author: Casey Walker
//
// Colors can be a little annoying to deal with, so this is a struct to handle manipulation and
// storing of RGBA colors, and to make using them with OpenGL easier.
// ============================================================================================== //

#if !defined(RGBA_H)
#define RGBA_H

#include <cstddef>

#include "fssimplewindow.h"

using size_t = std::size_t;

struct RGBA {
    float r;
    float g;
    float b;
    float a = RGBA::norm;

    RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a = uint8_t(RGBA::norm));
    RGBA(float r, float g, float b, float a = RGBA::norm/RGBA::norm);

    void set_as_gl_color() const;
    void set_as_gl_clear_color() const;

    RGBA operator*(float scale) const;
    RGBA operator/(float scale) const;
    RGBA operator%(const RGBA& rhs) const;
private:
    static constexpr float norm = float(0xFF);
};

namespace Colors {
    const auto black = RGBA(uint8_t(0x0D), uint8_t(0x0D), uint8_t(0x0D));
    const auto white = RGBA(uint8_t(0xF8), uint8_t(0xF8), uint8_t(0xF8));
    const auto red   = RGBA(uint8_t(0x69), uint8_t(0x20), uint8_t(0x28));
    const auto green = RGBA(uint8_t(0x42), uint8_t(0x69), uint8_t(0x42));
    const auto blue  = RGBA(uint8_t(0x42), uint8_t(0x69), uint8_t(0x87));
}

#endif // !defined(RGBA)
