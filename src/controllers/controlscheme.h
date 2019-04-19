//
// Created by Mark David on 19/04/2019.
//

#ifndef TETRISVS_SRC_CONTROLLERS_CONTROLSCHEME_H_
#define TETRISVS_SRC_CONTROLLERS_CONTROLSCHEME_H_

#include <fstream>
#include <string>

class ControlScheme {
public:
    ControlScheme(int scheme)
    {
        std::ifstream schemefile;
        std::string scheme_path = "data/schemes/";
        scheme_path += char(scheme+48);
        schemefile.open(scheme_path);
        schemefile >> LEFT >> RIGHT >> DOWN >> DROP >> ROTATECW >> ROTATECCW >> HOLD;
        schemefile.close();
    }
    char LEFT;
    char RIGHT;
    char DOWN;
    char DROP;
    char ROTATECW;
    char ROTATECCW;
    char HOLD;
};

#endif //TETRISVS_SRC_CONTROLLERS_CONTROLSCHEME_H_
