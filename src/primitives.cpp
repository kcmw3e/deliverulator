// ============================================================================================== //
// Primary author: Casey Walker
// ============================================================================================== //

#include "fssimplewindow.h" // includes OpenGL, takes care of different OS locations

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
}
