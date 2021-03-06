#ifndef GSM_H
#define GSM_H

#include <stack>
#include "state.h"

// overall game state manager
class GSM {
public:
	void pop();
	void push(State* s);
	void set(State* s);
	State* top();
	void render();
	void update(ALLEGRO_KEYBOARD_STATE &ks, ALLEGRO_MOUSE_STATE &ms);
private:
	std::stack<State*> states;
};
#endif