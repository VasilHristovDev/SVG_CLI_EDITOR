#include "SvgFile.h"
#include "FileHelperMessages.h"

bool SvgFile::isCorrectFormat()  {
   if(!this->hasCorrectExtension())
   {
       return false;
   }
    std::ifstream fileStream(this->fileName.getText());

    if(fileStream)
    {
        String line;
        while(!line.contains("<svg") && !fileStream.eof())
        {
            fileStream >> line;
        }
        if(!line.contains("xmlns=\"http://www.w3.org/2000/svg\"") || !this->markupTagCorrect(line))
        {
            std::cerr<<FileHelperMessages::INCORRECT_FILE_FORMAT_MESSAGE<<std::endl;
            fileStream.close();
            return false;
        }
        fileStream >> line;
        while(!fileStream.eof() && !line.contains("</svg>"))
        {
            if(!this->markupTagCorrectSvgElement(line)) {
                fileStream.close();
                return false;
            }
            fileStream >> line;
        }
        fileStream.close();
        return true;
    }
    return false;
}

bool SvgFile::markupTagCorrect(String &line) const{
    if(line.contains("<!--") && line.contains("-->"))
        return true;
    char * lineToCheck = new char [line.getSize() + 1];
    strcpy(lineToCheck, line.getText());
    int currentChar = 0;
    while(lineToCheck[currentChar] == ' ')
        currentChar++;
    bool openingTag = lineToCheck[currentChar] == '<';
    while (lineToCheck[currentChar] != '>'){
        currentChar++;
    }
    bool closingTag = lineToCheck[currentChar] == '>';
    bool nothingAfterClosingTag = true;
    while(currentChar < line.getSize() - 1 && nothingAfterClosingTag)
    {
        currentChar++;

        if(lineToCheck[currentChar] != ' ' && lineToCheck[currentChar] != '\n' && lineToCheck[currentChar] != '\r')
        {
            nothingAfterClosingTag = false;
        }
    }
    if(!(closingTag && openingTag && nothingAfterClosingTag))
    {
        std::cout<<FileHelperMessages::ERROR_IN_FILE<<std::endl;
        std::cout<<this->fileName<<std::endl;
        std::cout<<FileHelperMessages::ERROR_AT_LINE<<std::endl;
        std::cout<<lineToCheck<<std::endl;
    }
    delete [] lineToCheck;
    return closingTag && openingTag && nothingAfterClosingTag;
}

bool SvgFile::markupTagCorrectSvgElement(String &line) const {
    if(this->markupTagCorrect(line))
    {
        if(line.contains("rect"))
        {
            for (int i = 0; i <5 ; ++i) {
                if(!line.contains(Rectangle::props[i] + "="))
                    return false;
            }
            return true;
        }
        if(line.contains("circle"))
        {
            for (int i = 0; i <4 ; ++i) {
                if(!line.contains(Circle::props[i] + "="))
                    return false;
            }
            return true;
        }
        if(line.contains("line"))
        {
            for (int i = 0; i < 5 ; ++i) {
                if(!line.contains(Line::props[i] + "="))
                    return false;
            }
            return true;
        }
        std::cerr<<FileHelperMessages::UNSUPPORTED_SHAPE_MESSAGE<<std::endl;
        return false;
    }

    else
    {
        std::cerr<<FileHelperMessages::INCORRECT_SVG_MARKUP_MESSAGE<<std::endl;
        return false;
    }
}

bool SvgFile::hasCorrectExtension()  {
    if(!fileName.contains(".svg")) {
        std::cerr<<FileHelperMessages::UNSUPPORTED_FILE_FORMAT<<std::endl;
        return false;
    }
    return true;
}





