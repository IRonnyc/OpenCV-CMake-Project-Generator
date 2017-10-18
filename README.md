# OpenCV-CMake-Project-Generator
Generates CMakeList.txt and main.cpp for OpenCV projects

Use:
ocvCMake -c|-cpp [C/C++ Standard (Optional)] -cmp [Compilername] -d [Target directory] -n [Projectname]

-c|-cpp and -cmp are optional parameters
If not specified the application will generate cpp projects.

it will ALWAYS generate a main.cpp, if you created a C project, change main.cpp to main.c!!!
