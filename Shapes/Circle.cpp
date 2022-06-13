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
            this->cx = attrValueToInt(attributes[i].value);
        else if(attributes[i].key.contains("cy"))
            this->cy = attrValueToInt(attributes[i].value);
        else if(attributes[i].key.contains("r"))
            this->r = attrValueToInt(attributes[i].value);
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