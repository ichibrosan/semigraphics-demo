//////////////////////////////////////////////////////////////////////////////
// /home/doug/CLionProjects/semigraphics/main.cpp    2025/07/12 02:47 dwg - //
// Copyright (c) 2021-2025 Douglas Wade Goodall. All Rights Reserved.       //
//////////////////////////////////////////////////////////////////////////////

#include "std.h"
#include "semigraphics.h"
#include "window.h"
#include "crtbind.h"

/**
 * @brief Global pointer to an instance of the crtbind class.
 *
 * This global variable is used to interact with terminal display functionality
 * provided by the `crtbind` class. It enables operations such as clearing
 * the terminal, moving the cursor, or configuring text styles. The instance
 * pointed to by `gpCrt` must be initialized before use.
 */
crtbind * gpCrt;
/**
 * @brief Global pointer for managing semigraphics rendering.
 *
 * This global variable is an instance of the `semigraphics` class, which
 * provides methods to render semigraphical elements such as lines, boxes,
 * and separators on the console or user interface. It facilitates the
 * customization of visual elements by allowing the configuration of cosmetic
 * characters and styles.
 *
 * The `gpSemiGr` variable is used across the application to handle the rendering
 * of graphical components and is initialized during the application's startup.
 * It simplifies the design and manipulation of semigraphics-based UI components
 * by providing centralized functionality.
 */
semigraphics * gpSemiGr;

/**
 * @brief Entry point of the program.
 *
 * Initializes global objects for terminal manipulation and semigraphics,
 * customizes the appearance of a window using Unicode characters, builds
 * and appends a copyright notice, sets the window title and dynamically
 * renders it to the terminal.
 *
 * @return An integer representing the program's execution status.
 *         Returns 0 upon successful completion.
 */
int main()
{
    gpCrt = new crtbind();
    gpSemiGr = new semigraphics();
    window * pWin = new window();

    /**
     * @brief Configure window cosmetic characters
     *
     * Sets up the visual appearance of the window using Unicode box-drawing
     * characters for creating professional-looking borders and separators.
     *
     * Character mapping:
     * - SRUL: ┌ (top-left corner)
     * - SRUR: ┐ (top-right corner)
     * - SRLL: └ (bottom-left corner)
     * - SRLR: ┘ (bottom-right corner)
     * - SVSR: ├ (vertical separator right)
     * - SVSL: ┤ (vertical separator left)
     * - SH:   ─ (horizontal line)
     * - SV:   │ (vertical line)
     */
    gpSemiGr->cosmetics(
        SRUL,     SRUR,  SRLL,    // Corner characters: ┌ ┐ └ ┘
        SRLR,  SVSR,  SVSL,    // Right corner and separators
        SH,    SV);               // Horizontal ─ and vertical │ lines

    /**
     * @brief Build copyright notice string
     *
     * Constructs the copyright notice with proper formatting, including
     * the copyright symbol for legal compliance and professional appearance.
     */
    std::string ssCopr = "  Copyright ";
    ssCopr.append("(c)");  // Append copyright symbol for compatibility
    ssCopr.append(" 2025 Douglas Wade Goodall. All Rights Reserved.");

    /**
     * @brief Configure window title and initial content
     *
     * Sets the window title to identify the application and version,
     * then adds the copyright notice as the first row of content.
     */
    pWin->set_title("MultiWare Engineering Framework Semigraphics Demo Ver 5.7.12.2");
    pWin->add_row(ssCopr);

    pWin->render();

    return 0;
}