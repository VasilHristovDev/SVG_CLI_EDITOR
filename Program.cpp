#include "Program.h"

void Program::run() {
    String command;
    std::cin>>command;
    String path = stripCommand(command).getText();
    CLI_Handler console(stringToCommand(command), path.getText());
    console.action();



}
