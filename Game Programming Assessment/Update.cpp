#include "Update.h"

#include <iostream>

//Gives objects starting positions 
Update::Update(int windowHeight, int windowWidth, Player* playerPtr) {
	windowHeight_ = windowHeight;
	windowWidth_ = windowWidth;
	playerPtr_ = playerPtr;
	}


void Update::getUpdate() {

	//If objects movement is allowed, execute it
	checkPlayerInMap();

	playerPtr_->Update();

}

void Update::checkPlayerInMap() {
	//Check for player valid movement
	int playerWASD[4];
	int playerXYWH[4];
	int playerSpeed = 0;
	playerPtr_->getPlayerMovement(playerWASD);
	playerPtr_->getPlayerPosition(playerXYWH);
	playerPtr_->getPlayerSpeed(playerSpeed);

	int correctedPlayerWASD[4] = { playerWASD[0],playerWASD[1],playerWASD[2],playerWASD[3] };

	//Checks if player goes off the left of the screen, reset movement amount so they only move as far as the side
	if (playerXYWH[0] - (playerWASD[1] * playerSpeed) < 0) {
		//If the player hasn't yet reached the egde of the screen, move them until they touch the edge of the screen
		if (playerXYWH[0] > 0) {
			playerPtr_->setPlayerPosition(0, playerXYWH[1]);
		}
		//Player does not move
		correctedPlayerWASD[1] = 0;
		correctedPlayerWASD[3] = 0; //This is also reset to prevent player pinging backwards and forwards on the egde of the screen when both movement buttons are pressed

	}

	//Checks if player goes off the top of the screen, reset movement amount so they only move as far as the side

	if (playerXYWH[1] - (playerWASD[0] * playerSpeed) < 0) {
		//If the player hasn't yet reached the egde of the screen, manually set coordinates so they move until they touch the edge of the screen
		if (playerXYWH[1] > 0) {
			playerPtr_->setPlayerPosition(playerXYWH[0], 0);
		}

		//Player does not move
		correctedPlayerWASD[0] = 0;
		correctedPlayerWASD[2] = 0; //This is also reset to prevent player pinging backwards and forwards on the egde of the screen when both movement buttons are pressed

	}

	//Checks if player goes off the right of the screen, reset movement amount so they only move as far as the side
	if (playerXYWH[0] + playerXYWH[2] + (playerWASD[3] * playerSpeed) > windowWidth_) {
		//If the player hasn't yet reached the egde of the screen, move them until they touch the edge of the screen
		if (playerXYWH[0] + playerXYWH[2] < windowWidth_) {
			playerPtr_->setPlayerPosition(windowWidth_ - playerXYWH[2], playerXYWH[1]);
		}

		//Player does not move
		correctedPlayerWASD[1] = 0;
		correctedPlayerWASD[3] = 0; //This is also reset to prevent player pinging backwards and forwards on the egde of the screen when both movement buttons are pressed

	}

	//Checks if player goes off the bottom of the screen, reset movement amount so they only move as far as the side
	if (playerXYWH[1] + playerXYWH[3] + (playerWASD[2] * playerSpeed) > windowHeight_) {
		//If the player hasn't yet reached the egde of the screen, move them until they touch the edge of the screen
		if (playerXYWH[1] + playerXYWH[3] < windowHeight_) {
			playerPtr_->setPlayerPosition(playerXYWH[0], windowHeight_ - playerXYWH[3]);
		}
		//Player doesn't move
		correctedPlayerWASD[0] = 0;
		correctedPlayerWASD[2] = 0; //This is also reset to prevent player pinging backwards and forwards on the egde of the screen when both movement buttons are pressed

	}
	//Any changes to movement will now be reflected
	playerPtr_->setPlayerMovement(correctedPlayerWASD);
}