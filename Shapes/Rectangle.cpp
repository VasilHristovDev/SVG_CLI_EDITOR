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

void Rectangle::read(SvgElement & element) {
    Attribute * attributes = element.getAttributes();
    int count = element.getAttrCount();
    for (int i = 0; i < count ; ++i) {
        if(attributes[i].key == "x")
            this->x = (int) attrValueToDouble(attributes[i].value);
        else if(attributes[i].key == "y")
            this->y = (int) attrValueToDouble(attributes[i].value);
        else if(attributes[i].key.contains("width"))
            this->width = (int) attrValueToDouble(attributes[i].value);
        else if(attributes[i].key.contains("height"))
            this->height = (int) attrValueToDouble(attributes[i].value);
        else if(attributes[i].key.contains("fill"))
            this->fill = attributes[i].value;
    }
}

void Rectangle::readFromConsole() {
    std::cout<<"Enter x:";
    std::cin>>x;

    std::cout<<"Enter y:";
    std::cin>>y;

    std::cout<<"Enter width:";
    std::cin>>width;

    std::cout<<"Enter height:";
    std::cin>>height;

    std::cin.ignore();
    std::cout<<"Enter fill:";
    std::cin>>fill;
}

void Rectangle::setX(int horizontal) {
    this->x = this->x + horizontal;
}

void Rectangle::setY(int vertical) {
    this->y = this->y + vertical;
}

bool Rectangle::isWithinCircle(int cx, int cy, int r) {
    //define all four points
    Point point1(this->x, this->y);
    Point point2(this->x + this->width, this->y);
    Point point3(this->x, this->y + this->height);
    Point point4(this->x + this->width, this->y + this->height);
    Point points[] = {point1, point2, point3, point4};

    //check if they are all inside the circle
    for (int i = 0; i < 4 ; ++i) {
        if((cx - points[i].x) * (cx - points[i].x) + (cy - points[i].y) * (cy - points[i].y) > r * r)
            return false;
    }
    return true;
}

bool Rectangle::isWithinRectangle(int _x, int _y, int _width, int _height) {
    Point A(this->x, this->y);
    Point B(this->x + this->width, this->y);
    Point C(this->x, this->y + height);
    Point D(this->x + this->width, this->y + this->height);

    Point A1(_x, _y);
    Point B1(_x + _width, _y);
    Point C1(_x, _y + _height);

    Point pointArr[] = {A,B,C,D};

    for (int i = 0; i < 4 ; ++i) {
        if(!(pointArr[i].x > A1.x && pointArr[i].x < B1.x && pointArr[i].y > A1.y && pointArr[i].y < C1.y))
            return false;
    }
    return true;
}
