#ifndef SVG_CLI_EDITOR_ATTRIBUTES_H
#define SVG_CLI_EDITOR_ATTRIBUTES_H
#include "String.h"
#include <cmath>

//TODO: Add an argument structure, which reads a value from a console line

const int ERROR_INDEX = -1;
struct Attribute {
    String key;
    String value;
};
double attrValueToInt(String & value)
{
    if(value == "")
        return ERROR_INDEX;

    unsigned int size = value.getSize();

    double returnable = 0;
    double powHelper = pow(10, size-1);
    for (int i = 0; i < size; ++i) {
        returnable += powHelper * (double)(value[i] - '0');
        powHelper/= 10;
    }

    return returnable;


}




#endif //SVG_CLI_EDITOR_ATTRIBUTES_H
