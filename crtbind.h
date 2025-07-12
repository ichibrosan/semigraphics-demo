//////////////////////////////////////////////////////////////////////////////
// /home/doug/CLionProjects/semigraphics/crtbind.h   2025/07/12 02:47 dwg - //
// Copyright (c) 2021-2025 Douglas Wade Goodall. All Rights Reserved.       //
//////////////////////////////////////////////////////////////////////////////

#ifndef CRTBIND_H
#define CRTBIND_H

/**
 * @enum MODE_T
 * @brief Represents text style modes for terminal formatting.
 *
 * This enumeration defines various text formatting attributes that can
 * be applied to text in a terminal. Each value corresponds to a specific
 * formatting mode used for styling the text.
 *
 * - MODE_RESET: Resets all formatting attributes to default.
 * - MODE_BOLD: Displays text in bold style.
 * - MODE_DIM: Displays text in dim style.
 * - MODE_ITALIC: Displays text in italic style.
 * - MODE_UNDERLINE: Underlines the text.
 * - MODE_BLINK: Makes the text blink.
 * - MODE_REVERSE: Reverses the foreground and background colors.
 * - MODE_HIDDEN: Hides the text.
 * - MODE_STRIKE: Strikethrough text.
 */
enum MODE_T {
    MODE_RESET = 30,    // Reset all attributes
    MODE_BOLD,          // Bold text
    MODE_DIM,           // Dim text
    MODE_ITALIC,        // Italic text
    MODE_UNDERLINE,     // Underlined text
    MODE_BLINK,         // Blinking text
    MODE_REVERSE = 37,  // Reverse video
    MODE_HIDDEN,        // Hidden text
    MODE_STRIKE         // Strikethrough text
};

/**
 * @enum FG_COLORS_T
 * This enumeration defines the foreground color codes for terminal text.
 * The values correspond to the ANSI escape codes for text coloring.
 *
 * Enumerators:
 * - FG_BLACK: Represents black foreground color (value 30).
 * - FG_RED: Represents red foreground color.
 * - FG_GREEN: Represents green foreground color.
 * - FG_YELLOW: Represents yellow foreground color.
 * - FG_BLUE: Represents blue foreground color.
 * - FG_MAGENTA: Represents magenta foreground color.
 * - FG_CYAN: Represents cyan foreground color.
 * - FG_WHITE: Represents white foreground color.
 */
enum FG_COLORS_T {
    FG_BLACK = 30, FG_RED, FG_GREEN, FG_YELLOW,
    FG_BLUE, FG_MAGENTA, FG_CYAN, FG_WHITE
};

/**
 * @enum BG_COLORS_T
 *
 * Enumeration representing background colors for terminal text formatting.
 * These values correspond to ANSI color codes for setting background colors.
 *
 * - BG_BLACK: Sets the background color to black (ANSI code: 40).
 * - BG_RED: Sets the background color to red (ANSI code: 41).
 * - BG_GREEN: Sets the background color to green (ANSI code: 42).
 * - BG_YELLOW: Sets the background color to yellow (ANSI code: 43).
 * - BG_BLUE: Sets the background color to blue (ANSI code: 44).
 * - BG_MAGENTA: Sets the background color to magenta (ANSI code: 45).
 * - BG_CYAN: Sets the background color to cyan (ANSI code: 46).
 * - BG_WHITE: Sets the background color to white (ANSI code: 47).
 */
enum BG_COLORS_T {
    BG_BLACK = 40, BG_RED, BG_GREEN, BG_YELLOW,
    BG_BLUE, BG_MAGENTA, BG_CYAN, BG_WHITE
};

/**
 * @class crtbind
 * @brief A class for terminal screen manipulation and styling.
 *
 * The crtbind class provides methods to control terminal screen operations,
 * including screen clearing, cursor movement, and text styling.
 * It is designed to work with terminal graphic features such as foreground
 * and background colors, as well as text modes like bold, underline, and more.
 */
class crtbind {
    /**
     * @brief Constructor for the crtbind class.
     *
     * Initializes a new instance of the crtbind class, setting up
     * the necessary internal state for its functionality.
     *
     * @return A default-initialized object of type crtbind.
     */
public:
    crtbind();
    /**
     * @brief Clears the terminal screen using ANSI escape codes.
     *
     * This method sends an ANSI escape code to the terminal to clear the entire screen.
     * It is typically used to reset the terminal display for subsequent updates.
     */
    void crtclr();
    /**
     * Moves the cursor to the specified position in the terminal.
     *
     * @param line The line number to move the cursor to (1-based index).
     * @param col The column number to move the cursor to (1-based index).
     */
    void crtlc(int line,int col);
    /**
     * Sets the text style, foreground color, and background color for the terminal output.
     *
     * @param mode Specifies the text style mode (e.g., bold, underline, italic).
     *             It is represented by the MODE_T enum.
     * @param fg   Specifies the foreground color of the text.
     *             It is represented by the FG_COLORS_T enum.
     * @param bg   Specifies the background color of the text.
     *             It is represented by the BG_COLORS_T enum.
     */
    void crtstyle(MODE_T mode,FG_COLORS_T fg,BG_COLORS_T bg);
};



#endif //CRTBIND_H