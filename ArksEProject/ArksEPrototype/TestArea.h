#pragma once
#include <vector>
#include "../ArksEngine/Interfaces/Scene.h"
#include "../ArksEngine/Texture.h"
#include "PrototypeGame.h"


class Controller;
struct SDL_Rect;

namespace GameScene
{
	class TestArea : public ArksEngine::Scene
	{
	public:
		TestArea(ArksEnginePrototypeApp::PrototypeGame* pOwner);
		~TestArea() = default;



		/**
		 * \brief Enters our scene
		 */
		void Enter() override;


		/**
		 * \brief Exits our scene
		 */
		void Exit() override;

	};
}


