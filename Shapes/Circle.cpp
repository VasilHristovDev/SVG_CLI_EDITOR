#include "Circle.h"

Circle::Circle() {
    this->cx = 0;
    this->cy = 0;
    this->r = 0;
    this->fill = "white";
}

Circle::Circle(int cx, int cy, int r, const char *fill) {
    this->cx = cx;
    this->cy = cy;
    this->r = r;
    this->fill = fill;
}

void Circle::read(std::istream &in) {
    in.ignore(16);
    in>>cx;
    in.ignore(6);
    in>>cy;
    in.ignore(5);
    in>>r;
    in.ignore(8);
    in>>fill;
}

void Circle::print(std::ostream &out) {
    out<<"Circle: ";
    out<<"cx: "<<this->cx<<" ";
    out<<"cy: "<<this->cy<<" ";
    out<<"r: "<<this->r<<" ";
    out<<"fill: "<<this->fill<<std::endl;
}

void Circle::write(std::ostream &out) {
    out<<"    ";
    out<<"<circle ";
    out<<"cx=\""<<this->cx<<"\" ";
    out<<"cy=\""<<this->cy<<"\" ";
    out<<"r=\""<<this->r<<"\" ";
    out<<"fill=\""<<this->fill<<"\" ";
    out<<"/>";
    out<<std::endl;
}