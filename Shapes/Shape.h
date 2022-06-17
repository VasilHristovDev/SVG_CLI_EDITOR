#ifndef SVG_CLI_EDITOR_SHAPE_H
#define SVG_CLI_EDITOR_SHAPE_H
#include <fstream>
#include "../misc/SvgElement.h"

///Interface with pure virtual methods only
class Shape {
public:
    virtual Shape * copy() = 0;
    virtual void read(SvgElement & element) = 0;
    virtual void print(std::ostream & out) = 0;
    virtual void write(std::ostream & out) = 0;
    virtual void setX(int horizontal) = 0;
    virtual void setY(int vertical) = 0;
    virtual bool isWithinCircle(int cx, int cy, int r) = 0;
    virtual bool isWithinRectangle(int x, int y, int width, int height) = 0;

    virtual ~Shape() = default;

    virtual void readFromConsole() = 0;
};


#endif //SVG_CLI_EDITOR_SHAPE_H
