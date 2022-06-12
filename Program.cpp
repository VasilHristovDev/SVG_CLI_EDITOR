#include "Program.h"

void Program::run() {
    String command;
    CLI_Handler console;
    while(!(command == CliHelperMessages::EXIT))
    {
        std::cout<<"Enter command:";
        std::cin>>command;
        String path = stripCommand(command).getText();
        console.setCommand(stringToCommand(command));
        console.setPath(path);
        console.action();
    }

}
