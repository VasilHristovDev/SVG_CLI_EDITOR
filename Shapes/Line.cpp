#include "Line.h"


void Line::print(std::ostream &out) {
    out<<"Line: ";
    out<<"x1: "<<this->x1<<" ";
    out<<"y1: "<<this->y1<<" ";
    out<<"x2: "<<this->x2<<" ";
    out<<"y2: "<<this->y2<<" ";
    out<<"stroke: "<<this->stroke<<std::endl;
}

Line::Line() {
    this->x1 = 0;
    this->y1 = 0;
    this->x2 = 0;
    this->y2 = 0;
    this->stroke = "white";
}

Line::Line(int x1, int y1, int x2, int y2, const char *stroke) {
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->stroke = stroke;
}

void Line::write(std::ostream &out) {
    out<<"<line ";
    out<<"x1=\""<<this->x1<<"\" ";
    out<<"y1=\""<<this->y1<<"\" ";
    out<<"x2=\""<<this->x2<<"\" ";
    out<<"y2=\""<<this->y2<<"\" ";
    out<<"stroke=\""<<this->stroke<<"\" ";
    out<<"/>";
    out<<std::endl;
}

void Line::read(SvgElement & element) {
    Attribute * attributes = element.getAttributes();
    int count = element.getAttrCount();
    for (int i = 0; i < count ; ++i) {
        if(attributes[i].key.contains("x1"))
            this->x1 = (int)attrValueToInt(attributes[i].value);
        else if(attributes[i].key.contains("y1"))
            this->y1 = (int)attrValueToInt(attributes[i].value);
        else if(attributes[i].key.contains("x2"))
            this->x2 = (int)attrValueToInt(attributes[i].value);
        else if(attributes[i].key.contains("y2"))
            this->y2 = (int)attrValueToInt(attributes[i].value);
        else if(attributes[i].key.contains("stroke"))
            this->stroke = attributes[i].value;
    }
}