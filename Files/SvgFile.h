#ifndef SVG_CLI_EDITOR_SVGFILE_H
#define SVG_CLI_EDITOR_SVGFILE_H

#include "File.h"
#include "../Shapes/Rectangle.h"
#include "../Shapes/Circle.h"
#include "../Shapes/Line.h"

///A derivative of File class handling especially svg files
class SvgFile: public File {
public:
    ///Default constructor calling File default constructor
    SvgFile():File(){};

    ///Single param constructor constructing only fileName property
    explicit SvgFile(const char * fileName): File(fileName){};

    ///Applied polymorphic method that checks if a svg file is correctly formatted
    bool isCorrectFormat() override;

    ///Checker for a single markupTag (whether is correctly formatted)
    bool markupTagCorrect(String& line) const;

    ///Checker for a single svg markup tag (if the figure is in the list of supported figures etc.)
    bool markupTagCorrectSvgElement(String & line) const;

    ///Checks whether the open file has .svg extension
    bool hasCorrectExtension() override;
};


#endif //SVG_CLI_EDITOR_SVGFILE_H
