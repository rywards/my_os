static char* const VGA_MEMORY = (char*) 0xb8000;

static const int VGA_WIDTH = 80;
static const int VGA_HEIGHT = 25;
static const int TERM_NUM = 69;
static const int TOTAL_DISPLAY = 2 * VGA_WIDTH * VGA_HEIGHT;
static int CURR_LOC = 0;
static char* EXIT_MSG = "[***Good-bye!***]";

void terminal_print_line(char* string);
void putchar(char);
