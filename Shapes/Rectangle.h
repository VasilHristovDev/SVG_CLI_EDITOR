#ifndef SVG_CLI_EDITOR_RECTANGLE_H
#define SVG_CLI_EDITOR_RECTANGLE_H
#include "Shape.h"
#include "../misc/Point.h"
#include "../misc/String.h"

///A derivative of Shape base class implementing all its pure virtual methods
///Consists of 5 properties - x, y, width, height and fill
///<rect> svg element
class Rectangle: public Shape {
private:
    int width;
    int height;
    int x;
    int y;
    String fill;
public:
    ///Default constructor
    Rectangle();
    
    ///A constructor with params
    Rectangle(int width, int height, int x, int y, const char * fill);

    ///Read rectangle element by given SvgElement instance reference
    void read(SvgElement & element) override;

    ///Write rectangle element to an output stream
    void write(std::ostream & out) override;

    ///Print an element to an output stream
    void print(std::ostream & out) override;

    ///Polymorphic method that sets the cx property of the rectangle svg element ( translate action needed )
    void setX(int horizontal) override;

    ///Polymorphic method that sets the cy property of the rectangle svg element ( translate action needed )
    void setY(int vertical) override;

    ///A boolean checker that checks whether this instance of a rectangle is within a circle ( within action needed )
    bool isWithinCircle(int cx, int cy, int r) override;

    ///A boolean checker that checks whether this instance of a rectangle is within a rectangle ( within action needed )
    bool isWithinRectangle(int x, int y, int width, int height) override;

    ///A method that reads a rectangle from the console ( expects input for all properties )
    void readFromConsole() override;

    ///A static String array that lists all base supported properties a rectangle must have
    static String props[];

    ///copy method needed for the heterogeneous container
    virtual Rectangle * copy() override{
        return new Rectangle(*this);
    };

    ///A destructor
    virtual ~Rectangle() = default;
};
String Rectangle::props[] = {"x","y","width","height","fill"};

#endif //SVG_CLI_EDITOR_RECTANGLE_H
