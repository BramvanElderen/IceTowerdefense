#include "GameManager.h"
#include "EventReciever.h"

#include <irrlicht.h>
#include <time.h>


int main (int argc, char* argv[])
{
	srand(time(0)); //For random generators
	GameManager* gameManager = new GameManager();
	irr::IrrlichtDevice* device = gameManager->GetDevice();
	EventReciever* eventReciever = new EventReciever(device,(GameManagerInterface*)gameManager);
	device->setEventReceiver(eventReciever);
	gameManager->Start();
	return 0;
}