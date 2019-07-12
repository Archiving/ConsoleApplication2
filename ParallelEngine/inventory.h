#ifndef INVENTORY_H
#define INVENTORY_H
#include "resources.h"
#include <map>
#include <vector>

class Inventory {
public:
	Inventory(int f, int g, int w, int s) : food(f), gold(g), wood(w), stone(s) {}
	void addResource(const Resource * res);
	void removeResource(ResourceType res, int quantity);
	void removeResource(const Resource * res, int quantity);

	int getFood() const { return food; }
	int getGold() const { return gold; }
	int getWood() const { return wood; }
	int getStone() const { return stone; }

	bool hasItems() { return inventory.empty(); }
	bool hasItem(std::string key) { return !(inventory[key].empty()); } //if not empty, inventory has item

private:
	std::map<std::string, std::vector<const Resource*>> inventory;
	int food;
	int gold;
	int wood;
	int stone;
};


#endif