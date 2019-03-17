//
// Created by Mark David on 13/03/2019.
//

#ifndef TERMINALGAMEENGINE_WIN32INPUT_H
#define TERMINALGAMEENGINE_WIN32INPUT_H

#include "abstractinput.h"

class Win32Input : public AbstractInput {
private:
    unsigned short old_key_states[256] = {};
    unsigned short new_key_states[256] = {};
public:

    void Update() override;

    bool GetKey(unsigned char keycode) const override;

    bool GetKeyDown(unsigned char keycode) const override;

    bool GetKeyUp(unsigned char keycode) const override;

    ~Win32Input() override;
};


#endif //TERMINALGAMEENGINE_WIN32INPUT_H
