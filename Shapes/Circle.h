#ifndef SVG_CLI_EDITOR_CIRCLE_H
#define SVG_CLI_EDITOR_CIRCLE_H
#include "Shape.h"

///A derivative of Shape base class implementing all its pure virtual methods
///Consists of 4 properties - cx, cy, r and fill
///<circle> svg element
class Circle: public Shape {
private:
    int cx;
    int cy;
    int r;
    String fill;
public:
    ///Default constructor
    Circle();

    ///Constructor with params
    Circle(int cx, int cy, int r, const char * fill);

    ///Read circle element by given SvgElement instance reference
    void read(SvgElement & element) override;

    ///Write circle element to an output stream
    void write(std::ostream & out) override;

    ///Print an element to an output stream
    void print(std::ostream & out) override;

    ///Polymorphic method that sets the cx property of the circle svg element ( translate action needed )
    void setX(int horizontal) override;

    ///Polymorphic method that sets the cy property of the circle svg element ( translate action needed )
    void setY(int vertical) override;

    ///A boolean checker that checks whether this instance of a circle is within another one ( within action needed )
    bool isWithinCircle(int cx, int cy, int r) override;

    ///A boolean checker that checks whether this instance of a circle is within a rectangle ( within action needed )
    bool isWithinRectangle(int x, int y, int width, int height) override;

    ///A method that reads a circle from the console ( expects input for all properties )
    void readFromConsole() override;

    ///A static String array that lists all base supported properties a circle must have
    static String props[];

    ///A copy method for the heterogeneous container
    virtual Circle * copy() override {
        return new Circle(*this);
    };

    ///A virtual destructor
   virtual ~Circle() = default;
};

String Circle::props[] = {"cx","cy","r","fill"};


#endif //SVG_CLI_EDITOR_CIRCLE_H
