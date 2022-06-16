#ifndef SVG_CLI_EDITOR_SVGFILE_H
#define SVG_CLI_EDITOR_SVGFILE_H

#include "File.h"
#include "../Shapes/Rectangle.h"
#include "../Shapes/Circle.h"
#include "../Shapes/Line.h"

String SUPPORTED_FIGURES[] = {
        "rect",
        "circle",
        "line"
};
const int NUMBER_SUPPORTED_FIGURES = 3;
class SvgFile: public File {
public:
    SvgFile():File(){};
    explicit SvgFile(const char * fileName): File(fileName){};
    bool isCorrectFormat() override;
    bool markupTagCorrect(String& line) const;
    bool markupTagCorrectSvgElement(String & line) const;
    bool hasCorrectExtension() override;

    bool checkAttributes(String &string, String & string1) const;
};


#endif //SVG_CLI_EDITOR_SVGFILE_H
