// ============================================================================================== //
// Primary author: Casey Walker
// ============================================================================================== //

#include "fssimplewindow.h" // includes OpenGL, takes care of different OS locations
#include "ysglfontdata.h"

#include "primitives.h"

namespace Primitives {
    void rect(double x, double y, double w, double h) {
        glBegin(GL_QUADS);
        glVertex2d(x    , y    );
        glVertex2d(x + w, y    );
        glVertex2d(x + w, y + h);
        glVertex2d(x    , y + h);
        glEnd();
    }

    void rect(double x, double y, double w, double h, double lw) {
        glLineWidth(lw);
        glBegin(GL_LINE_LOOP);
        glVertex2d(x    , y    );
        glVertex2d(x + w, y    );
        glVertex2d(x + w, y + h);
        glVertex2d(x    , y + h);
        glEnd();
    }

    void rect(double x, double y, double w, double h, RGBA c) {
        c.set_as_gl_color();
        rect(x, y, w, h);
    }

    void rect(double x, double y, double w, double h, double lw, RGBA c) {
        c.set_as_gl_color();
        rect(x, y, w, h, lw);
    }

    void text(double x, double y, std::string str) {
        glRasterPos2d(x, y);
        YsGlDrawFontBitmap12x16(str.c_str());
    }

    void text(double x, double y, std::string str, RGBA c) {
        c.set_as_gl_color();
        text(x, y, str);
    }

    void table_cell(
        double x, double y, double w, double h, double lw, RGBA rc,
        std::string str, RGBA sc
    ) {
        rect(x, y, w, h, lw, rc);
        text(x + 40, y + 30, str, sc);
    }
}
