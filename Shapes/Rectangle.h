#ifndef SVG_CLI_EDITOR_RECTANGLE_H
#define SVG_CLI_EDITOR_RECTANGLE_H
#include "Shape.h"
#include "../misc/String.h"

class Rectangle: public Shape {
private:
    int width;
    int height;
    int x;
    int y;
    String fill;
public:
    Rectangle();
    Rectangle(int width, int height, int x, int y, const char * fill);
    void read(SvgElement & element) override;
    void write(std::ostream & out) override;
    void print(std::ostream & out) override;

    virtual Rectangle * copy() override{
        return new Rectangle(*this);
    };
    virtual ~Rectangle() = default;
};


#endif //SVG_CLI_EDITOR_RECTANGLE_H
