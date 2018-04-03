#include "stdafx.h"
#include "Aggressive.h"


Aggressive::Aggressive()
{
}


Aggressive::~Aggressive()
{
}

void Aggressive::execute(Map* gameMap, Player* player, string phase, GameLoop* gl, GameDeck* gd)
{
	
	
	if (phase == "Picks Race") {
		srand(time(NULL));
		int x = rand() % 6;
		player->picks_race(gl->pairs[x].first, gl->pairs[x].second, gd);
		cout << "You have chosen: " << gl->pairs[x].second.getBadgeName() << " " << gl->pairs[x].first.getRaceName() << endl;
		gl->pairs.erase(gl->pairs.begin() + x);

		cout << "\nUpdated list of race power combos: " << endl;
		for (int i = 0; i < 6; i++) {
			cout << i << ". " << gl->pairs[i].second.getBadgeName() << " " << gl->pairs[i].first.getRaceName() << endl;
		}
	}
	if (phase == "Conquer Regions" && player->getTokenCount() > 2) {

		for (auto & region : gameMap->regions) {

			(*player).conquers(region, true);
			

		}
	}

	if (phase == "Following Turn" && player->getTokenCount() <= 2) {

		player->decline(gl->pairs[0].first, gl->pairs[0].second, gd);
	}

	else if (phase == "Following Turn" && player->getTokenCount() > 2) {
		for (auto & region : gameMap->regions){
				
					(*player).conquers(region, true);
				
			}
		}
	
}
