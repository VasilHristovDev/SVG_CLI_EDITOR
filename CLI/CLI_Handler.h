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

public:
    CLI_Handler();

    CLI_Handler(COMMANDS command,  const char * path = "/");

    void action();

};

void CLI_Handler::action() {
    switch (this->command) {
        case OPEN:
            if(File::exists(this->path.getText()))
            {
                SvgFile svgFile(this->path.getText());
                if(svgFile.isCorrectFormat())
                {
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
            //TODO: Implement save
            break;
        case SAVE_AS:
            //TODO: Implement save as
            break;
        case CLOSE:
            //TODO: Implement closing file
            break;
        case HELP:
            //TODO: Write all commands string
            std::cout << CliHelperMessages::FILE_OPENED_MESSAGE << std::endl;
            break;
        case EXIT:
            //TODO: Implement exit
            std::cout<<"exit"<<std::endl;
            break;
        case RENDER:
            ShellExecute(NULL, "open", this->path.getText(), NULL, NULL, SW_SHOWNORMAL);
            break;
        default:
            break;
    }

}

CLI_Handler::CLI_Handler() {
    this->command = HELP;
}

CLI_Handler::CLI_Handler(COMMANDS command, const char * path) {
    this->command = command;
    this->path = path;
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
