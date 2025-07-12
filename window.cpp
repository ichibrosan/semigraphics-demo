//////////////////////////////////////////////////////////////////////////////
// /home/doug/CLionProjects/semigraphics/window.cpp  2025/07/12 02:47 dwg - //
// Copyright (c) 2021-2025 Douglas Wade Goodall. All Rights Reserved.       //
//////////////////////////////////////////////////////////////////////////////

#include "std.h"
#include "window.h"
#include "semigraphics.h"
#include "crtbind.h"

//#include "mwfw2.h"

/**
 * @brief Global pointer to crtbind instance.
 *
 * This global variable serves as a handle to the primary instance of the
 * `crtbind` class. It is used to access terminal-related functionalities,
 * such as clearing the screen, setting text styles, and positioning the cursor.
 *
 * The `gpCrt` variable is typically initialized at runtime before being used
 * in other parts of the application. It provides centralized access to the
 * terminal control features implemented by the `crtbind` class.
 */
extern crtbind * gpCrt;
/**
 * @var gpSemiGr
 * @brief Represents an instance of the semigraphics class used for graphical operations.
 *
 * This variable is utilized as a global object to manage or perform
 * semigraphical operations within the application. It handles the data and functionalities
 * related to rendering or working with semigraphic elements in the program.
 */
extern semigraphics * gpSemiGr;

/**
 * @brief Constructs a default window object with uninitialized dimensions.
 *
 * This constructor initializes the window object settings to their default values.
 * The x and y coordinates, width, and height of the window are all set to zero
 * instead of being initialized from possible external configuration data.
 *
 * @return A new instance of the window class with default values.
 */
window::window(
    // WinDesc& wd
    ) {
    m_x = 0; // wd.x;
    m_y = 0; // wd.y;
    m_width = 0; // wd.width;
    m_height = 0; // wd.height;
}

/**
 * Adds a new row of text to the window content, dynamically adjusting
 * the window's height and width if needed.
 *
 * @param ssRow The string representing the content of the row to be added.
 */
void window::add_row(std::string ssRow) {
    m_ssData.push_back(ssRow);
    m_height++;
    int iRowSize = ssRow.size() + 3;
    if (m_width < iRowSize) {
        m_width = iRowSize;
    }
};

/**
 * @brief Sets the title of the window and adjusts the width if necessary.
 *
 * This method updates the window's title to the specified string. Additionally,
 * it ensures that the window's width is at least the size of the title plus three characters.
 *
 * @param ssTitle The new title for the window.
 */
void window::set_title(std::string ssTitle) {
    m_ssTitle = ssTitle;
    int iTitleSize = ssTitle.size() + 3;
    if (m_width < iTitleSize) {
        m_width = iTitleSize;
    }
}

/**
 * Retrieves the current height of the window.
 *
 * @return The height of the window in pixels or unspecified units.
 */
int window::get_height() {
    return m_height;
}

/**
 * Retrieves the current width of the window.
 *
 * @return The width of the window as an integer.
 */
int window::get_width() {
    return m_width;
}

/**
 * Retrieves the zero-based column number of the left corner edge of the window.
 *
 * @return The zero relative column number of the left corner edge of the window.
 */
int window::get_x() {
    return m_x;
}

/**
 * Retrieves the vertical position of the window's top edge.
 *
 * @return The zero-based line number of the top edge of the window.
 */
int window::get_y() {
    return m_y;
}


/**
 * @brief Renders the window layout and content to the terminal.
 *
 * This function uses the semigraphics and crtbind modules to create and display
 * a styled terminal-based window. It performs the following:
 * - Sets the text style to bold green text on a black background.
 * - Draws the top border of the window.
 * - Draws the window title in the middle of the top section.
 * - Draws a vertical splitter for layout separation.
 * - Iterates through the window's content (m_ssData) to display each row.
 * - Draws the bottom border of the window.
 * - Resets the text style to bold cyan text on a black background.
 */
void window::render() {
    gpCrt->crtstyle(MODE_BOLD,FG_GREEN,BG_BLACK);
    gpSemiGr->topline(1,1,m_width,m_height);
    gpSemiGr->middleline(1,1,m_width,m_height,m_ssTitle);
    gpSemiGr->vert_splitter(1,1,m_width,m_height);
    for (const std::string& str : m_ssData ) {
        gpSemiGr->middleline(1,1,m_width,m_height,str);
    }
    gpSemiGr->endline(1,1,m_width,m_height);
    gpCrt->crtstyle(MODE_BOLD,FG_CYAN,BG_BLACK);
}

/**
 * @brief Renders the frame for the window, including top, middle, and end lines.
 *
 * This function defines the visual frame around the window. It uses `gpCrt`
 * and `gpSemiGr` to set the text style and render the borders and contents
 * of the frame. The steps include:
 * - Setting the initial text style using a bold green style.
 * - Rendering a top line of the frame based on the window dimensions.
 * - Iterating over the stored textual data (`m_ssData`) to populate the middle lines.
 * - Rendering the bottom line of the frame to complete it.
 * - Resetting the style to a bold cyan configuration.
 *
 * External global objects `gpCrt` and `gpSemiGr` are used for rendering the
 * styles and graphical elements, and the window's dimensions (`m_width`, `m_height`)
 * are used to size the frame appropriately.
 */
void window::render_frames() {
    gpCrt->crtstyle(MODE_BOLD,FG_GREEN,BG_BLACK);
    gpSemiGr->topline(1,1,m_width,m_height);
    for (const std::string& str : m_ssData ) {
        gpSemiGr->middleline(1,1,m_width,m_height,str);
    }
    gpSemiGr->endline(1,1,m_width,m_height);
    gpCrt->crtstyle(MODE_BOLD,FG_CYAN,BG_BLACK);



}

/**
 * @brief Renders the text content of the window onto the screen.
 *
 * This method is responsible for outputting the text content stored in the
 * window instance (e.g., the title or any other data associated with its text representation).
 * It takes into account the current state of the window, such as its dimensions
 * and content stored in m_ssData.
 *
 * It should ensure the text fits appropriately within the bounds of the window
 * and is displayed in the desired manner.
 */
void window::render_text() {

}

/**
 * Displays the properties of the window to the standard output.
 *
 * This method prints the window's descriptor information, including:
 * - The title of the window, if it is set.
 * - The x and y coordinates of the window's position on the screen.
 * - The width and height of the window.
 *
 * This method is primarily used for debugging purposes to inspect
 * the state of the window object.
 */
void window::show() {
    std::cout << "windows descriptor:" << std::endl;
    if (m_ssTitle.size() > 0) {
        std::cout << "title: " << m_ssTitle << std::endl;
    }
    std::cout << "x: " << m_x << std::endl;
    std::cout << "y: " << m_y << std::endl;
    std::cout << "width: " << m_width << std::endl;
    std::cout << "height: " << m_height << std::endl;
    std::cout << std::endl;
}

/**
 * @brief Destructor for the window class.
 *
 * Releases any resources or memory held by the window object.
 * Ensures proper cleanup of the window when it goes out of scope.
 */
window::~window() {

}