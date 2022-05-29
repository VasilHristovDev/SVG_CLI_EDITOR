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
    void read(const char * read);
    void write(std::ostream & out);
    void print(std::ostream & out);
};


#endif //SVG_CLI_EDITOR_RECTANGLE_H
