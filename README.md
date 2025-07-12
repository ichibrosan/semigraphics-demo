## Project Overview
The **semigraphics** project is a C++23 terminal-based framework for creating bordered windows with Unicode box-drawing characters. It provides a clean API for rendering professional-looking text-based user interfaces with customizable borders and styling.
## Module Documentation
### 1. Standard Library Aggregation Header **std.h**
**Purpose**: Provides a unified header that includes all necessary standard library components, emulating the functionality of C++23's directive. `import std;`
**Key Features**:
- Comprehensive inclusion of C++17/C++23 standard library headers
- Legacy system includes for POSIX compatibility
- Predefined macros for return codes
- Acts as a single point of inclusion for all standard library functionality

**Usage**: Include this header in all source files to access standard library functions without individual includes.
### 2. Terminal Control Binding **crtbind.h****crtbind.cpp**
**Purpose**: Provides low-level terminal control functionality using ANSI escape sequences.
**Key Components**:
#### Enumerations:
- **`MODE_T`**: Text styling modes (bold, italic, underline, etc.)
- **`FG_COLORS_T`**: Foreground color definitions
- **`BG_COLORS_T`**: Background color definitions

#### Class Methods:
- **`crtclr()`**: Clears the entire terminal screen
- **`crtlc(int line, int col)`**: Positions cursor at specified coordinates
- **`crtstyle(MODE_T mode, FG_COLORS_T fg, BG_COLORS_T bg)`**: Sets text styling attributes

**Technical Details**:
- Uses ANSI escape sequences for terminal control
- Supports standard terminal color palette
- Provides immediate visual feedback through stdout

### 3. Unicode Box Drawing Engine **semigraphics.h****semigraphics.cpp**
**Purpose**: Core rendering engine for creating bordered boxes and frames using Unicode box-drawing characters.
#### Character Definitions:
- **Single-line variants**: `┌┐└┘─│`
- **Double-line variants**: `╔╗╚╝═║`
- **Rounded corners**: `╭╮╰╯`
- **Complex junctions**: `├┤┬┴┼`

#### Key Methods:
**`cosmetics()`**:
- Configures the visual style of box elements
- Allows runtime customization of border characters
- Parameters: UpperLeft, UpperRight, LowerLeft, LowerRight, VertSplitRight, VertSplitLeft, HorizontalLine, VerticalLine

**`singlebox(int line, int col, int width, int height)`**:
- Renders a complete rectangular box
- Handles positioning and sizing automatically
- Creates frame with empty interior

**`topline(int line, int col, int width, int height)`**:
- Renders the top border of a box
- Uses configured corner and horizontal line characters

**`middleline(int line, int col, int width, int height, std::string ssText)`**:
- Renders a content line with text
- Automatically pads with spaces to maintain alignment
- Handles text positioning within borders

**`vert_splitter(int line, int col, int width, int height)`**:
- Creates horizontal divider lines within boxes
- Uses junction characters for proper connection

**`endline(int line, int col, int width, int height)`**:
- Renders the bottom border of a box
- Completes the box structure

### 4. Window Management System **window.h****window.cpp**
**Purpose**: High-level window abstraction that combines semigraphics rendering with content management.
#### Data Structures:
**`WinDesc`**: Window descriptor structure (currently unused but defined for future expansion)
- `x`, `y`: Position coordinates
- `width`, `height`: Dimensions
- `ssData`: Content storage

#### Class Members:
- **, `m_x``m_y`**: Window position coordinates
- **, `m_width``m_height`**: Dynamic window dimensions
- **`m_ssTitle`**: Window title string
- **`m_ssData`**: Vector of content strings

#### Key Methods:
**`add_row(std::string ssRow)`**:
- Adds content line to window
- Automatically adjusts window height
- Updates width based on content length

**`set_title(std::string ssTitle)`**:
- Sets window title
- Adjusts window width to accommodate title

**`render()`**:
- Complete window rendering with styling
- Combines frame drawing with content display
- Applies color styling through crtbind

**`show()`**:
- Diagnostic method for displaying window properties
- Useful for debugging and development

**Accessor Methods**: , , , `get_height()``get_width()``get_x()``get_y()`
### 5. Application Entry Point and Demo **main.cpp**
**Purpose**: Demonstrates the framework capabilities and serves as the primary application entry point.
#### Global Variables:
- **`gpCrt`**: Global crtbind instance pointer for terminal control
- **`gpSemiGr`**: Global semigraphics instance pointer for rendering

#### Main Function Workflow:
1. **Initialization**: Creates instances of crtbind, semigraphics, and window classes
2. **Configuration**: Sets up Unicode box-drawing characters using rounded corners
3. **Content Setup**: Creates copyright notice and application title
4. **Rendering**: Displays the configured window with styling

#### Character Configuration:
- Uses rounded single-line border style (`╭╮╰╯─│`)
- Implements professional appearance with consistent styling
- Configures separators for complex layouts

## Architecture Overview
The framework follows a layered architecture:
1. **Terminal Layer** (`crtbind`): Low-level terminal control
2. **Graphics Layer** (`semigraphics`): Unicode character rendering
3. **Window Layer** (`window`): High-level window management
4. **Application Layer** (`main`): User interface and business logic

## Usage Pattern
``` cpp
// Initialize framework
gpCrt = new crtbind();
gpSemiGr = new semigraphics();

// Configure appearance
gpSemiGr->cosmetics(corners, lines, etc.);

// Create and populate window
window* pWin = new window();
pWin->set_title("My Application");
pWin->add_row("Content line 1");
pWin->add_row("Content line 2");

// Render to terminal
pWin->render();
```
This documentation provides a comprehensive understanding of each module's purpose, functionality, and integration within the semigraphics framework.
