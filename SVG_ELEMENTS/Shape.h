#ifndef SVG_CLI_EDITOR_SHAPE_H
#define SVG_CLI_EDITOR_SHAPE_H
#include <fstream>

class Shape {
protected:
    virtual void read(const char * line) = 0;
    virtual void write(std::ostream & out) = 0;
    virtual void print(std::ostream & out) = 0;
};


#endif //SVG_CLI_EDITOR_SHAPE_H
