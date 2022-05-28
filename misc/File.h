#ifndef SVG_CLI_EDITOR_FILE_H
#define SVG_CLI_EDITOR_FILE_H

#include "String.h"
#include <fstream>

class File {
private:
    String fileName;
public:
    File(const char * fileName);
    static bool exists(const char * file);
    virtual bool isCorrectFormat() {
        return true;
    };
};


#endif //SVG_CLI_EDITOR_FILE_H
