#ifndef SVG_CLI_EDITOR_FILE_H
#define SVG_CLI_EDITOR_FILE_H

#include "../misc/String.h"
#include <fstream>

///File class handling whether a file exists, if it has correct extension and if it correctly formatted
///Consisting only by one protected property - filename
class File {
protected:
    String fileName;
public:
    ///Default constructor setting the filename
    File()
    {
        this->fileName = "<file_name>";
    }

    ///A constructor with a single param
    explicit File(const char * fileName);

    ///a static function checking whether a file exists in the filesystem
    static bool exists(const char * file);

    ///getter for the filename
    String getFileName();

    ///check if a file is correctly formatted
    virtual bool isCorrectFormat() {
        return true;
    };

    ///setter for the filename
    void setFileName(const char * fileName);

    ///checker if the given file has correct extension
    virtual bool hasCorrectExtension() {
        return true;
    }
};


#endif //SVG_CLI_EDITOR_FILE_H
