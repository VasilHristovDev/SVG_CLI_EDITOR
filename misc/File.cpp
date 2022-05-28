#include "File.h"

bool File::exists(const char * file) {
    std::ifstream fileStream(file);
    return fileStream.good();
}

File::File(const char *fileName) {
    this->fileName = fileName;
}

