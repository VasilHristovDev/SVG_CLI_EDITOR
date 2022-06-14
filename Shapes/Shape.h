#ifndef SVG_CLI_EDITOR_SHAPE_H
#define SVG_CLI_EDITOR_SHAPE_H
#include <fstream>
#include "../misc/SvgElement.h"

class Shape {
protected:
    virtual void read(SvgElement & element) = 0;
public:
    virtual Shape * copy() = 0;
    virtual void print(std::ostream & out) = 0;
    virtual void write(std::ostream & out) = 0;
    virtual void setX(int horizontal) = 0;
    virtual void setY(int vertical) = 0;
    virtual ~Shape() = default;

    virtual void readFromConsole() = 0;
};


#endif //SVG_CLI_EDITOR_SHAPE_H
