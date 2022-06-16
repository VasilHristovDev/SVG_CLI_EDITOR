#ifndef SVG_CLI_EDITOR_LINE_H
#define SVG_CLI_EDITOR_LINE_H
#include "Shape.h"

class Line: public Shape {
private:
    int x1;
    int y1;
    int x2;
    int y2;
    String stroke;
public:
    Line();
    Line(int x1, int y1, int x2, int y2, const char * stroke);

    void read(SvgElement & element) override;
    void write(std::ostream & out) override;
    void print(std::ostream & out) override;
    void setX(int horizontal) override;
    void setY(int vertical) override;
    bool isWithinCircle(int cx, int cy, int r) override;
    bool isWithinRectangle(int x, int y, int width, int height) override;
    void readFromConsole() override;

    static String props[];
    virtual Line * copy() override {
        return new Line(*this);
    }
     ~Line() override = default;
};

String Line::props[] = {"x1", "y1", "x2", "y2", "stroke"};

#endif //SVG_CLI_EDITOR_LINE_H
