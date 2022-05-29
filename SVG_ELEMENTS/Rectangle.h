#ifndef SVG_CLI_EDITOR_RECTANGLE_H
#define SVG_CLI_EDITOR_RECTANGLE_H
#include "Shape.h"

class Rectangle: public Shape {
public:
    void read(const char * read) override;
};


#endif //SVG_CLI_EDITOR_RECTANGLE_H
