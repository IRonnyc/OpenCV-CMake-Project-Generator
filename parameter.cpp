#include <cstring>

#include "parameter.h"

bool getUseCpp(int argc, const char *argv[]) {
    for(int i = 0; i < argc - 1; i++) {
        if(const char *arg = argv[i]; strcmp(arg, "-c") == 0) {
            return false;
        } else if (strcmp(arg, "-cpp") == 0) {
            return true;
        }
    }
    return true;
}

const char *getCompiler(int argc, const char *argv[]) {
    for(int i = 0; i < argc - 1; i++) {
        if(const char *arg = argv[i]; strcmp(arg, "-cmp") == 0) {
            if(argv[i+1][0] != '-') {
                return argv[i+1];
            } else {
                return "";
            }
        }
    }
    return "";
}

const char *getStandard(int argc, const char *argv[]) {
    for(int i = 0; i < argc - 1; i++) {
        if(const char *arg = argv[i]; strcmp(arg, "-c") == 0 || strcmp(arg, "-cpp") == 0) {
            if(argv[i+2][0] != '-') {
                return argv[i+1];
            }
        }
    }
    return "";
}

const char *getDestination(int argc, const char *argv[]) {
    for(int i = 0; i < argc - 1; i++) {
        if(strcmp(argv[i], "-d") == 0) {
            return argv[i + 1];
        }
    }
    return "";
}

const char *getName(int argc, const char *argv[]) {
    for(int i = 0; i < argc - 1; i++) {
        if(strcmp(argv[i], "-n") == 0) {
            return argv[i + 1];
        }
    }
    return "";
}
