//
// Created by Mark David on 13/03/2019.
//

#ifndef TERMINALGAMEENGINE_ABSTRACTINPUT_H
#define TERMINALGAMEENGINE_ABSTRACTINPUT_H


class AbstractInput {
public:
    virtual void Update() = 0;

    virtual bool GetKey(unsigned char keycode) const = 0;

    virtual bool GetKeyDown(unsigned char keycode) const = 0;

    virtual bool GetKeyUp(unsigned char keycode) const = 0;

    virtual ~AbstractInput() = default;
};


#endif //TERMINALGAMEENGINE_ABSTRACTINPUT_H
