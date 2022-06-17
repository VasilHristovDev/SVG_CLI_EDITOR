#ifndef SVG_CLI_EDITOR_POINT_H
#define SVG_CLI_EDITOR_POINT_H
#include "cmath"

///Geometric helper structure - used in methods inside Rectangle, Line and Circle derivatives of Shape class
///Implements a point within the 2D, consisting of a position of the point in the plain (x,y)
struct Point
{
    int x;
    int y;

    Point():x(0),y(0){};
    Point(int x, int y):x(x),y(y){};
};

///Returns the distance between two 2D points
double distance(Point a, Point b)
{
    return sqrt(pow(abs(a.x - b.x),2) - pow(abs(a.y - b.y),2));
}
#endif //SVG_CLI_EDITOR_POINT_H
