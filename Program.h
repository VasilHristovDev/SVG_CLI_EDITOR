#ifndef SVG_CLI_EDITOR_PROGRAM_H
#define SVG_CLI_EDITOR_PROGRAM_H
#include "CLI/CLI_Handler.cpp"

///The UI class
class Program {
public:
    ///a method that runs the CLI_Handler
    void run();
};

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


#endif //SVG_CLI_EDITOR_PROGRAM_H
