#ifndef SVG_CLI_EDITOR_CLI_HANDLER_H
#define SVG_CLI_EDITOR_CLI_HANDLER_H

#include <iostream>
#include <windows.h>

#include "CliHelperMessages.h"
#include "File.cpp"

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
                File svgFile(this->path.getText());
                //TODO: Implement Logic
                SvgAdapter adapter = new SvgAdapter();
                SvgContainer = adapter.readFromFile(svgFile);
            }
            else {
                std::cout<<"The specified path does not exist or it is not a file!"<<std::endl;
            }
            break;
        case SAVE:
            break;
        case SAVE_AS:
            break;
        case CLOSE:
            break;
        case HELP:
            std::cout << CliHelperMessages::FILE_OPENED_MESSAGE << std::endl;
            break;
        case EXIT:
            break;
        case RENDER:
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
    else if (string.getText() == CliHelperMessages::CLOSE)
        return CLOSE;
    else if (string.getText() == CliHelperMessages::RENDER)
        return RENDER;
    else if (string.getText() == CliHelperMessages::SAVE)
        return SAVE;
    else if (string.getText() == CliHelperMessages::SAVE_AS)
        return SAVE_AS;
    else if (string.getText() == CliHelperMessages::EXIT)
        return EXIT;
    else if (string.getText() == CliHelperMessages::HELP)
        return HELP;
    else
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
    return command;
}


#endif //SVG_CLI_EDITOR_CLI_HANDLER_H
