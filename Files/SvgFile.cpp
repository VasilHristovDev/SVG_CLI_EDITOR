#include "SvgFile.h"
#include "FileHelperMessages.h"

bool SvgFile::isCorrectFormat() const {
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
    char * lineToCheck = new char [line.getSize()];
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

        if(lineToCheck[currentChar] != ' ' && lineToCheck[currentChar] != '\n')
        {
            nothingAfterClosingTag = false;
        }
    }
    if(!(closingTag && openingTag && nothingAfterClosingTag))
    {
        std::cout<<"Found error at line:"<<std::endl;
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
            return line.contains("x=") && line.contains("y=") && line.contains("width=") && line.contains("height=") && line.contains("fill=");
        }
        if(line.contains("circle"))
        {
            return line.contains("cx=") && line.contains("cy=") && line.contains("r=") && line.contains("fill=");
        }
        if(line.contains("line"))
        {
            return line.contains("x1=") && line.contains("y1=") && line.contains("x2=") && line.contains("y2=") && line.contains("stroke=");
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

bool SvgFile::hasCorrectExtension() const {
    if(!fileName.contains(".svg")) {
        std::cerr<<FileHelperMessages::UNSUPPORTED_FILE_FORMAT<<std::endl;
        return false;
    }
}





