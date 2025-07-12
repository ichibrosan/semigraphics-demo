/////////////////////////////////////////////////////////////////////////////////
// /home/doug/CLionProjects/semigraphics/semigraphics.h 2025/07/12 02:47 dwg - //
// Copyright (c) 2021-2025 Douglas Wade Goodall. All Rights Reserved.          //
/////////////////////////////////////////////////////////////////////////////////

#ifndef SEMIGRAPHICS_H
#define SEMIGRAPHICS_H

#define COPR "©"
#define CHECK "✓"

#define SV  "│"     // single vertical
#define SH  "─"     // single horizontal
#define DV  "║"     // double vertical
#define DH  "═"     // double horizontal

// Single Rounded Corners
#define SRUL "╭"    // single rounded upper left
#define SRUR "╮"    // single rounded upper right
#define SRLL "╰"    // single rounded lower left
#define SRLR "╯"    // single rounded lower right

// Single Square Corners
#define SSUL "┌"    // single square upper left
#define SSUR "┐"    // single square upper right
#define SSLL "└"    // single square lower left
#define SSLR "┘"    // single square lower right

// Double Square Corners
#define DSUL "╔"    // double square upper left
#define DSUR "╗"    // double square upper right
#define DSLL "╚"    // double square lower left
#define DSLR "╝"    // double square lower right
#define DHL  "═"    // double horizontal line
#define DVL  "║"    // double vertical lines

// Single Vertical Corners
#define ULDHSV  "╒" // upper left double horizontal single vertical
#define URDHSV  "╕" // upper right double horizontal single vertical
#define LLDHSV  "╘" // lower left double horizontal single vertical
#define LRDHSV  "╛" // lower right double horizontal single vertical

// Double Vertical Corners
#define ULSHDV  "╓" // upper left single horizontal double vertical
#define URSHDV  "╖" // upper right single horizontal double vertical
#define LLSHDV  "╙" // lower left single horizontal double vertical
#define LRSHDV  "╜" // lower right single horizontal double vertical

// Double Line Extentions
#define SVSR "├"
#define SVSL "┤"
#define DVSR "╟"
#define DVSL "╢"

#define DVDHL "╣"    // double vertical double horizontal left
#define DVDHR "╠"    // double vertical double right
#define DHDVL "╣"    // double horizontal double vertical
#define DHDVD "╦"   // double horizontal double vertical downward
#define DHDVU "╩"   // double horizontal double vertical upward

// Bi-Directional Extentions
#define DVSHRL  "╫" // double vertical single horizontal right & left
#define DHSVUP  "╪" // double horizontal single vertical up & down
#define DVERTEX "╬" // double horizontal double vertical cross

// Doublel Line Single Extentions
#define DHSDV "╤"   // double horizontal single downward vertical
#define DHSUV "╧"   // double horizontal single upward vertical
#define DVSHL "╢"   // double vertical single horizontal leftward
#define DVSHR "╟"   // double vertical single horizontal rightward

// Single Line Double Extentions
#define SVDHR "╞"   // single vertical double horizontal right
#define SVDHL "╡"   // single vertical double horizontal left
#define SHDVD "╥"   // single horizontal double vertical downward
#define SHDVU "╨"   // single horizontal double vertical upward

// Angular Components
#define FWDSLSH "╱" // lower left to upper right
#define BCKSLSH "╲" // upper left to lower right
#define SLNTEX  "╳"


/**
 * The semigraphics class provides methods for rendering semi-graphical boxes
 * and lines with customizable aesthetics in a text-based interface.
 */
class semigraphics {
    /**
     * Represents the character or symbol used for the upper-left corner of a box
     * in semigraphics. This string is used to render graphical elements for the
     * upper-left boundary of a box.
     */
    std::string m_ssUL;
    /**
     * Represents the top-right corner symbol of a box in the semigraphics.
     * This member is used as part of the box rendering for graphical representations.
     */
    std::string m_ssUR;
    /**
     * Represents the lower-left corner symbol used for drawing boxes
     * and outlines in the semigraphics class.
     */
    std::string m_ssLL;
    /**
     * Represents the lower-right corner symbol for the semigraphics object.
     * This string is used to define the character that visually represents
     * the lower-right corner in various graphic elements such as boxes
     * and lines.
     */
    std::string m_ssLR;
    /**
     * A semigraphic character or string used for visual appearance in console UI designs.
     *
     * m_ssVSR is a character or string representing the vertical right splitter for dividing
     * screen areas or elements in a tabular, boxed, or structured layout. It is typically
     * used in constructing vertical splitters or dividers on the right side in console-based
     * visual designs.
     */
    std::string m_ssVSR;
    /**
     * Represents the left vertical splitter character in semigraphics.
     * This member variable is used to define and store the character or string
     * that represents the left vertical boundary or splitter for rendering
     * graphical elements in a semigraphics context.
     */
    std::string m_ssVSL;
    /**
     * @brief Represents the horizontal line segment used in the graphics.
     *
     * This member variable holds a string that defines the character(s) used
     * to generate horizontal lines in components such as boxes, splitters, and lines.
     * It is utilized in rendering graphical structures by methods like singlebox,
     * topline, and vert_splitter.
     */
    std::string m_ssHL;
    /**
     * @brief Stores the vertical line character for box drawing.
     *
     * This member variable is used in the semigraphics class to define
     * the character or string that represents vertical borders
     * when drawing boxes or other graphical structures in a console-based
     * context.
     */
    std::string m_ssVL;

