# SVG_CLI_EDITOR
Second project for FMI's Object Oriented Programming Course 2022

A console app where you can read SVG files.

## Console App Features:
1. Open an SVG file and store all its figures inside a container - **open "<path_to_file>**
2. Close an SVG file - **close**
3. Save an SVG file into its origin filename - **save**
4. Save an SVG file into a new file - **save as <path_to_new_file>**
5. Help command which lists all currently available commands - **help**

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

