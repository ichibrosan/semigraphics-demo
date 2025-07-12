//////////////////////////////////////////////////////////////////////////////
// /home/doug/CLionProjects/semigraphics/crtbind.cpp 2025/07/12 02:47 dwg - //
// Copyright (c) 2021-2025 Douglas Wade Goodall. All Rights Reserved.       //
//////////////////////////////////////////////////////////////////////////////

#include "std.h"
#include "crtbind.h"

/**
 * @brief Default constructor for the crtbind class.
 *
 * Initializes an instance of the crtbind class.
 * The class provides functionality for handling terminal-style visual output,
 * such as screen clearing, cursor movement, and text styling.
 *
 * @return A constructed crtbind object.
 */
crtbind::crtbind() {

}

/**
 * @brief Clears the terminal screen.
 *
 * This function uses ANSI escape codes to clear the entire
 * terminal screen. It sends the escape sequence "\x1B[2J"
 * to clear all visible content from the terminal display.
 */
void crtbind::crtclr() {
    std::cout << "\x1B[2J";  // ANSI escape: clear entire screen
}

/**
 * Moves the cursor to a specified position in the terminal.
 *
 * This function sets the terminal cursor to the specific `line` and `col`
 * (row and column) using ANSI escape codes. It directly interacts with
 * the terminal by outputting the escape sequence necessary to reposition
 * the cursor.
 *
 * @param line The row number to which the cursor will be moved (starting from 1).
 * @param col The column number to which the cursor will be moved (starting from 1).
 */
void crtbind::crtlc(int line, int col) {
    std::cout << "\x1B[" << line << ";" << col << "H";
}

/**
 * @brief Sets the display style of the console text.
 *
 * This function applies formatting to console text by combining a mode,
 * foreground color, and background color. It uses ANSI escape codes to set
 * the desired text attributes.
 *
 * @param mode Specifies the text mode (e.g., bold, underline, reset).
 * @param fg Specifies the foreground color for the text.
 * @param bg Specifies the background color for the text.
 */
void crtbind::crtstyle(MODE_T mode, FG_COLORS_T fg, BG_COLORS_T bg) {
    std::cout << "\x1B[" << mode << ";" << fg << ";" << bg << "m";
}