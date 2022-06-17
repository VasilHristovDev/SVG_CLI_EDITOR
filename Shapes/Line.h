#ifndef SVG_CLI_EDITOR_LINE_H
#define SVG_CLI_EDITOR_LINE_H
#include "Shape.h"

///A derivative of Shape base class implementing all its pure virtual methods
///Consists of 5 properties - x1, y1, x2, y2 and stroke
///<line> svg element
class Line: public Shape {
private:
    int x1;
    int y1;
    int x2;
    int y2;
    String stroke;
public:
    ///Default constructor
    Line();
    
    ///A constructor with params
    Line(int x1, int y1, int x2, int y2, const char * stroke);

    ///Read line element by given SvgElement instance reference
    void read(SvgElement & element) override;

    ///Write line element to an output stream
    void write(std::ostream & out) override;

    ///Print an element to an output stream
    void print(std::ostream & out) override;

    ///Polymorphic method that sets the cx property of the line svg element ( translate action needed )
    void setX(int horizontal) override;

    ///Polymorphic method that sets the cy property of the line svg element ( translate action needed )
    void setY(int vertical) override;

    ///A boolean checker that checks whether this instance of a line is within a circle ( within action needed )
    bool isWithinCircle(int cx, int cy, int r) override;

    ///A boolean checker that checks whether this instance of a line is within a rectangle ( within action needed )
    bool isWithinRectangle(int x, int y, int width, int height) override;

    ///A method that reads a line from the console ( expects input for all properties )
    void readFromConsole() override;

    ///A static String array that lists all base supported properties a line must have
    static String props[];

    ///A copy method for the heterogeneous container
    virtual Line * copy() override {
        return new Line(*this);
    }
    ///a destructor
     ~Line() override = default;
};

String Line::props[] = {"x1", "y1", "x2", "y2", "stroke"};

#endif //SVG_CLI_EDITOR_LINE_H