    /**
     * @brief Constructor for the semigraphics class.
     *
     * Initializes an instance of the semigraphics class. This class provides
     * functionality for rendering ASCII or Unicode-based graphical elements such
     * as boxes, lines, and separators in a console or terminal environment.
     */
   public:
    semigraphics();
    /**
     * Draws a single box with the specified dimensions starting from the given position.
     *
     * The box consists of a top border, side borders, and a bottom border, defined using semigraphics.
     *
     * @param line The starting row (line) coordinate for the box.
     * @param col The starting column coordinate for the box.
     * @param width The width of the box including the borders.
     * @param height The height of the box including the borders.
     */
    void singlebox(int line, int col, int width, int height);
    /**
     * Draws the top line of a box-like structure on the console using semigraphical
     * characters. The method controls the appearance of the top border by printing
     * the upper-left corner character, horizontal line characters, and the
     * upper-right corner character.
     *
     * @param line The starting line (row coordinate) of the top line of the box.
     * @param col The starting column (column coordinate) of the top line.
     * @param width The total width of the box, which determines the number of
     *        horizontal line characters.
     * @param height The total height of the box. It is included for consistency
     *        but is not directly used within this method.
     */
    void topline(int line, int col, int width, int height);
    /**
     * Draws a middle line of a box with optional text alignment within specified dimensions.
     *
     * The function prints a line surrounded by vertical separators using the `m_ssVL` character.
     * If `ssText` is shorter than the designated width, the remaining space is filled with spaces
     * to align the text within the box. If the text exceeds the width, it is not truncated
     * by this function.
     *
     * @param line The zero-based starting line number for the middle line.
     * @param col The zero-based starting column number for the middle line (not utilized in implementation).
     * @param width The total width of the line including any box borders.
     * @param height The total height of the box (not utilized in this function).
     * @param ssText The text to be centered and displayed within the line.
     */
    void middleline(int line, int col, int width, int height,std::string ssText);
    /**
     * Draws a vertical splitter line within a defined rectangular region.
     *
     * The function uses preconfigured string assets as part of the `semigraphics` class
     * to construct a vertical splitter by printing characters on the console. It starts
     * by outputting the `m_ssVSR` (vertical splitter right asset), followed by a series
     * of `m_ssHL` (horizontal line asset) characters that span the width minus two columns.
     * Finally, it outputs the `m_ssVSL` (vertical splitter left asset) and ends the line.
     *
     * Parameters:
     * - line: The starting line of the splitter.
     * - col: The starting column of the splitter.
     * - width: The total width of the rectangular region containing the splitter.
     * - height: The total height of the rectangular region containing the splitter.
     */
    void vert_splitter(int line, int col, int width, int height);
    /**
     * Generates the bottom line of a rectangular box for semigraphics purposes.
     *
     * This method outputs a line beginning with the lower-left corner character,
     * followed by horizontal line characters to span the width minus the corners,
     * and ends with the lower-right corner character. The line is then terminated
     * with a newline for formatting.
     *
     * @param line The zero-based Y-coordinate where the line begins.
     * @param col The X-coordinate indicating the starting point for the bottom line.
     * @param width The total width of the box, including the corners.
     * @param height The total height of the box; however, this parameter is not
     *               directly utilized in this function.
     */
    void endline(int line, int col, int width, int height);
    /**
     * @brief Configures the cosmetic characters used for rendering semigraphical elements.
     *
     * This function defines characters used to construct visual elements, like borders
     * and separators, for the semigraphics rendering system. These characters are set
     * using Unicode box-drawing characters or similar symbols, which enable customizable
     * appearances for graphical elements.
     *
     * @param ssUL Character used for the upper-left corner of the box.
     * @param ssUR Character used for the upper-right corner of the box.
     * @param ssLL Character used for the lower-left corner of the box.
     * @param ssLR Character used for the lower-right corner of the box.
     * @param ssVSR Character used for the right vertical splitter.
     * @param ssVSL Character used for the left vertical splitter.
     * @param ssHL Character used for horizontal lines.
     * @param ssVL Character used for vertical lines.
     */
    void cosmetics(std::string UpperLeft,std::string UpperRight,
                   std::string LowerLeft,std::string LowerRight,
                   std::string VertSplitRight,std::string VertSplitLeft,
                   std::string HorizontalLine,std::string VerticalLine);
};



#endif //SEMIGRAPHICS_H
