// ============================================================================================== //
// Primary author: Casey Walker
//
// Some OpenGL primitive drawings are included in this file and it's implementation.
// ============================================================================================== //

#if !defined(PRIMITIVES_H)
#define PRIMITIVES_H

#include <string>

#include "rgba.h"

namespace Primitives {
    // filled rectangle
    void rect(double x, double y, double w, double h);

    // hollow rectangle with line width
    void rect(double x, double y, double w, double h, double lw);

    void rect(double x, double y, double w, double h, RGBA c);
    void rect(double x, double y, double w, double h, double lw, RGBA c);

    void text(double x, double y, std::string str);
    void text(double x, double y, std::string str, RGBA c);
    void table_cell(
        double x, double y, double w, double h, double lw, RGBA rc,
        std::string str, RGBA sc
    );
}

#endif // !defined(PRIMITIVES_H)
