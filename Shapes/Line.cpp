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

void Line::readFromConsole() {
    std::cout<<"Enter x1:";
    std::cin>>x1;

    std::cout<<"Enter y1:";
    std::cin>>y1;

    std::cout<<"Enter x2:";
    std::cin>>x2;

    std::cout<<"Enter y2:";
    std::cin>>y2;

    std::cin.ignore();

    std::cout<<"Enter stroke:";
    std::cin>>stroke;
}

void Line::setX(int horizontal) {
    this->x1 = this->x1 + horizontal;
    this->x2 = this->x2 + horizontal;
}

void Line::setY(int vertical) {
    this->y1 = this->y1 + vertical;
    this->y2 = this->y2 + vertical;
}

bool Line::isWithinCircle(int cx, int cy, int r) {
    Point start(this->x1, this->y1);
    Point end(this->x2, this->y2);

    if((cx - start.x) * (cx - start.x) + (cy - start.y) * (cy - start.y) < r * r && (cx - end.x) * (cx - end.x) + (cy - end.y) * (cy - end.y) < r * r)
        return true;

    return false;
}

bool Line::isWithinRectangle(int x, int y, int width, int height) {
    Point startPoint(this->x1, this->y1);
    Point endPoint(this->x2, this->y2);

    Point A(x,y);
    Point B(x + width, y);
    Point C(x, y + height);
    Point D(x + width, y + height);

    return startPoint.x > A.x && startPoint.x > C.x && startPoint.y > A.y && startPoint.y < C.y
        && endPoint.x < B.x && endPoint.x < D.x && endPoint.y > B.y && endPoint.y < D.y;
}
