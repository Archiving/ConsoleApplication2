#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "state.h"
#include "entity.h"
#include "player.h"
#include "tilemap.h"

class PlayState : public State {
public:
	PlayState(GSM * gsm);
	~PlayState();
	void render() override;
	void update(ALLEGRO_KEYBOARD_STATE & ks) override;
private:
	Player * player;
	TileMap * tm;
};

#endif
