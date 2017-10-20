#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>

#include "parameter.h"

/**
* destination ist der zielordner
* name der name des projekts
* useCpp ob C++ oder C verwendet wird
* und standard ist der C/C++ standard der verwendet werden soll
*/
std::string getCMake(const char *name, bool useCpp, const char *compiler, const char *standard) {
    std::string cmake = "";

    std::cout << "Compiler:" << compiler << '\n';
    if(strcmp(compiler, "") != 0) {
        cmake += "set(CMAKE_";
        cmake += (useCpp ? "CXX" : "C");
        cmake += "_COMPILER \"";
        cmake += compiler;
        cmake += "\")\n";
    }

    std::cout << "Standard: " << standard << '\n';
    if(strcmp(standard, "") != 0) {
        cmake += "set(CMAKE_";
        cmake += (useCpp ? "CXX" : "C");
        cmake += "_STANDARD ";
        cmake += standard;
        cmake += ")\n";
    }

    cmake += "cmake_minimum_required(VERSION 3.0)\n\n";
    cmake += "project(";
    cmake += name;
    cmake += ")\n\n";

    cmake += "find_package(OpenCV REQUIRED)\n";
    cmake += "include_directories(${OpenCV_INCLUDE_DIRS})\n\n";

    cmake += "add_executable(";
    cmake += name;
    cmake += " main.";
    if(useCpp) {
        cmake += "cpp";
    } else {
        cmake += "c";
    }
    cmake += ")\n";

    cmake += "target_link_libraries(";
    cmake += name;
    cmake += " ${OpenCV_LIBS})";

    return cmake;
}

bool ends_with(std::string const & value, std::string const & ending) {
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

std::string getMain() {
    std::string text = "#include <opencv/cv.h>\n\n";
    text += "int main(int argc, const char *argv[]) {\n";
    text += "return 0;\n}";
    return text;
}

int main(int argc, const char *argv[]) {
    if(argc < 5) {
        std::cerr << "Usage: " << argv[0]
        << " -c|-cpp [STANDARD]"
        << "[-cmp COMPILERNAME]"
        << " -d DESTINATION "
        << "-n NAME" << '\n';
    }

    std::string cmake = getCMake(getName(argc, argv),
                            getUseCpp(argc, argv),
                            getCompiler(argc, argv),
                            getStandard(argc, argv));

    std::string path = getDestination(argc, argv);
    if(!ends_with(path, "/")) {
        path += "/";
    }

    std::string cmd = "mkdir " + path;

    std::system(cmd.data());

    std::ofstream file(path + "CMakeLists.txt");
    if(file.is_open()) {
        file << cmake;
        file.close();
    } else {
        std::cerr << "Couldn't write to  " << path << "CMakeLists.txt" << '\n';
        return -1;
    }

    file = std::ofstream(path + "main.cpp");
    if(file.is_open()) {
        file << getMain();
        file.close();
    } else {
        std::cerr << "Couldn't write to  " << path << "main.cpp" << '\n';
        return -2;
    }

    return 0;
}
