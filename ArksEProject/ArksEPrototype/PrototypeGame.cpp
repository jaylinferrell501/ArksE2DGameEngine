#include "PrototypeGame.h"

#include <iostream>

#include "TestArea.h"
#include "../ArksEngine/SceneManager.h"
#include "../ArksEngine/Window.h"
#include "../ArksEngine/Utillities/Zipper.h"

ArksEnginePrototypeApp::PrototypeGame::PrototypeGame()
= default;

ArksEnginePrototypeApp::PrototypeGame::~PrototypeGame()
= default;

/**
 * \brief This Function Creates a window, giving it a name, width and height.
 *
 * \param name Name of the window.
 * \param width Width of window.
 * \param height Height of window 
 */
void ArksEnginePrototypeApp::PrototypeGame::InitializeApp(const char* name, const char* assetsFileName, int screenWidth, int screenHeight)
{
	ArksEngine_Initialize(name, assetsFileName, screenWidth, screenHeight); // Initialize The engine

	LoadScene(Test); // Loads out TestScene
}


/**
 * \brief Just a update function
 * \param deltaTime Keeps track of time since last frame
 */
void ArksEnginePrototypeApp::PrototypeGame::Update(double deltaTime)
{
	GetSceneManager()->UpdateCurrentScene(deltaTime);
}

/**
 * \brief Displays the current output
 */
void ArksEnginePrototypeApp::PrototypeGame::DisplayOutput()
{
	if (!GetQuit())
		GetSceneManager()->RenderCurrentScene();
}

/**
 * \brief This function loads current scene
 * \param scene A scene in the game
 */
void ArksEnginePrototypeApp::PrototypeGame::LoadScene(SceneName scene)
{
	switch (scene)
	{
	case Test:
		GetSceneManager()->ChangeScene(new GameScene::TestArea{this});
		break;
	}
}
