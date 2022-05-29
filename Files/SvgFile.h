#ifndef SVG_CLI_EDITOR_SVGFILE_H
#define SVG_CLI_EDITOR_SVGFILE_H

#include "File.h"

class SvgFile: public File {
public:
    SvgFile(const char * fileName): File(fileName){};
    bool isCorrectFormat() const override;
    bool markupTagCorrect(String& line) const;
    bool markupTagCorrectSvgElement(String & line) const;
    bool hasCorrectExtension() const override;

};


#endif //SVG_CLI_EDITOR_SVGFILE_H
