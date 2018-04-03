#include "stdafx.h"
#include "Random.h"


Random::Random()
{
}


Random::~Random()
{
}

void Random::execute(Map * gameMap, Player * player, string phase, GameLoop * gl, GameDeck * gd)
{
	
		if (phase == "Picks Race") {
			
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
			
			int x = rand() % 3;

			for (auto & region : gameMap->regions) {


				if (x == 0 && region->isOwned()) {

					(*player).conquers(region, true);

				}
				else if (x == 1 && region->hasLostTribe()) {
					(*player).conquers(region, true);
				}
				else if (x == 2 && region->hasMountain()) {
					(*player).conquers(region, true);
				}
				else {
					(*player).conquers(region, true);
					break;
				}
			}
		}

		
		int x = rand() % 2;

		if (phase == "Following Turn") {

			if (x == 0) {
				player->decline(gl->pairs[0].first, gl->pairs[0].second, gd);
			}


			else {
				
				int x = rand() % 3;
				for (auto & region : gameMap->regions) {

					if (x == 0 && region->isOwned()) {

						(*player).conquers(region, true);

					}
					else if (x == 1 && region->hasLostTribe()) {
						(*player).conquers(region, true);
					}
					else if (x == 2 && region->hasMountain()) {
						(*player).conquers(region, true);
					}
					else {
						(*player).conquers(region, true);
						break;
					}
				}
			}
		}
}
