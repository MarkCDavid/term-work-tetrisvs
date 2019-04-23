if (WIN32)
    project(pdcurses)
    cmake_minimum_required(VERSION 2.8.9)
    set(CMAKE_CXX_STANDARD 17)
    include_directories("../")
    set(LIBRARY_OUTPUT_PATH "../")
    add_library(pdcurses STATIC addch.c addchstr.c addstr.c attr.c beep.c bkgd.c border.c clear.c color.c debug.c delch.c deleteln.c getch.c getstr.c getyx.c inch.c inchstr.c initscr.c inopts.c insch.c insstr.c instr.c kernel.c keyname.c mouse.c move.c outopts.c overlay.c pad.c panel.c printw.c refresh.c scanw.c scr_dump.c scroll.c slk.c termattr.c touch.c util.c window.c)
endif (WIN32)

