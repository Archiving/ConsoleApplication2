#include "player.h"

// add resource items from entities standing on resource tiles on the map.
void Player::updateInventory() {
	for (Entity * e : entities) {
		if (e->getTileType() == TileMap::RESOURCE) {
			const Resource* tileResource = WHEAT;
			switch (e->getTileID()) {
			case 6: //rice
				tileResource = RICE;
				break;
			case 7: //chicken
				tileResource = CHICKEN;
				break;
			case 8: //mutton
				tileResource = MUTTON;
				break;
			case 9: //light_wood
				tileResource = LIGHT_WOOD;
				break;
			case 10: //heavy_wood
				tileResource = HEAVY_WOOD;
				break;
			case 11: //light_gold_ore
				tileResource = LIGHT_GOLD_ORE;
				break;
			case 12: //heavy_gold_ore
				tileResource = HEAVY_GOLD_ORE;
				break;
			case 13: //light_stone_ore
				tileResource = LIGHT_STONE_ORE;
				break;
			case 14: //heavy_stone_ore
				tileResource = HEAVY_STONE_ORE;
				break;
			case 15: //wool
				tileResource = WOOL;
				break;
			case 16: //iron_ore
				tileResource = IRON_ORE;
				break;
			}
			inventory->addResource(tileResource);
		}
	}
}

bool Player::buyBuilding(Building* building) {
	int foodCost = building->getFoodCost();
	int stoneCost = building->getStoneCost();
	int woodCost = building->getWoodCost();
	int goldCost = building->getGoldCost();

	bool success = false;

	if (building->requiresItems() && inventory->hasItems()) {
		for (auto req : building->getRequiredItems()) {
			if (inventory->hasItem(req.first->getName())) {
				try {
					inventory->removeResource(req.first, req.second);
				}
				catch (char* e) {
					std::cout << e << std::endl;
				}
			}
		}
	}

	try {
		if (foodCost != 0) inventory->removeResource(FOOD, foodCost);
		if (stoneCost != 0) inventory->removeResource(STONE, stoneCost);
		if (woodCost != 0) inventory->removeResource(WOOD, woodCost);
		if (goldCost != 0) inventory->removeResource(GOLD, goldCost);
		success = true;
	}
	catch (char* e) {
		std::cout << e << std::endl;
	}

	return success;
}