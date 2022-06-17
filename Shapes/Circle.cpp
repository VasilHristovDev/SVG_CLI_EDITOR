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

void Circle::read(SvgElement & element) {
    Attribute * attributes = element.getAttributes();
    int count = element.getAttrCount();
    for (int i = 0; i < count ; ++i) {
        if(attributes[i].key.contains("cx"))
            this->cx = attrValueToDouble(attributes[i].value);
        else if(attributes[i].key.contains("cy"))
            this->cy = attrValueToDouble(attributes[i].value);
        else if(attributes[i].key.contains("r"))
            this->r = attrValueToDouble(attributes[i].value);
        else if(attributes[i].key.contains("fill"))
            this->fill = attributes[i].value;
    }
}

void Circle::print(std::ostream &out) {
    out<<"Circle: ";
    out<<"cx: "<<this->cx<<" ";
    out<<"cy: "<<this->cy<<" ";
    out<<"r: "<<this->r<<" ";
    out<<"fill: "<<this->fill<<std::endl;
}

void Circle::write(std::ostream &out) {
    out<<"<circle ";
    out<<"cx=\""<<this->cx<<"\" ";
    out<<"cy=\""<<this->cy<<"\" ";
    out<<"r=\""<<this->r<<"\" ";
    out<<"fill=\""<<this->fill<<"\" ";
    out<<"/>";
    out<<std::endl;
}

void Circle::readFromConsole() {
    std::cout<<"Enter cx:";
    std::cin>>cx;

    std::cout<<"Enter cy:";
    std::cin>>cy;

    std::cout<<"Enter r:";
    std::cin>>r;

    std::cin.ignore();
    std::cout<<"Enter fill:";
    std::cin>>fill;
}

void Circle::setX(int horizontal) {
    this->cx = this->cx + horizontal;
}

void Circle::setY(int vertical) {
    this->cy = this->cy + vertical;
}

bool Circle::isWithinCircle(int _cx, int _cy, int _r) {
    Point bigCenter(_cx, _cy);
    Point smallCenter(this->cx, this->cy);

    if(distance(smallCenter, bigCenter) + this->r < _r)
        return true;
    return false;
}

bool Circle::isWithinRectangle(int x, int y, int width, int height) {
    Point A(x,y);
    Point B(x + width,y);
    Point C(x,y + height);

    Point center(this->cx, this->cy);
    Point testTop(this->cx, this->cy - r);
    Point testBottom(this->cx, this->cy + r);
    Point testLeft(this->cx - r, this->cy);
    Point testRight(this->cx + r, this->cy);

    Point testable [] = {center,testTop, testBottom, testLeft, testRight};

    for (int i = 0; i < 5 ; ++i) {
        if(!(testable[i].x > A.x && testable[i].x < B.x && testable[i].y > A.y && testable[i].y < C.y))
            return false;
    }
    return true;
}
