//
// Created by Mark David on 18/03/2019.
//

#include "controls.h"
#include "windows.h"

Controls::Controls(AbstractTerminal *terminal, AbstractInput *input) : AbstractView(terminal), input(input) {

}

int Controls::Update(float delta_time) {
    if (input->GetKeyDown(VK_RETURN)) {
        return 11;
    }
    return -1;
}

void Controls::InitialDraw() {
    int menu_left = terminal->GetWidth() / 5;
    int menu_top = terminal->GetHeight() / 3;
    terminal->PutStringAt(menu_left, menu_top - 11, R"( ############################################## )",
                          FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top - 10, R"( #     LEFT PLAYER     ##    RIGHT PLAYER     # )",
                          FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top - 9, R"( #                     ##                     # )",
                          FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top - 8, R"( # LEFT: A             ## LEFT: LEFT ARROW    # )",
                          FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top - 7, R"( # RIGHT: D            ## RIGHT: RIGHT ARROW  # )",
                          FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top - 6, R"( # LOWER: S            ## LOWER: DOWN ARROW   # )",
                          FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top - 5, R"( # DROP: W             ## DROP: UP ARROW      # )",
                          FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top - 4, R"( # ROTATE LEFT: C      ## ROTATE LEFT: RALT   # )",
                          FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top - 3, R"( # ROTATE RIGHT: V     ## ROTATE RIGHT: RCTRL # )",
                          FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top - 2, R"( # HOLD: LALT          ## HOLD: RSHIFT        # )",
                          FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top - 1, R"( #                     ##                     # )",
                          FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top - 0, R"( ############################################## )",
                          FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top + 2, R"(              PRESS ENTER TO EXIT               )",
                          FG_COLOR::WHITE, BG_COLOR::BLACK);


}

void Controls::Draw() {

}
