#ifndef SVG_CLI_EDITOR_POINT_H
#define SVG_CLI_EDITOR_POINT_H
#include "cmath"
struct Point
{
    int x;
    int y;

    Point():x(0),y(0){};
    Point(int x, int y):x(x),y(y){};
};
double distance(Point a, Point b)
{
    return sqrt(pow(abs(a.x - b.x),2) - pow(abs(a.y - b.y),2));
}
#endif //SVG_CLI_EDITOR_POINT_H
