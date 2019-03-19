//
// Created by Mark David on 13/03/2019.
//

#ifndef TERMINALGAMEENGINE_ABSTRACTTERMINAL_H
#define TERMINALGAMEENGINE_ABSTRACTTERMINAL_H

#include <vector>
#include "color.h"

class AbstractTerminal {
public:
    virtual void UpdateTitle(float delta_time) = 0;

    virtual void Draw() = 0;

    virtual void GetResolution(short &width, short &height) = 0;

    virtual bool SetWindow(short width, short height, int pixel_size) = 0;

    virtual bool PutAt(int x, int y, char symbol, FG_COLOR fg, BG_COLOR bg) = 0;

    virtual char GetAt(int x, int y) const = 0;

    virtual void InitEmptyBuffer() = 0;

    virtual bool PutStringAt(int x, int y, const char *message, FG_COLOR fg, BG_COLOR bg) = 0;

    virtual bool PutLine(int fx, int fy, int tx, int ty, char symbol, FG_COLOR fg, BG_COLOR bg) = 0;

    virtual bool PutLines(std::vector<std::pair<int, int>> points, char symbol, FG_COLOR fg, BG_COLOR bg) = 0;

    virtual int GetWidth() const = 0;

    virtual int GetHeight() const = 0;

    virtual ~AbstractTerminal() = default;
};


#endif //TERMINALGAMEENGINE_ABSTRACTTERMINAL_H
