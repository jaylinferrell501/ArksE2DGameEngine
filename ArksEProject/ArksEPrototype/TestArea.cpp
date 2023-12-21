#include "TestArea.h"

#include <cassert>
#include <iostream>

#include "ArksEngine.h"
#include "../ArksEngine/TestLuaFunctions.h"

GameScene::TestArea::TestArea(ArksEnginePrototypeApp::PrototypeGame* pOwner)
	:Scene(pOwner)
{
}

void GameScene::TestArea::Enter()
{
	GetOwner()->GetDebug_Log()->Log("Enter scene");

	//----------------------------- Testing Out Level Class --------------------------------------------------------------

	auto screenHeight = static_cast<float>(GetOwner()->GetWindow()->GetScreenHeight());
	auto screenWidth = static_cast<float>(GetOwner()->GetWindow()->GetScreenWidth());

	auto hall = new ArksEngine::Texture(GetOwner(), "Assets/Hall.png");
	auto hallCollisionMap = new ArksEngine::Texture(GetOwner(), "Assets/HallCollisionMap.png");

	Level()->LoadLevel(hall, hallCollisionMap, 2560, screenHeight);

	//----------------------------- Testing Out Level Class --------------------------------------------------------------

	LoadEntity("Xml_Files/PlayerCharacter.xml");
	LoadEntity("Xml_Files/Enemy.xml");

	SetSceneMusic("Assets/dark.mp3", 100, 0);

	TestLuaFunctions test(GetOwner()->GetLuaSystem());

	test.TestLua();
}


// Cleans up and Exits our scene
void GameScene::TestArea::Exit()
{
	GetSceneMusic()->Stop_Music(); // ALWAYS STOP MUSIC BEFORE EXITING A SCENE!!!!!!!
	GetEntityManager()->Clear();
	GetOwner()->GetDebug_Log()->Log("Exit scene");

}
