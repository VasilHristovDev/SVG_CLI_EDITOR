# SVG_CLI_EDITOR
## Second project for FMI's Object-Oriented Programming Course 2022

A console app where you can read, edit and create SVG files.

## Console App Features:
1. Open an SVG file and store all its figures inside a container - **open "<path_to_file>**
2. Close an SVG file - **close**
3. Save an SVG file into its origin filename - **save**
4. Save an SVG file into a new file - **save as <path_to_new_file>**
5. Help command which lists all currently available commands - **help**
6. Render a svg file to your default browser - **render <path_to_file>**
   >**Render** is only supported for Windows OS !

## SVG app features
After you successfully open a correct format SVG file you are able to execute the following commands:

1. Print all figures inside the svg container - **print**
2. Create a new figure by given input - **create**
    > You will be asked what kind of figure you are willing to add to the container. Then you will have to give input for all its properties.
3. Erase a figure by given index - **erase <given_index>**
4. Translate a figure by given index(optional) by given units vertically and horizontally - **translate [<given_index>]**
    > you will be asked for **horizontal units** input and **vertical units** input after you execute the command.
5. List all figures within a given area which can be either a circle or rectangle - **within <chosen_figure>**
    > You will be asked for either **circle properties** input or **rectangle properties** input after you execute the command.


## Currently supported figures
Here is a list of all currently supported figures
1. **Rectangle** - consisting of **x, y, width, height and fill**
2. **Circle** - consisting of **cx, cy, r and fill**
3. **Line** - consisting of **x1, y1, x2, y2 and stroke**

## Add a new figure to the project
Here is a tutorial step by step.
Let's say that you want to add **ellipse** figure to the supported figures.
1. Create a class called **Ellipse** in the "/shapes" directory
2. You must implement all virtual methods from the base class
**
  + virtual Shape * copy();
  + virtual void read(SvgElement & element);
  + virtual void print(std::ostream & out);
  + virtual void write(std::ostream & out);
  + virtual void setX(int horizontal);
  + virtual void setY(int vertical);
  + virtual bool isWithinCircle(int cx, int cy, int r);
  + virtual bool isWithinRectangle(int x, int y, int width, int height);
  + virtual ~Shape();
  + virtual void readFromConsole();
**
4. After that in Ellipse.cpp add a **static String props[]** array as a public property and list all   allowed attributes an **`<ellipse>`** must have (cx, cy, rx, ry, fill) 
5. Add this to the **SvgFile::markupTagCorrectSvgElement(String &line)** method:  
   if(line.contains("ellipse"))\
   {\
      for (int i = 0; i < 5 ; ++i) {\
        if(!line.contains(Ellipse::props[i] + "="))\
           return false;\
      }\
    return true;\
   }
6. Then in **SvgContainer::readFromConsole()** add the corresponding logic for the new figure
7. And last add corresponding logic in **SvgContainer::readSvgElementsFromFile(SvgFile &file)** for the new figure

## Bugs found:
Done some testing while working on the project and found these bugs:
1. When a file is currently open, don't edit it in the IDE (.svg files)
2. Sometimes the changes you make to a file manually are not in the memory (cache)
3. When providing arguments for an action you must surround them with two symbols (in order to work correctly)