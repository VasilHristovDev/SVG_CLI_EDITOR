#ifndef SVG_CLI_EDITOR_CLI_HANDLER_H
#define SVG_CLI_EDITOR_CLI_HANDLER_H

#include <iostream>
//#include <windows.h>
#include <unistd.h>

#include "CliHelperMessages.h"
#include "../Files/File.cpp"
#include "../Files/SvgFile.cpp"
#include "../Shapes/SvgContainer.cpp"

enum COMMANDS {
    OPEN, CLOSE, SAVE, SAVE_AS, HELP, EXIT, RENDER, UNKNOWN_COMMAND
};
enum SVG_COMMANDS {
    PRINT, CREATE, ERASE, TRANSLATE, WITHIN
};

class CLI_Handler {
private:
    SvgContainer container;
    COMMANDS command;
    String path;
    SvgFile currentOpenFile;
    bool isFileOpen = false;
public:
    CLI_Handler();

    CLI_Handler(COMMANDS command,  const char * path = "/");

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
    void handlePrint();
    void handleErase();
    void handleTranslate();
    void handleWithin();

    void setCommand(COMMANDS commands);

    void setPath(String &string);
};

void CLI_Handler::action() {
    switch (this->command) {
        case OPEN:
            this->handleOpen();
            break;
        case SAVE:
            this->handleSave();
            break;
        case SAVE_AS:
            this->handleSaveAs();
            break;
        case CLOSE:
           this->handleClose();
            break;
        case HELP:
            this->handleHelp();
            break;
        case RENDER:
            this->handleRender();
            break;
        case EXIT:
            this->handleExit();
            return;
        case UNKNOWN_COMMAND:
        default:
            std::cout<<CliHelperMessages::UNKNOWN_COMMAND_USED<<std::endl;
            break;
    }

}

CLI_Handler::CLI_Handler() {
    this->command = HELP;
    this->path = "";
    this->isFileOpen = false;
}

CLI_Handler::CLI_Handler(COMMANDS command, const char * path):container(),currentOpenFile() {
    this->command = command;
    this->path = path;
    this->isFileOpen = false;
}

void CLI_Handler::setCommand(COMMANDS _command) {
    this->command = _command;
}

void CLI_Handler::setPath(String &string) {
    this->path = string;
}

void CLI_Handler::handleOpen() {
    if(this->path == "")
    {
        std::cerr<<CliHelperMessages::NO_PATH_PROVIDED<<std::endl;
        return;
    }
    if(File::exists(this->path.getText()))
    {
        this->currentOpenFile.setFileName(this->path.getText());
        if(this->currentOpenFile.isCorrectFormat())
        {
            this->isFileOpen = true;
            this->container.readSvgElementsFromFile(this->currentOpenFile);
        }
        else
        {
            std::cout<<"Ne bachkam :("<<std::endl;
        }

    }
    else {
        std::cout<<CliHelperMessages::FILE_PATH_DOES_NOT_EXIST<<std::endl;
    }
}
void CLI_Handler::handleRender() {
    if(this->path == "")
    {
        std::cerr<<CliHelperMessages::NO_PATH_PROVIDED<<std::endl;
        return;
    }
    if(File::exists(this->path.getText()))
    {
        SvgFile file(this->path.getText());
        if(file.isCorrectFormat())
        {
//            ShellExecute(NULL, "open", this->path.getText(), NULL, NULL, SW_SHOWNORMAL);
            return;
        }
        std::cerr<<CliHelperMessages::FILE_NOT_IN_CORRECT_FORMAT<<std::endl;
    }
    else
    {
        std::cerr<<CliHelperMessages::FILE_PATH_DOES_NOT_EXIST<<std::endl;
    }
}

void CLI_Handler::handleClose() {
    if(this->isFileOpen)
    {
        this->isFileOpen = false;
    }
    else{
        std::cout<<CliHelperMessages::NO_FILE_OPEN<<std::endl;
    }
}

void CLI_Handler::handleSave() {
    if(this->isFileOpen)
    {
        std::ofstream out;
        out.open(this->currentOpenFile.getFileName().getText());

        if(out)
        {
            this->container.write(out);
            out.close();
            std::cout<<CliHelperMessages::SAVE_CHANGES_TO_FILE<<this->currentOpenFile.getFileName()<<std::endl;
        }
    }
    else{
        std::cout<<CliHelperMessages::NO_FILE_OPEN<<std::endl;
    }
}
void CLI_Handler::handleSaveAs() {
    if(this->isFileOpen) {
        if(this->path == "")
        {
            std::cerr<<CliHelperMessages::NO_PATH_PROVIDED<<std::endl;
            return;
        }
        if(!File::exists(this->path.getText()))
        {
            std::ofstream out;
            out.open(this->path.getText());
            if (out) {
                this->container.write(out);
                out.close();
                std::cout<<CliHelperMessages::SAVE_CHANGES_TO_FILE<<this->path<<std::endl;
            }
            else
            {
                std::cout<<CliHelperMessages::FILE_OPEN_ERROR_MESSAGE<<std::endl;
            }
            this->isFileOpen = false;
        }

    }
    else{
        std::cout<<CliHelperMessages::NO_FILE_OPEN<<std::endl;
    }
}

void CLI_Handler::handleHelp() {
    std::cout << CliHelperMessages::CLI_COMMANDS << std::endl;
}

String stripCommand(String & command)
{
    if(command.contains(CliHelperMessages::OPEN))
    {
        return command.strip(CliHelperMessages::OPEN);
    }
    else if(command.contains(CliHelperMessages::SAVE_AS))
    {
        return command.strip(CliHelperMessages::SAVE_AS);
    }
    else if(command.contains(CliHelperMessages::RENDER))
    {
        return command.strip(CliHelperMessages::RENDER);
    }
    return command.getText();
}

void CLI_Handler::handleExit() {
    if(this->isFileOpen)
    {
        std::cout<<CliHelperMessages::UNSAVED_CHANGES<<std::endl;
        String input;
        std::cin>>input;
        if(input.contains(CliHelperMessages::CLOSE))
        {
            this->handleClose();
            return;
        }
        if(input.contains(CliHelperMessages::SAVE) && !input.contains(CliHelperMessages::SAVE_AS))
        {
            this->handleSave();
            return;
        }
        if(input.contains(CliHelperMessages::SAVE_AS))
        {
            String newPath = stripCommand(input).getText();
            setPath(newPath);
            this->handleSaveAs();
            return;
        }
    }
}

COMMANDS stringToCommand(String &string) {
    if (string.contains(CliHelperMessages::OPEN))
        return OPEN;
    if (string.contains(CliHelperMessages::CLOSE))
        return CLOSE;
    if (string.contains(CliHelperMessages::RENDER))
        return RENDER;
    if (string.contains(CliHelperMessages::SAVE_AS))
        return SAVE_AS;
    if (string.contains(CliHelperMessages::SAVE) && !string.contains(CliHelperMessages::SAVE_AS))
        return SAVE;
    if (string.contains(CliHelperMessages::EXIT))
        return EXIT;
    if (string.contains(CliHelperMessages::HELP))
        return HELP;

    return UNKNOWN_COMMAND;
}



#endif //SVG_CLI_EDITOR_CLI_HANDLER_H
