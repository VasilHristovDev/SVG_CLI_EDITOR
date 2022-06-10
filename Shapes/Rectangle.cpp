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
            this->x = (int)attrValueToInt(attributes[i].value);
        else if(attributes[i].key == "y")
            this->y = (int)attrValueToInt(attributes[i].value);
        else if(attributes[i].key.contains("width"))
            this->width = (int)attrValueToInt(attributes[i].value);
        else if(attributes[i].key.contains("height"))
            this->height = (int)attrValueToInt(attributes[i].value);
        else if(attributes[i].key.contains("fill"))
            this->fill = attributes[i].value;
    }

}