#ifndef SVG_CLI_EDITOR_STRING_H
#define SVG_CLI_EDITOR_STRING_H

#include <cstring>
#include <iostream>

///Max buffer constant that helps me when reading strings from the console
const int MAX_BUFFER = 4096;

///My own implementation of string consisting of two private properties : text and size
class String {
private:
    char *text;
    unsigned int size;
    ///Method that deletes the allocated memory for text
    void deallocateMemory();
public:
    ///Constructor with default param ( can be interpreted as both Default and Constructor with params)
    String(const char * text = "\0");
    ///Copy Constructor
    String(const String & string);

    ///Setter
    void setText(const char * text);

    ///A boolean method that checks whether a given string is contained inside a string
    bool contains(const String & other) const;

    ///Getters
    unsigned int getSize() const;
    const char *getText() const;

    ///Operator for assignment
    String &operator=(const String &other);

    ///Operator for string concatenation
    String operator+(const String &other);
    String strip(const String & other);
    ///Operator for comparison between two strings
    bool operator == (const String & other);

    ///Indexing operator returning char standing on a given index
    char operator[](int index);

    ///Operators for input and output
    friend std::istream & operator >> (std::istream & in, String & readable);
    friend std::ostream & operator << (std::ostream & out,const String & readable);

    ///Destructor
    ~String();
};



#endif //SVG_CLI_EDITOR_STRING_H
