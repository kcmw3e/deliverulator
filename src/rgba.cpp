// ============================================================================================== //
// Primary author: Casey Walker
// ============================================================================================== //
#include "rgba.h"

RGBA::RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
: r(float(r)/RGBA::norm),
  g(float(g)/RGBA::norm),
  b(float(b)/RGBA::norm),
  a(float(a)/RGBA::norm) { }

RGBA::RGBA(float r, float g, float b, float a)
: r(r),
  g(g),
  b(b),
  a(a) { }

void RGBA::set_as_gl_color() const {
    glColor4f(this->r, this->g, this->b, this->a);
}

void RGBA::set_as_gl_clear_color() const {
    glClearColor(this->r, this->g, this->b, this->a);
}

RGBA RGBA::operator*(float scale) const {
    return RGBA(this->r*scale, this->g*scale, this->b*scale, this->a*scale);
}

RGBA RGBA::operator/(float scale) const {
    return RGBA(this->r/scale, this->g/scale, this->b/scale, this->a/scale);
}

RGBA RGBA::operator%(const RGBA& rhs) const {
    return RGBA(
        (this->r + rhs.r)/2.0f, (this->g + rhs.g)/2.0f, (this->b + rhs.b)/2.0f,
        (this->a + rhs.a)/2.0f
    );
}

