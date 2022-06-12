#ifndef SVG_CLI_EDITOR_SVGFILE_H
#define SVG_CLI_EDITOR_SVGFILE_H

#include "File.h"

class SvgFile: public File {
public:
    SvgFile():File(){};
    explicit SvgFile(const char * fileName): File(fileName){};
    bool isCorrectFormat() override;
    bool markupTagCorrect(String& line) const;
    bool markupTagCorrectSvgElement(String & line) const;
    bool hasCorrectExtension() override;



};


#endif //SVG_CLI_EDITOR_SVGFILE_H
