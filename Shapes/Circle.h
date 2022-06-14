#ifndef SVG_CLI_EDITOR_CIRCLE_H
#define SVG_CLI_EDITOR_CIRCLE_H
#include "Shape.h"

class Circle: public Shape {
private:
    int cx;
    int cy;
    int r;
    String fill;
public:
    Circle();
    Circle(int cx, int cy, int r, const char * fill);

    void read(SvgElement & element) override;
    void write(std::ostream & out) override;
    void print(std::ostream & out) override;
    void setX(int horizontal) override;
    void setY(int vertical) override;
    bool isWithinCircle(int cx, int cy, int r) override;
    bool isWithinRectangle(int x, int y, int width, int height) override;

    void readFromConsole() override;

    virtual Circle * copy() override {
        return new Circle(*this);
    };
   virtual ~Circle() = default;
};


#endif //SVG_CLI_EDITOR_CIRCLE_H
