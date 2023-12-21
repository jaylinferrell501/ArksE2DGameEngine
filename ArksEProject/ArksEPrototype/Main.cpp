// Main Source
// Jaylin Ferrell

#include "PrototypeGame.h"
#include "../ArksEngine/Core.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////
///This is the Main Cpp for the ArksEngine prototype Game. This game will show the full capabilities
///Of my Game engine.
//////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	
	ArksEnginePrototypeApp::PrototypeGame prototypeGame;

	prototypeGame.InitializeApp("PrototypeGameTest", "../Assets.zip", 960, 480);

	prototypeGame.RunEngine();

	prototypeGame.De_initialize();

	return 0;
}

