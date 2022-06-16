#ifndef SVG_CLI_EDITOR_CLI_HANDLER_H
#define SVG_CLI_EDITOR_CLI_HANDLER_H

#include <iostream>

#ifdef _WIN32
#define WINDOWS
#elifdef __linux__
#define UNIX
#elifdef __APPLE__
#define APPLE
#endif

#include "CliHelperMessages.h"
#include "../Files/File.cpp"
#include "../Files/SvgFile.cpp"
#include "../Shapes/SvgContainer.cpp"

enum COMMANDS {
    OPEN, CLOSE, SAVE, SAVE_AS, HELP, EXIT, RENDER, UNKNOWN_COMMAND,
    PRINT, CREATE, ERASE, TRANSLATE, WITHIN
};

class CLI_Handler {
private:
    SvgContainer container;
    COMMANDS command;
    String path;
    SvgFile currentOpenFile;
    bool isFileOpen = false;
    bool hasUnsavedChanges = false;
public:
    CLI_Handler();

    explicit CLI_Handler(COMMANDS command, const char *path = "/");

    //action based commands
    void action();

    void handleOpen();

    void handleClose();

    void handleSave();

    void handleSaveAs();

    void handleHelp();

    void handleRender();

    void handleExit();

    //svg file commands
    void handleCreate();

    void handlePrint();

    void handleErase();

    void handleTranslate();

    void handleWithin();

    void handleNoFileIsOpen();

    void setCommand(COMMANDS commands);

    void setPath(String &string);
};


#endif //SVG_CLI_EDITOR_CLI_HANDLER_H
