#ifndef SVG_CLI_EDITOR_HELPER_MESSAGES_H
#define SVG_CLI_EDITOR_HELPER_MESSAGES_H
#include "../misc/String.cpp"

class CliHelperMessages {
public:
    //opening file helper messages
    static const String FILE_OPENED_MESSAGE;
    static const String FILE_OPEN_ERROR_MESSAGE;
    static const String FILE_PATH_DOES_NOT_EXIST;
    static const String FILE_NOT_IN_CORRECT_FORMAT;

    //close file helper messages
    static const String SAVE_CHANGES_TO_FILE;
    static const String UNSAVED_CHANGES;

    //cli commands
    static const char * OPEN;
    static const char * CLOSE;
    static const char * SAVE;
    static const char * SAVE_AS;
    static const char * HELP;
    static const char * RENDER;
    static const char * EXIT;

    //cli commands
    static const char * CLI_COMMANDS;

};
const String CliHelperMessages::FILE_OPENED_MESSAGE = "Successfully opened file ";
const String CliHelperMessages::FILE_OPEN_ERROR_MESSAGE = "Could not open file ";
const String CliHelperMessages::FILE_NOT_IN_CORRECT_FORMAT = "The given file is not the correct format! ";
const String CliHelperMessages::FILE_PATH_DOES_NOT_EXIST = "The given file doesn't exist! ";
const char * CliHelperMessages::OPEN = "open";
const char * CliHelperMessages::CLOSE = "close";
const char * CliHelperMessages::SAVE = "save";
const char * CliHelperMessages::SAVE_AS = "save as";
const char * CliHelperMessages::EXIT = "exit";
const char * CliHelperMessages::HELP = "help";
const char * CliHelperMessages::RENDER = "render";
const char * CliHelperMessages::CLI_COMMANDS = "\nList of available commands for the CLI:\n"
                                               "open \"<path_to_file>\"         opens a file and checks if it is correct\n"
                                               "close                         closes a file\n"
                                               "save                          saves the currently opened file\n"
                                               "save as \"<path_to_file>\"      saves the currently opened file to the specified path\n"
                                               "render \"<path_to_svg_file>\"   renders the specified svg file to the browser\n"
                                               "help                          shows a list of operable commands\n"
                                               "exit                          exits the application\n";
#endif //SVG_CLI_EDITOR_HELPER_MESSAGES_H
