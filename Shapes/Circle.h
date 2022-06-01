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

    void read(std::istream & in) override;
    void write(std::ostream & out) override;
    void print(std::ostream & out) override;

    virtual Circle * copy() {
        return new Circle(*this);
    };
};


#endif //SVG_CLI_EDITOR_CIRCLE_H
