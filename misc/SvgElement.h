#ifndef SVG_CLI_EDITOR_SVGELEMENT_H
#define SVG_CLI_EDITOR_SVGELEMENT_H
#include "Attribute.h"
#include "String.h"
class SvgElement {
private:
    String name;
    Attribute * attributes;
    int attrCount;
public:
    SvgElement();
    SvgElement(const char * name, Attribute * attributes, int attrCount);

    void read(const char * line);
    String & getName();
    Attribute * getAttributes();
    int getAttrCount() const;
    ~SvgElement();
};


#endif //SVG_CLI_EDITOR_SVGELEMENT_H
