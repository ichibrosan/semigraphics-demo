///////////////////////////////////////////////////////////////////////////////////
// /home/doug/CLionProjects/semigraphics/semigraphics.cpp 2025/07/12 02:47 dwg - //
// Copyright (c) 2021-2025 Douglas Wade Goodall. All Rights Reserved.            //
///////////////////////////////////////////////////////////////////////////////////

#include "std.h"
#include "semigraphics.h"


/**
 * @brief Default constructor for the semigraphics class.
 *
 * Initializes a new instance of the semigraphics class, setting up
 * the internal state with default values for creating semigraphic
 * elements.
 *
 * @return A default-initialized object of type semigraphics.
 */
semigraphics::semigraphics() {

}

/**
 * @brief Configures cosmetic characters for semigraphics output.
 *
 * This method sets various visual elements for rendering semigraphics,
 * including corners and lines used for creating box-like structures.
 *
 * @param ssUL The character for the upper-left corner of the box.
 * @param ssUR The character for the upper-right corner of the box.
 * @param ssLL The character for the lower-left corner of the box.
 * @param ssLR The character for the lower-right corner of the box.
 * @param ssVSR The character for the vertical splitter on the right side.
 * @param ssVSL The character for the vertical splitter on the left side.
 * @param ssHL The character for the horizontal line.
 * @param ssVL The character for the vertical line.
 */
void semigraphics::cosmetics(std::string ssUL,std::string ssUR,
                             std::string ssLL,std::string ssLR,
                             std::string ssVSR,std::string ssVSL,
                             std::string ssHL,std::string ssVL) {
    m_ssUL = ssUL;
    m_ssUR = ssUR;
    m_ssLL = ssLL;
    m_ssLR = ssLR;
    m_ssVSR = ssVSR;
    m_ssVSL = ssVSL;
    m_ssHL = ssHL;
    m_ssVL = ssVL;
}

/**
 * @brief Draws a single-line border box with the specified dimensions and position.
 *
 * This method generates a box using single-line semigraphic characters, with
 * the top-left corner starting at the specified coordinates `(line, col)`.
 *
 * @param line The vertical starting position of the box.
 * @param col The horizontal starting position of the box.
 * @param width The width of the box in characters, including borders.
 * @param height The height of the box in lines, excluding the top and bottom borders.
 */
void semigraphics::singlebox(int line, int col, int width, int height) {

    // Top line of box
    std::cout << m_ssUL;
    for (int iColdex = col; iColdex<width-2; iColdex++) {
        std::cout << m_ssHL;
    }
    std::cout << m_ssUR;
    std::cout << std::endl;

    // Middle lines of box
    for (int iLinedex = 0; iLinedex<height; iLinedex++) {
        std::cout << m_ssVL;
        for (int iColdex = 0; iColdex<width-3; iColdex++) {
            std::cout << "\u0020";
        }
        std::cout << m_ssVL;
        std::cout << std::endl;
    }

    // Bottom line of box
    std::cout << m_ssLL;
    for (int iColdex = col; iColdex<width-2; iColdex++) {
        std::cout << m_ssHL;
    }
    std::cout << m_ssLR;
    std::cout << std::endl;
}

/**
 * Draws the top line of a box using the specified position and dimensions.
 *
 * @param line The starting line position for the top line of the box.
 * @param col The starting column position for the top line of the box.
 * @param width The width of the box.
 * @param height The height of the box (currently not used in the function).
 */
void semigraphics::topline(int line, int col, int width, int height) {
    // Top line of box
    std::cout << m_ssUL;
    for (int iColdex = col; iColdex<width-2; iColdex++) {
        std::cout << m_ssHL;
    }
    std::cout << m_ssUR;
    std::cout << std::endl;
}

/**
 * Outputs a formatted middle line for a box structure with optional text,
 * padded to fit within the specified width.
 *
 * @param line The row position of the middle line on the screen.
 * @param col The column position of the middle line on the screen.
 * @param width The total width of the box including the middle line.
 * @param height The height of the box, which influences where the middle line appears.
 * @param ssText The text to display in the middle line, centered and padded with spaces.
 */
void semigraphics::middleline(int line, int col,
                              int width, int height,
                              std::string ssText) {
    std::cout << m_ssVL;
    std::cout << ssText;
    int textlen = ssText.size();
    if (textlen < width-3) {
        int fillsize = width-3-textlen;
        for (int i = 0; i<fillsize; i++) {
            std::cout << " ";
        }
    }
    std::cout << m_ssVL;
    std::cout << std::endl;
}

/**
 * @brief Draws a vertical splitter line in a graphical box.
 *
 * This method generates a vertical splitter line within a graphical box structure
 * based on the provided dimensions and position. It utilizes pre-defined symbols
 * stored in the class for rendering the splitter visually.
 *
 * @param line The starting line (row) coordinate for the vertical splitter.
 * @param col The starting column coordinate for the vertical splitter.
 * @param width The total width of the box containing the splitter.
 * @param height The total height of the box containing the splitter.
 */
void semigraphics::vert_splitter(int line, int col, int width, int height) {

    std::cout << m_ssVSR;
    for (int iColdex = col; iColdex<width-2; iColdex++) {
        std::cout << m_ssHL;
    }
    std::cout << m_ssVSL;
    std::cout << std::endl;
}


/**
 * Outputs a formatted "endline" using semigraphics characters, including specific edges and a repeated horizontal line.
 *
 * @param line The starting line number for the graphics output. This parameter does not directly affect this method's behavior.
 * @param col The starting column index for the horizontal line.
 * @param width The total width of the area, affects the number of repeated horizontal characters.
 * @param height The height of the area. This parameter does not directly affect this method's behavior.
 */
void semigraphics::endline(int line, int col, int width, int height) {

    std::cout << m_ssLL;
    for (int iColdex = col; iColdex<width-2; iColdex++) {
        std::cout << m_ssHL;
    }
    std::cout << m_ssLR;
    std::cout << std::endl;
}

////////////////////////////
// eof - semigraphics.cpp //
////////////////////////////