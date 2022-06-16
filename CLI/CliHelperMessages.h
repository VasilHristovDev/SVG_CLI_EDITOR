#ifndef SVG_CLI_EDITOR_HELPER_MESSAGES_H
#define SVG_CLI_EDITOR_HELPER_MESSAGES_H
#include "../misc/String.cpp"

class CliHelperMessages {
public:
    //opening file helper messages
    static const char * FILE_OPENED_MESSAGE;
    static const char * FILE_OPEN_ERROR_MESSAGE;
    static const char * FILE_PATH_DOES_NOT_EXIST;
    static const char * FILE_NOT_IN_CORRECT_FORMAT;

    //close file helper messages
    static const char * SAVE_CHANGES_TO_FILE;
    static const char * UNSAVED_CHANGES;

    //cli commands
    static const char * OPEN;
    static const char * CLOSE;
    static const char * SAVE;
    static const char * SAVE_AS;
    static const char * HELP;
    static const char * RENDER;
    static const char * EXIT;
    static const char * PRINT;
    static const char * ERASE;
    static const char * CREATE;
    static const char * TRANSLATE;
    static const char * WITHIN;
    static const char * UNKNOWN_COMMAND_USED;

    //cli commands
    static const char * CLI_COMMANDS;

    //svg commands
    static const char * SVG_COMMANDS;

    //
    static const char * NO_FILE_OPEN;
    static const char * NO_PATH_PROVIDED;

    //svg commands helper messages
    static const char * UNAVAILABLE_COMMAND;
    static const char * ERASED_SUCCESSFULLY;
    static const char * NO_ELEMENT_WITH_INDEX_WAS_FOUND;
    static const char * UNSUPPORTED_SVG_ELEMENT;
    static const char * SUCCESSFULLY_TRANSLATED_ELEMENT;
    static const char * SUCCESSFULLY_TRANSLATED_ALL;

};
const char * CliHelperMessages::FILE_OPENED_MESSAGE = "Successfully opened file ";
const char * CliHelperMessages::FILE_OPEN_ERROR_MESSAGE = "Could not open file ";
const char * CliHelperMessages::FILE_NOT_IN_CORRECT_FORMAT = "The given file is not the correct format! ";
const char * CliHelperMessages::FILE_PATH_DOES_NOT_EXIST = "The specified path does not exist or it is not a file!";

const char * CliHelperMessages::OPEN = "open";
const char * CliHelperMessages::CLOSE = "close";
const char * CliHelperMessages::SAVE = "save";
const char * CliHelperMessages::SAVE_AS = "save as";
const char * CliHelperMessages::EXIT = "exit";
const char * CliHelperMessages::HELP = "help";
const char * CliHelperMessages::RENDER = "render";
const char * CliHelperMessages::PRINT = "print";
const char * CliHelperMessages::ERASE = "erase";
const char * CliHelperMessages::CREATE = "create";
const char * CliHelperMessages::TRANSLATE = "translate";
const char * CliHelperMessages::WITHIN = "within";

const char * CliHelperMessages::CLI_COMMANDS = "\nList of available commands for the CLI:\n"
                                               "open \"<path_to_file>\"         opens a file and checks if it is correct\n"
                                               "close                         closes a file\n"
                                               "save                          saves the currently opened file\n"
                                               "save as \"<path_to_file>\"      saves the currently opened file to the specified path\n"
                                               "render \"<path_to_svg_file>\"   renders the specified svg file to the browser. Works only under windows OS\n"
                                               "help                          shows a list of operable commands\n"
                                               "exit                          exits the application\n";

const char * CliHelperMessages::UNKNOWN_COMMAND_USED = "Unknown command was used!\nPlease write help to see a list of all supported commands!";

const char * CliHelperMessages::SVG_COMMANDS = "\nList of available commands for the SVG files\n"
                                               "(only available after you successfully open an svg file with the 'open' command)\n"
                                               "print                               prints all currently available figures\n"
                                               "create                              creates a new figure by a given input\n"
                                               "erase <n>                           erases a figure from the container with index 'n'\n"
                                               "translate [<n>]                     translates figure with index n or all figures by <x_pixels> horizontally\n"
                                               "                                    and with <y_pixels> vertically.\n"
                                               "within <option>                     lists all figures within a given area.\n"
                                               "                                    <option> may be a circle or a rectangle\n\n"
                                               "For rectangle you must provide starting coordinates <x> <y> <width> <height>\n"
                                               "For circle you must provide <cx> <cy> <r>\n";

const char * CliHelperMessages::UNSAVED_CHANGES = "You have an open file with unsaved changes, please select close or save first.\n"
                                                  "You can use close, save or save as <directory>!";

const char * CliHelperMessages::SAVE_CHANGES_TO_FILE = "Successfully saved changes to file: ";
const char * CliHelperMessages::NO_FILE_OPEN = "No file is currently open!";
const char * CliHelperMessages::NO_PATH_PROVIDED = "No path was provided!";
const char * CliHelperMessages::UNAVAILABLE_COMMAND = "This command is only available when a file is currently open!";
const char * CliHelperMessages::NO_ELEMENT_WITH_INDEX_WAS_FOUND = "No element with the given index was found!";
const char * CliHelperMessages::ERASED_SUCCESSFULLY = "Successfully removed element at index ";
const char * CliHelperMessages::UNSUPPORTED_SVG_ELEMENT = "The element you entered is currently not supported by this program!";
const char * CliHelperMessages::SUCCESSFULLY_TRANSLATED_ELEMENT = "Successfully translated element (";
const char * CliHelperMessages::SUCCESSFULLY_TRANSLATED_ALL = "Successfully translated all elements!";
#endif //SVG_CLI_EDITOR_HELPER_MESSAGES_H
