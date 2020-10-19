#include "food.h"

vector<pair<int, int>> nibbles;

pair<int, int> make_food() {
	return make_pair(experimental::randint(1, LINES-2), experimental::randint(1, COLS-2));
}

void paint_food() {
	attron(COLOR_PAIR(FOOD_COLOR_PAIR));
	for(int i = 0; i < nibbles.size(); i++) {
		move(nibbles[i].first, nibbles[i].second);
		addstr("$");
	}
	attroff(COLOR_PAIR(FOOD_COLOR_PAIR));
}

void init_food() {
	nibbles.clear();
	for(int i = 0; i < FOOD_COUNT; i++) {
		nibbles.push_back(make_food());
	}
}

bool consume_food(int x, int y) {
	for(int i = 0; i < FOOD_COUNT; i++) {
		if(x == nibbles[i].first && y == nibbles[i].second) {
			// consume the food at snake's head
			nibbles.erase(nibbles.begin() + i);
			// create new food
			nibbles.push_back(make_food());
			return true;
		}
	}
	return false;
}