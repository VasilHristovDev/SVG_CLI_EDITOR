#ifndef SVG_CLI_EDITOR_CLI_HANDLER_H
#define SVG_CLI_EDITOR_CLI_HANDLER_H

#include <iostream>
#include <windows.h>

#include "CliHelperMessages.h"
#include "../Files/File.cpp"
#include "../Files/SvgFile.cpp"

enum COMMANDS {
    OPEN, CLOSE, SAVE, SAVE_AS, HELP, EXIT, RENDER, UNKNOWN_COMMAND
};

class CLI_Handler {
private:
    COMMANDS command;
    String path;
    bool isFileOpen = false;
public:
    CLI_Handler();

    CLI_Handler(COMMANDS command,  const char * path = "/");

    void action();

    void setCommand(COMMANDS commands);

    void setPath(String &string);
};

void CLI_Handler::action() {
    switch (this->command) {
        case OPEN:
            if(this->path == "")
            {
                std::cerr<<"No path provided!"<<std::endl;
                return;
            }
            if(File::exists(this->path.getText()))
            {
                SvgFile svgFile(this->path.getText());
                if(svgFile.isCorrectFormat())
                {
                    this->isFileOpen = true;
                    std::cout<<"BACHKAM"<<std::endl;
//                    SvgContainer container = readFromFile(svgFile);
                }
                else
                {
                    std::cout<<"Ne bachkam :("<<std::endl;
                }

            }
            else {
                std::cout<<"The specified path does not exist or it is not a file!"<<std::endl;
            }
            break;
        case SAVE:
            if(this->isFileOpen)
            {

            }
            else{
                std::cout<<"No file is currently open!"<<std::endl;
            }
            break;
        case SAVE_AS:
            if(this->isFileOpen)
            {

            }
            else{
                std::cout<<"No file is currently open!"<<std::endl;
            }
            break;
        case CLOSE:
            if(this->isFileOpen)
            {

                this->isFileOpen = false;
            }
            else{
                std::cout<<"No file is currently open!"<<std::endl;
            }
            break;
        case HELP:
            std::cout << CliHelperMessages::CLI_COMMANDS << std::endl;
            break;
        case EXIT:
            std::cout<<"Goodbye :("<<std::endl;
            return;
        case RENDER:
            if(this->path == "")
            {
                std::cerr<<"No path provided!"<<std::endl;
                return;
            }
            if(File::exists(this->path.getText()))
            {
                SvgFile file(this->path.getText());
                if(file.isCorrectFormat())
                {
                    ShellExecute(NULL, "open", this->path.getText(), NULL, NULL, SW_SHOWNORMAL);
                    return;
                }
                std::cerr<<CliHelperMessages::FILE_NOT_IN_CORRECT_FORMAT<<std::endl;
            }
            else
            {
                std::cerr<<CliHelperMessages::FILE_PATH_DOES_NOT_EXIST<<std::endl;
            }

            break;
        default:
            break;
    }

}

CLI_Handler::CLI_Handler() {
    this->command = HELP;
    this->path = "";
    this->isFileOpen = false;
}

CLI_Handler::CLI_Handler(COMMANDS command, const char * path) {
    this->command = command;
    this->path = path;
    this->isFileOpen = false;
}

void CLI_Handler::setCommand(COMMANDS command) {
    this->command = command;
}

void CLI_Handler::setPath(String &string) {
    this->path = string;
}

COMMANDS stringToCommand(String &string) {
    if (string.contains(CliHelperMessages::OPEN))
        return OPEN;
    if (string.contains(CliHelperMessages::CLOSE))
        return CLOSE;
    if (string.contains(CliHelperMessages::RENDER))
        return RENDER;
    if (string.contains(CliHelperMessages::SAVE))
        return SAVE;
    if (string.contains(CliHelperMessages::SAVE_AS))
        return SAVE_AS;
    if (string.contains(CliHelperMessages::EXIT))
        return EXIT;
    if (string.contains(CliHelperMessages::HELP))
        return HELP;

    return UNKNOWN_COMMAND;
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


#endif //SVG_CLI_EDITOR_CLI_HANDLER_H
