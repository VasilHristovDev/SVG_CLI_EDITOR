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

//TODO:Finish logic
void SvgElement::read(const char *line) {
    int currChar = 0;
    while(line[currChar] != '<')
        currChar++;
    int occChar = 0;
    int occAttr = 0;
    char * tempChar = new char [10];
    while(line[currChar++] != ' ')
    {
        tempChar[occChar++] = line[currChar];
    }
    this->name = tempChar;
    delete [] tempChar;
    occChar = 0;
    while(line[currChar] != '/')
    {
        tempChar = new char [10];
        while(line[currChar] != '=')
        {
            tempChar[occChar++] = line[currChar++];
        }
        currChar+=2;
        std::cout<<tempChar<<std::endl;
        this->attributes[occAttr].key = tempChar;
        occChar = 0;
        delete [] tempChar;
        tempChar = new char [10];
        while(line[currChar] != '"')
        {
            tempChar[occChar++] = line[currChar++];
        }
        currChar++;
        std::cout<<tempChar<<std::endl;
        this->attributes[occAttr].value = tempChar;
        delete [] tempChar;
    }
    for (int i = 0; i < occAttr; ++i) {
        std::cout<<this->attributes[i].key<<" : "<<this->attributes[i].value<<std::endl;
    }

}