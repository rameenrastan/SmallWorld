#include "stdafx.h"
#include "Moderate.h"


Moderate::Moderate()
{
}


Moderate::~Moderate()
{
}

void Moderate::execute(Map * gameMap, Player * player, string phase, GameLoop * gl, GameDeck * gd)
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


			if ((*region).isOwned() && player->getTokenCount() > 5) {

				(*player).conquers(region, true);

			}
			else if (player->getTokenCount() > 3) {
				(*player).conquers(region, true);
			}
		}
	}


	if (phase == "Following Turn" && player->getTokenCount() <= 3) {

		player->decline(gl->pairs[0].first, gl->pairs[0].second, gd);
	}

	else if (phase == "Following Turn" && player->getTokenCount() > 3) {
		
		for (auto & region : gameMap->regions) {

			if ((*region).isOwned() && player->getTokenCount() > 5) {

				(*player).conquers(region, true);

			}
			else if (player->getTokenCount() > 4) {
				(*player).conquers(region, true);
			}
		}
	}
}
