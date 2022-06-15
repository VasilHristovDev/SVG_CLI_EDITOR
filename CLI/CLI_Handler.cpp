#include "CLI_Handler.h"

void CLI_Handler::action() {
    switch (this->command) {
        case OPEN:
            this->handleOpen();
            break;
        case SAVE:
            this->handleSave();
            return;
        case SAVE_AS:
            this->handleSaveAs();
            return;
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
        case PRINT:
            this->handlePrint();
            break;
        case CREATE:
            this->handleCreate();
            break;
        case ERASE:
            this->handleErase();
            break;
        case TRANSLATE:
            this->handleTranslate();
            break;
        case WITHIN:
            this->handleWithin();
            break;
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
            std::cout<<CliHelperMessages::FILE_NOT_IN_CORRECT_FORMAT<<std::endl;
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
        this->handleNoFileIsOpen();
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
        this->handleNoFileIsOpen();
        return;
    }
    this->isFileOpen = false;
    this->hasUnsavedChanges = false;
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
            this->hasUnsavedChanges = false;
            this->isFileOpen = false;
        }

    }
    else{
        this->handleNoFileIsOpen();
    }
}

void CLI_Handler::handleHelp() {
    if(this->isFileOpen)
    {
        std::cout<<CliHelperMessages::SVG_COMMANDS<<std::endl;
    }
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
    else if(command.contains(CliHelperMessages::ERASE))
    {
        return command.strip(CliHelperMessages::ERASE);
    }
    else if(command.contains(CliHelperMessages::TRANSLATE))
    {
        return command.strip(CliHelperMessages::TRANSLATE);
    }
    else if(command.contains(CliHelperMessages::WITHIN))
    {
        return command.strip(CliHelperMessages::WITHIN);
    }
    return command.getText();
}

void CLI_Handler::handleExit() {
    if(this->isFileOpen && this->hasUnsavedChanges)
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

void CLI_Handler::handlePrint() {
    if(this->isFileOpen && this->container.getSize() > 0)
    {
        this->container.print();
    }
    else {
        this->handleNoFileIsOpen();
    }
}

void CLI_Handler::handleNoFileIsOpen() {
    std::cout<<CliHelperMessages::NO_FILE_OPEN<<std::endl;
    std::cout<<CliHelperMessages::UNAVAILABLE_COMMAND<<std::endl;
}

void CLI_Handler::handleCreate() {
    if(this->isFileOpen)
    {
        this->container.readFromConsole();
    }
    else {
        this->handleNoFileIsOpen();
    }
}

void CLI_Handler::handleErase() {
    if(!(this->path == "") && this->isFileOpen)
    {
        this->container.remove((int)attrValueToInt(this->path));
        this->hasUnsavedChanges = true;
    }
    else
    {
        this->handleNoFileIsOpen();
    }
}

void CLI_Handler::handleTranslate() {
    if (this->isFileOpen)
    {
        int vertical;
        int horizontal;
        std::cout<<"Enter vertical:";
        std::cin>>vertical;
        std::cout<<"Enter horizontal:";
        std::cin>>horizontal;
        int n = (int)attrValueToInt(this->path);
        this->container.translate(vertical,horizontal, n);
    }
    else {
        this->handleNoFileIsOpen();
    }
}

void CLI_Handler::handleWithin() {
    if(this->isFileOpen)
    {
        this->container.within(this->path);
    }
    else
    {
        this->handleNoFileIsOpen();
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
    if (string.contains(CliHelperMessages::CREATE))
        return CREATE;
    if(string.contains(CliHelperMessages::PRINT))
        return PRINT;
    if(string.contains(CliHelperMessages::ERASE))
        return ERASE;
    if(string.contains(CliHelperMessages::TRANSLATE))
        return TRANSLATE;
    if(string.contains(CliHelperMessages::WITHIN))
        return WITHIN;

    return UNKNOWN_COMMAND;
}
