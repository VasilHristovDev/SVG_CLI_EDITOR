#ifndef SVG_CLI_EDITOR_FILEHELPERMESSAGES_H
#define SVG_CLI_EDITOR_FILEHELPERMESSAGES_H
#include "../misc/String.h"

//TODO: Split Messages into three files - CliHelper, SvgHelper, FileHelper
class FileHelperMessages {
public:
    //incorrect format
    static const char * UNSUPPORTED_FILE_FORMAT;
    static const char * INCORRECT_FILE_FORMAT_MESSAGE;
    static const char * INCORRECT_SVG_MARKUP_MESSAGE;
    static const char * UNSUPPORTED_SHAPE_MESSAGE;

    //Error messages
    static const char * ERROR_AT_LINE;
    static const char * ERROR_IN_FILE;
};
const char * FileHelperMessages::INCORRECT_FILE_FORMAT_MESSAGE = "The file is not in the correct format!";
const char * FileHelperMessages::UNSUPPORTED_FILE_FORMAT = "Unsupported file format! The file must be of format .svg";
const char * FileHelperMessages::INCORRECT_SVG_MARKUP_MESSAGE = "Found incorrect SVG markup in the file!";
const char * FileHelperMessages::UNSUPPORTED_SHAPE_MESSAGE = "Unsupported type of shape!";

const char * FileHelperMessages::ERROR_AT_LINE = "Found an error at line:";
const char * FileHelperMessages::ERROR_IN_FILE = "Found an error in file:";
#endif //SVG_CLI_EDITOR_FILEHELPERMESSAGES_H
