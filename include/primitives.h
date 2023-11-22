// ============================================================================================== //
// Primary author: Casey Walker
//
// Some OpenGL primitive drawings are included in this file and it's implementation.
// ============================================================================================== //

#if !defined(PRIMITIVES_H)
#define PRIMITIVES_H


namespace Primitives {
    // filled rectangle
    void rect(double x, double y, double w, double h);

    // hollow rectangle with line width
    void rect(double x, double y, double w, double h, double lw);
}

#endif // !defined(PRIMITIVES_H)
