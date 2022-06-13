#ifndef SVG_CLI_EDITOR_FILE_H
#define SVG_CLI_EDITOR_FILE_H

#include "../misc/String.h"
#include <fstream>

class File {
protected:
    String fileName;
public:
    File()
    {
        this->fileName = "<file_name>";
    }
    File(const char * fileName);
    static bool exists(const char * file);

    String getFileName();
    virtual bool isCorrectFormat() {
        return true;
    };
    void setFileName(const char * fileName);
    virtual bool hasCorrectExtension() {
        return true;
    }
};


#endif //SVG_CLI_EDITOR_FILE_H
