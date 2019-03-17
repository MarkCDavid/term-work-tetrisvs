//
// Created by Mark David on 13/03/2019.
//

#ifndef TERMINALGAMEENGINE_CMDTERMINAL_H
#define TERMINALGAMEENGINE_CMDTERMINAL_H

#include "color.h"
#include "abstractterminal.h"
#include "windows.h"

class CMDTerminal : public AbstractTerminal {

private:
    short width;
    short height;
    SMALL_RECT const min_window = {0, 0, 1, 1};
    SMALL_RECT window_rect;
    HANDLE consoleHandle;
    CHAR_INFO *window_buffer;
public:
    CMDTerminal();

    void UpdateTitle(float delta_time) override;

    void Draw() override;

    void GetResolution(short &width, short &height) override;

    bool SetWindow(short width, short height, int pixel_size) override;

    bool PutAt(int x, int y, char symbol, FG_COLOR fg, BG_COLOR bg) override;

    bool PutStringAt(int x, int y, const char *message, FG_COLOR fg, BG_COLOR bg) override;

    bool PutLine(int fx, int fy, int tx, int ty, char symbol, FG_COLOR fg, BG_COLOR bg) override;

    bool PutLines(std::vector<std::pair<int, int>> points, char symbol, FG_COLOR fg, BG_COLOR bg) override;

    int GetWidth() const override;

    int GetHeight() const override;

    ~CMDTerminal() override;
};


#endif //TERMINALGAMEENGINE_CMDTERMINAL_H
