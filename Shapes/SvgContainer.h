#ifndef SVG_CLI_EDITOR_SVGCONTAINER_H
#define SVG_CLI_EDITOR_SVGCONTAINER_H
#include "Shape.h"
#include "Rectangle.cpp"
#include "Circle.cpp"
#include "Line.cpp"
#include "../Files/SvgFile.h"
#include "../misc/SvgElement.cpp"

const int DEFAULT_CAP = 10;


class SvgContainer {
private:
    Shape ** shapes;
    int size;
    int cap;
    void clean();
public:
    SvgContainer();
    SvgContainer(int cap);
    SvgContainer(const SvgContainer & other);

    //Add a shape to the container
    void add(Shape * shape);
    ///a method that extracts the index of an element inside the container
    unsigned int getIndex(Shape &shape);

    ///a method that removes an element standing on a given index inside the container
    void remove(unsigned int index);

    ///a method that returns the current size of the container
    unsigned int getSize() const;

    ///read all svg elements from a file and add them to the container
    void readSvgElementsFromFile(SvgFile & file);

    ///an indexation operator that returns the element standing on the index inside of the container
    Shape *operator[](unsigned index);

    ///an assignment operator (good practise when using dynamic allocated memory)
    SvgContainer &operator=(const SvgContainer &other);

    ///a destructor handling all dynamic memory data ( deleting all allocated properties of the class)
    ~SvgContainer();
};


#endif //SVG_CLI_EDITOR_SVGCONTAINER_H
