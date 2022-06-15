#ifndef SVG_CLI_EDITOR_FILEHELPERMESSAGES_H
#define SVG_CLI_EDITOR_FILEHELPERMESSAGES_H
#include "../misc/String.h"

//TODO: Split Messages into three files - CliHelper, SvgHelper, FileHelper
class FileHelperMessages {
public:
    //incorrect format
    static const String UNSUPPORTED_FILE_FORMAT;
    static const String INCORRECT_FILE_FORMAT_MESSAGE;
    static const String INCORRECT_SVG_MARKUP_MESSAGE;
    static const String UNSUPPORTED_SHAPE_MESSAGE;
};
const String FileHelperMessages::INCORRECT_FILE_FORMAT_MESSAGE = "The file is not in the correct format!";
const String FileHelperMessages::UNSUPPORTED_FILE_FORMAT = "Unsupported file format! The file must be of format .svg";
const String FileHelperMessages::INCORRECT_SVG_MARKUP_MESSAGE = "Found incorrect SVG markup in the file!";
const String FileHelperMessages::UNSUPPORTED_SHAPE_MESSAGE = "Unsupported type of shape!";
#endif //SVG_CLI_EDITOR_FILEHELPERMESSAGES_H
