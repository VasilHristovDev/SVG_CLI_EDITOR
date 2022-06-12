#include "SvgElement.h"

SvgElement::SvgElement() {
    this->attributes = new Attribute[5];
    this->name = "empty";
}

SvgElement::SvgElement(const char *name, Attribute * attributes, int attrCount) {
    this->name = name;
    this->attributes = new Attribute [attrCount];
    this->attrCount = attrCount;
    for (int i = 0; i < this->attrCount; ++i) {
        this->attributes[i].key = attributes[i].key;
        this->attributes[i].value = attributes[i].value;
    }
}


void SvgElement::read(const char *line) {
    int currChar = 0;
    while(line[currChar] != '<')
        ++currChar;
    currChar++;
    int occChar = 0;
    int occAttr = 0;
    char * tempChar = new char [100];
    while(line[currChar] != ' ')
    {
        tempChar[occChar++] = line[currChar++];
    }
    tempChar[occChar] = '\0';
    this->name = tempChar;
    delete [] tempChar;
    occChar = 0;
    currChar++;
    while(line[currChar] != '/')
    {
        tempChar = new char [20];
        while(line[currChar] != '=')
        {
            tempChar[occChar++] = line[currChar++];
        }
        tempChar[occChar] = '\0';
        currChar+=2;
        this->attributes[occAttr].key = tempChar;
        occChar = 0;
        delete [] tempChar;
        tempChar = new char [20];
        while(line[currChar] != '"')
        {
            tempChar[occChar++] = line[currChar++];
        }
        tempChar[occChar] = '\0';
        currChar+=2;
        this->attributes[occAttr++].value = tempChar;
        delete [] tempChar;
        occChar = 0;
    }
    this->attrCount = occAttr;

}

String &SvgElement::getName()  {
    return this->name;
}

Attribute *SvgElement::getAttributes() {
    return this->attributes;
}

int SvgElement::getAttrCount() const {
    return this->attrCount;
}

SvgElement::~SvgElement() {
    delete [] this->attributes;
}
