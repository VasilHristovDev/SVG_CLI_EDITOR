#ifndef SVG_CLI_EDITOR_CLI_HANDLER_H
#define SVG_CLI_EDITOR_CLI_HANDLER_H

#include <iostream>

#ifdef _WIN32
#define WINDOWS
#include <windows.h>

#endif

#include "CliHelperMessages.h"
#include "../Files/File.cpp"
#include "../Files/SvgFile.cpp"
#include "../Shapes/SvgContainer.cpp"

///enum for all commands that the application handles
enum COMMANDS {
    OPEN, CLOSE, SAVE, SAVE_AS, HELP, EXIT, RENDER, UNKNOWN_COMMAND,
    PRINT, CREATE, ERASE, TRANSLATE, WITHIN
};

///Action based pseudo controller that accepts a command and handles the corresponding action
///List of properties: svgContainer, command, path(argument), the currently open file, boolean for whether a file is open,
///boolean whether there are unsaved changes
class CLI_Handler {
private:
    SvgContainer container;
    COMMANDS command;
    String path;
    SvgFile currentOpenFile;
    bool isFileOpen = false;
    bool hasUnsavedChanges = false;

    ///action for opening a file
    void handleOpen();

    ///action for closing a file
    void handleClose();

    ///action for saving the contents into the same file
    void handleSave();

    ///action for saving the contents into a new file by given path
    void handleSaveAs();

    ///action for displaying all executable commands
    void handleHelp();

    ///action for rendering a svg file to the default browser ( available only on WINDOWS OS)
    void handleRender();

    ///action for closing the program
    void handleExit();

    ///svg file commands
    ///create a new svg file by given input
    void handleCreate();

    ///prints all existing elements in the svgContainer
    void handlePrint();

    ///Erase an svgElement by given index, corresponding to its position in the svgContainer
    void handleErase();

    ///Translate an svgElement by given index(optionally) or translate all elements inside the svgContainer by given horizontal and vertical units
    void handleTranslate();

    ///Print all the elements of svgContainer inside a given figure (circle or rectangle)
    void handleWithin();

    ///Handle the situation when no file is currently open
    void handleNoFileIsOpen();
public:
    CLI_Handler();

    explicit CLI_Handler(COMMANDS command, const char *path = "/");

    ///handler for all the actions
    void action();

    ///Setter for the command
    void setCommand(COMMANDS commands);

    ///Setter for the path
    void setPath(String &string);
};


#endif //SVG_CLI_EDITOR_CLI_HANDLER_H
