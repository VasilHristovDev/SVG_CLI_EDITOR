#ifndef SVG_CLI_EDITOR_HELPER_MESSAGES_H
#define SVG_CLI_EDITOR_HELPER_MESSAGES_H
#include "String.h"

class HelperMessages {
    //opening file helper messages
    static const String FILE_OPENED_MESSAGE;
    static const String FILE_OPEN_ERROR_MESSAGE;

    //
};
const String HelperMessages::FILE_OPENED_MESSAGE = "Successfully opened file ";
const String HelperMessages::FILE_OPEN_ERROR_MESSAGE = "Could not open file ";
#endif //SVG_CLI_EDITOR_HELPER_MESSAGES_H
