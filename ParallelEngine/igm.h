#ifndef IGM_H
#define IGM_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "var.h"
#include <string>
#include "player.h"
#include "buttonmanager.h"
#include "menustates.h"
#include "unitbutton.h"
#include "buildinglist.h"
#include <iostream>
#include "assetloader.h"
#include "resources.h"
#include "units.h"

//in-game menu
class IGM {
public:
	IGM(Player * player_, BuildingList* bl, TileMap * tm_);
	// update states
	void update(bool clicked, bool keyClicked, std::string key, int x, int y, BuildingList* bl);
	// render states 
	void staticRender();
	void isoRender();
	// returns current state
	void setState(MenuState state);

	//basic menu types
	void gameBackground();
	void menuBackground();
	void defaultMenu();
	void buildingMenu();
	void diploMenu();
	void overviewMenu();
	void productionMenu();
	void inventoryMenu();
	void buildingInfoBackground();

	// getter methods
	Building* getBuilding() { return newBuilding; }
	Building* getPrevSelectedBuilding() { return prevSelectedBuilding; }

	//setter methods
	void setCol(int col) { currCol = col; }
	void setRow(int row) { currRow = row; }
private:
	MenuState currState, prevState;
	ALLEGRO_FONT* basic_font20 = al_load_font("basicfont.ttf", 20, 0);
	bool isClicked = false;
	ButtonManager* bm, *buildingbm;
	Player* player;
	BuildingList* bl;
	MenuButton *flag, *production, *build, *exit, *exit1, *misc, *rightExit;
	BuildButton *castle, *towncenter, *newBuildingPlaceHolder;
	UnitButton* peasant;
	int buttonIndex;
	Castle* c;
	Towncenter* tc;

	Castle* sampleCastle;
	Towncenter* sampleTC;
	Peasant* samplePeasant;
	Building* newBuilding, *selectedBuilding, *prevSelectedBuilding;

	TileMap* tm;

	int currCol = 0, currRow = 0;
};
#endif