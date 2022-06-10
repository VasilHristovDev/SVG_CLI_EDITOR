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
    virtual Line * copy() {
        return new Line(*this);
    }
};


#endif //SVG_CLI_EDITOR_LINE_H