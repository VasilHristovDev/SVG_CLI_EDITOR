#ifndef SVG_CLI_EDITOR_FILE_H
#define SVG_CLI_EDITOR_FILE_H

#include "../misc/String.h"
#include <fstream>

class File {
protected:
    String fileName;
public:
    File(const char * fileName);
    static bool exists(const char * file);
    virtual bool isCorrectFormat() const{
        return true;
    };
    virtual bool hasCorrectExtension() const {
        return true;
    }
};


#endif //SVG_CLI_EDITOR_FILE_H
