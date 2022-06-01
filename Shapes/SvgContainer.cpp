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
    }
        //If no element was found
        //TODO: Print no element found error
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
    if(this != &other)
    {
        for (int i = 0; i < this->cap ; ++i) {
            delete [] this->shapes[i];
        }
        delete [] this->shapes;

        this->shapes = new Shape * [other.cap];
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
    this->shapes = new Shape * [this->cap];
    this->size = 0;
}

SvgContainer::SvgContainer() {
    this->cap = DEFAULT_CAP;
    this->shapes = new Shape * [this->cap];
    this->size = 0;
}

void SvgContainer::add(Shape * shape) {
    this->shapes[size++] = shape->copy();
}

void SvgContainer::clean() {
    for (int i = 0; i < this->size ; ++i) {
        delete [] &this->shapes[i];
    }
    delete [] this->shapes;
}

SvgContainer::SvgContainer(const SvgContainer &other) {
    for (int i = 0; i < this->size ; ++i) {
        delete [] this->shapes[i];
    }
    delete [] this->shapes;

    this->cap = other.cap;
    this->shapes = new Shape * [this->cap];
    for (int i = 0; i < other.size ; ++i) {
        this->add(other.shapes[i]);
    }

}

void SvgContainer::readSvgElementsFromFile(SvgFile &file) {
    std::fstream reader(file.getFileName().getText(), std::ios::in);
    class Rectangle temp;
    class Circle tempCircle;
    class Line tempLine;
    if(reader)
    {
        String line;
        while(!line.contains("<svg"))
        {
            reader>>line;
        }
        while(!line.contains("</svg") || !reader.eof())
        {
            reader>>line;
            std::cout<<line<<std::endl;

            reader.seekg(((int)reader.tellg() - line.getSize()), std::ios::beg);
            SvgElement element;
            element.read(line.getText());
            return;
//            if(line.contains("rect")) {
//                temp.read(reader);
//                temp.print(std::cout);
//            }
//            if(line.contains("line"))
//            {
//                tempLine.read(reader);
//                tempLine.print(std::cout);
//            }
//            if(line.contains("circle"))
//            {
//                tempCircle.read(reader);
//                tempCircle.print(std::cout);
//            }
        }

        reader.close();
    }



}
