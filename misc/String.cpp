#include "String.h"

//constructor with single param
String::String(const char *text) {
    this->size = strlen(text);
    this->text = new char [this->size + 1];
    strcpy(this->text,text);
}
//setter for the text
void String::setText(const char * _text) {
    if(this->text)
        deallocateMemory();
    this->size = strlen(_text);
    this->text = new char [this->size + 1];
    strcpy(this->text, _text);
}
//getter for the size of the string
unsigned int String::getSize() const {
    return this->size;
}
//getter for the text
const char *String::getText() const {
    return this->text;
}

//operator for assignment ( good practise when using dynamic memory )
String &String::operator=(const String &other) {
    if(this != &other)
    {
        this->setText(other.getText());
    }
    return *this;
}
//operator for string concatenation
String String::operator+(const String &other) {
    char * returnable = new char[this->size + other.getSize() + 1];
    strcpy(returnable, this->text);
    strcat(returnable,other.getText());
    return (String)returnable;
}
//method that deletes the memory of the text
void String::deallocateMemory() {
    delete [] this->text;
}
//destructor
String::~String() {
    deallocateMemory();
}
//operator for input
std::istream &operator>>(std::istream &in, String &readable) {
    //used cin.getline() with max buffer const
    char input [MAX_BUFFER];
    in.getline(input, MAX_BUFFER - 1);
    readable = (String) input;
    return in;
}
//output operator
std::ostream &operator<<(std::ostream &out, const String &readable) {
    out<<readable.getText();
    return out;
}
//copy constructor
String::String(const String &string) {
    this->text = new char[string.getSize() + 1];
    strcpy(this->text,string.getText());
}
//procedural way to check if a string is contained inside another string
bool String::contains(const String &other) const{
    unsigned int otherSize  = other.getSize();
    if(otherSize > this->size)
        return false;
    const char * otherText = other.getText();
    for (int i = 0; i < this->size; i++){
        int j = 0;
        // If the first characters match
        if(this->text[i] == otherText[j]){
            int k = i;
            while (this->text[i] == otherText[j] && j < otherSize)
            {
                j++;
                i++;
            }
            if (j == otherSize)
            {
                return true;
            }
            else
            {
                i = k;
            }
        }
    }
    return false;
}
//operator for indexation
char String::operator[](int index) {
    return this->text[index];
}
//an operator that checks whether two strings are the same
bool String::operator==(const String &other) {
    if(this->size != other.getSize())
        return false;
    int counter = 0;
    for (int i = 0; i < this->size ; ++i) {
        if(this->text[i] == other.getText()[i])
            counter++;
    }
    return counter == this->size;
}

String String::strip(const String &other) {
    if(this->size < other.size)
        return *this;

    if(this->contains(other))
    {
        int occupiedChar = 0;
        char * helperStr = new char [this->size - other.size + 3];
        String returnable;
        for (int i = other.size + 2; i < this->size -1 ; ++i) {
            helperStr[occupiedChar++] = this->text[i];
        }
        helperStr[occupiedChar] = '\0';
        returnable.setText(helperStr);
        delete [] helperStr;
        return (String) returnable;
    }
    return *this;
}
