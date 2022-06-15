#include "SvgContainer.h"

unsigned int SvgContainer::getSize() const {
    return this->size;
}

SvgContainer::~SvgContainer() {
    clean();
}

Shape *SvgContainer::operator[](unsigned int index) {
    return this->shapes[index];
}

void SvgContainer::remove(unsigned int index) {
    if (index <= size) {
        for (int i = 0; i < size; ++i) {
            if (i == index) {
                for (int j = i; j < size; ++j) {
                    this->shapes[j] = this->shapes[j + 1];
                }
            }
        }
        //decrement size
        size--;
        std::cout<<CliHelperMessages::ERASED_SUCCESSFULLY<<index<<std::endl;
        return;
    }
    std::cout << CliHelperMessages::NO_ELEMENT_WITH_INDEX_WAS_FOUND << std::endl;
}

unsigned int SvgContainer::getIndex(Shape &shape) {
//    std::cout<<size<<std::endl;
//    for (int i = 0; i < this->size ; ++i) {
//        if(*this->shapes[i] == shape)
//            return i;
//    }
//    //TODO: Return error index const || Throw exception
    return -1;
}

SvgContainer &SvgContainer::operator=(const SvgContainer &other) {
    if (this != &other) {
        for (int i = 0; i < this->cap; ++i) {
            delete[] this->shapes[i];
        }
        delete[] this->shapes;

        this->shapes = new Shape *[other.cap];
        for (int i = 0; i < other.size; ++i) {
            this->shapes[i] = other.shapes[i]->copy();
        }
        this->cap = other.cap;
        this->size = other.size;
    }
    return *this;
}

SvgContainer::SvgContainer(int cap) {
    this->cap = cap;
    this->shapes = new Shape *[this->cap];
    this->size = 0;
}

SvgContainer::SvgContainer() {
    this->cap = DEFAULT_CAP;
    this->shapes = new Shape *[this->cap];
    this->size = 0;
}

void SvgContainer::add(Shape *shape) {
    this->shapes[size++] = shape->copy();
}

void SvgContainer::clean() {
    for (int i = 0; i < this->size; ++i) {
        delete this->shapes[i];
    }
    delete[] this->shapes;
}

SvgContainer::SvgContainer(const SvgContainer &other) {
    for (int i = 0; i < this->size; ++i) {
        delete[] this->shapes[i];
    }
    delete[] this->shapes;

    this->cap = other.cap;
    this->shapes = new Shape *[this->cap];
    for (int i = 0; i < other.size; ++i) {
        this->add(other.shapes[i]);
    }

}

void SvgContainer::readSvgElementsFromFile(SvgFile &file) {
    std::fstream reader(file.getFileName().getText(), std::ios::in);
    class Rectangle tempRect;
    class Circle tempCircle;
    class Line tempLine;
    if (reader) {
        String line;
        while (!line.contains("<svg")) {
            reader >> line;
        }
        while (!line.contains("</svg") && !reader.eof()) {
            reader >> line;
            if (reader.eof())
                break;
            reader.seekg(((int) reader.tellg() - line.getSize()), std::ios::beg);
            SvgElement element;
            element.read(line.getText());
            if (element.getName().contains("rect")) {
                tempRect.read(element);
                this->add(&tempRect);
                reader >> line;
            } else if (element.getName().contains("circle")) {
                tempCircle.read(element);
                this->add(&tempCircle);
                reader >> line;
            } else if (element.getName().contains("line")) {
                tempLine.read(element);
                this->add(&tempLine);
                reader >> line;
            }
        }
        std::cout << "Successfully read svg elements from file: " << file.getFileName() << std::endl;
        reader.close();
    }


}

void SvgContainer::print() const {
    for (int i = 0; i < this->size; ++i) {
        std::cout << i + 1 << ". ";
        this->shapes[i]->print(std::cout);
    }
}

void SvgContainer::write(std::ofstream &out) const {
    out << "<svg xmlns=";
    out << "\"http://www.w3.org/2000/svg\"";
    out << ">" << std::endl;
    for (int i = 0; i < size; ++i) {
        out << "     ";
        this->shapes[i]->write(out);
    }
    out << "</svg>";
}

void SvgContainer::readFromConsole() {
    std::cout<<"Enter shape:"<<std::endl;
    String shapeType;
    std::cin>>shapeType;
    Shape * shape;
    if(shapeType=="rectangle" || shapeType == "Rectangle")
    {
        shape = new Rectangle;
        shape->readFromConsole();
        this->add(shape);
        std::cout<<"Added: ";
        shape->print(std::cout);
        return;
    }

    if(shapeType == "circle" || shapeType == "Circle")
    {
        shape = new Circle;
        shape->readFromConsole();
        this->add(shape);
        std::cout<<"Added: ";
        shape->print(std::cout);
        return;
    }

    if(shapeType == "line" || shapeType == "Line")
    {
        shape = new Line;
        shape->readFromConsole();
        this->add(shape);
        std::cout<<"Added: ";
        shape->print(std::cout);
        return;
    }
    std::cout<<CliHelperMessages::UNSUPPORTED_SVG_ELEMENT<<std::endl;
}

void SvgContainer::translate(int vertical, int horizontal, int index) {
    if(index != -1)
    {
        this->shapes[index]->setX(horizontal);
        this->shapes[index]->setY(vertical);
        std::cout<<CliHelperMessages::SUCCESSFULLY_TRANSLATED_ELEMENT<<index<<")"<<std::endl;
        return;
    }

    for (int i = 0; i < this->size ; ++i) {
        this->shapes[i]->setX(horizontal);
        this->shapes[i]->setY(vertical);
    }
    std::cout<<CliHelperMessages::SUCCESSFULLY_TRANSLATED_ALL<<std::endl;

}
void SvgContainer::within(String & figure)
{
    std::cout<<figure<<std::endl;
    if(figure == "circle")
    {
        int cx, cy, r;
        std::cout<<"cx:";
        std::cin>>cx;
        std::cout<<"cy:";
        std::cin>>cy;
        std::cout<<"r:";
        std::cin>>r;
        SvgContainer tempContainer;
        for (int i = 0; i < this->size ; ++i) {
            if(this->shapes[i]->isWithinCircle(cx,cy,r))
                tempContainer.add(this->shapes[i]);
        }
        if(tempContainer.getSize() > 0)
        {
            tempContainer.print();
        }
        else {
            std::cout<<"No figures within circle "<<cx<<" "<<cy<<" "<<r<<std::endl;
        }
    }
    else if(figure == "rectangle")
    {
        int x,y,width,height;
        std::cout<<"x:";
        std::cin>>x;
        std::cout<<"y:";
        std::cin>>y;
        std::cout<<"width:";
        std::cin>>width;
        std::cout<<"height:";
        std::cin>>height;

        SvgContainer tempContainer;

        for (int i = 0; i < size ; ++i) {
            if(this->shapes[i]->isWithinRectangle(x,y,width,height))
                tempContainer.add(this->shapes[i]);
        }
        if(tempContainer.getSize() > 0)
        {
            tempContainer.print();
        }
        else {
            std::cout<<"No figures within rectangle "<<x<<" "<<y<<" "<<width<<" "<<height<<std::endl;
        }
    }
    std::cin.ignore();
}
