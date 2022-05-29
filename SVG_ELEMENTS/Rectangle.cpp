#include "Rectangle.h"

Rectangle::Rectangle(int width, int height, int x, int y, const char *fill) {
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    this->fill = fill;
}

Rectangle::Rectangle() {
    this->x = 0;
    this->y = 0;
    this->width = 0;
    this->height = 0;
    this->fill = "white";
}

void Rectangle::write(std::ostream &out) {
    out<<"<rect ";
    out<<"x=\""<<this->x<<"\" ";
    out<<"y=\""<<this->y<<"\" ";
    out<<"width=\""<<this->width<<"\" ";
    out<<"height=\""<<this->height<<"\" ";
    out<<"fill=\""<<this->fill<<"\" ";
    out<<"/>";
    out<<std::endl;
}

void Rectangle::print(std::ostream &out) {
    out<<"Rectangle: ";
    out<<"width: "<<this->width<<" ";
    out<<"height: "<<this->height<<" ";
    out<<"x: "<<this->x<<" ";
    out<<"y: "<<this->y<<" ";
    out<<"fill: "<<this->fill<<std::endl;
}
//TODO: Implement read method