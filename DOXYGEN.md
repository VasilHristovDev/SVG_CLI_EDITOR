# SVG_CLI_EDITOR
## Second project for FMI's Object-Oriented Programming Course 2022

A console app where you can read, edit and create SVG files.

## Console App Features: ##
+ Open an SVG file and store all its figures inside a container - **open "<path_to_file>"** 
+ Close an SVG file - **close**
+ Save an SVG file into its origin filename - **save**
+ Save an SVG file into a new file - **save as <path_to_new_file>**
+ Help command which lists all currently available commands - **help**
+ Render a svg file to your default browser - **render <path_to_file>**
> **Render** is only supported for Windows OS !

All commands are used in the **CLI** application

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


## Currently supported figures ##
Here is a list of all currently supported figures
1. **Rectangle** - consisting of **x, y, width, height and fill**
2. **Circle** - consisting of **cx, cy, r and fill**
3. **Line** - consisting of **x1, y1, x2, y2 and stroke**


## Add a new figure to the project
Here is a tutorial step by step.
Let's say that you want to add **ellipse** figure to the supported figures.
1. Create a class called **Ellipse** in the "/shapes" directory
2. You must implement all virtual methods from the base class
   +  Shape * copy();
   +  void read(SvgElement & element);
   +  void print(std::ostream & out);
   +  void write(std::ostream & out);
   +  void setX(int horizontal);
   +  void setY(int vertical);
   +  bool isWithinCircle(int cx, int cy, int r);
   +  bool isWithinRectangle(int x, int y, int width, int height);
   +  ~Shape();
   +  void readFromConsole();
3. After that in Ellipse.cpp add a **static String props[]** array as a public property and list all   allowed attributes an `<ellipse>` must have (cx, cy, rx, ry, fill)
4. Add this to the **SvgFile::markupTagCorrectSvgElement()** method:

     if(line.contains("ellipse"))
     {
        for (int i = 0; i < 5 ; ++i) {
           if(!line.contains(Ellipse::props[i] + "="))\
              return false;
        }
     return true;
   }

5. Then in **SvgContainer::readFromConsole()** add the corresponding logic for the new figure
6. And last add corresponding logic in **SvgContainer::readSvgElementsFromFile(SvgFile &file)** for the new figure


## Bugs found:
Done some testing while working on the project and found these bugs:
1. When a file is currently open, don't edit it in the IDE (.svg files)
2. Sometimes the changes you make to a file manually are not in the memory (cache)
3. When providing arguments for an action you must surround them with two symbols (in order to work correctly)