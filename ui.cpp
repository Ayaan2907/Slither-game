#include "ui.h"
// https://stackoverflow.com/questions/172587/what-is-the-difference-between-g-and-gcc
// Compile: g++ snake.cpp -finput-charset=UTF-8 -lncursesw -o ./snake
// refrence for ncurses // https://invisible-island.net/ncurses/man/ncurses.3x.html

void init_ui() {
	setlocale(LC_ALL, "");  // override default locale of ISO-8859-1
	initscr();  // initialize curses mode
	curs_set(0);  // invisible cursor
	noecho();  // don't echo chars back to the terminal
	// Get char as soon as it is typed (don't wait for CR)
	// raw();  // send ^C to program
	cbreak();  // generate interrupt on ^C
	// enable reading of function and arrow keys, backspace, del..
	keypad(stdscr, TRUE);
	start_color();
	// init_pair(index, foreground, background)
	// BLACK RED GREEN YELLOW BLUE MAGENTA CYAN WHITE
	init_pair(SNAKE_COLOR_PAIR, COLOR_RED, COLOR_BLACK);
	init_pair(FOOD_COLOR_PAIR, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(BORDER_COLOR_PAIR, COLOR_WHITE, COLOR_BLACK);
	init_pair(STATUS_COLOR_PAIR, COLOR_GREEN, COLOR_WHITE);
	nodelay(stdscr, TRUE);  // make getch non-blocking. return ERR if no input

	// addch(ch | ...)
	// A_NORMAL        Normal display (no highlight)
    // A_STANDOUT      Best highlighting mode of the terminal.
    // A_UNDERLINE     Underlining
    // A_REVERSE       Reverse video
    // A_BLINK         Blinking
    // A_DIM           Half bright
    // A_BOLD          Extra bright or bold
    // A_PROTECT       Protected mode
    // A_INVIS         Invisible or blank mode
    // A_ALTCHARSET    Alternate character set
    // A_CHARTEXT      Bit-mask to extract a character
    // COLOR_PAIR(n)   Color-pair number n
    // beep();
    // flash();
}

void tear_down_ui() {
	endwin(); // exit curses mode
}

void paint_border() {
	// https://en.wikipedia.org/wiki/Box-drawing_character
	attron(COLOR_PAIR(BORDER_COLOR_PAIR));
	for(int i = 0; i < COLS; i++) {
		move(0, i);
		addstr("\u2588");
		move(LINES-1, i);
		addstr("\u2588");
	}
	for(int i = 0; i < LINES; i++) {
		move(i, 0);
		addstr("\u2588");
		move(i, COLS - 1);
		addstr("\u2588");
	}
	attroff(COLOR_PAIR(BORDER_COLOR_PAIR));
}