#ifndef SVG_CLI_EDITOR_SVGELEMENT_H
#define SVG_CLI_EDITOR_SVGELEMENT_H
#include "Attribute.h"
#include "String.h"

///Svg element class consisting of: name, an array of attributes and attributesCount
class SvgElement {
private:
    String name;
    Attribute * attributes;
    int attrCount;
public:
    ///Default constructor
    SvgElement();

    ///A constructor with params
    SvgElement(const char * name, Attribute * attributes, int attrCount);

    ///A method that reads an svgElement by given line in svgElement
    void read(const char * line);

    ///A name getter
    String & getName();

    ///Attributes getter
    Attribute * getAttributes();

    ///Attributes count getter
    int getAttrCount() const;

    ///Destructor - needed for deleting the attributes array
    ~SvgElement();
};


#endif //SVG_CLI_EDITOR_SVGELEMENT_H
