#pragma once
#include "Component.h"
#include "../Utillities/Vector2.h"

namespace ArksEngine
{
	class Core;
	class Texture;
}

namespace ArksEngineComponents
{
	class PhysicsComponent;
	class TransformComponent;

	class SpriteComponent : public Component
	{
		ArksEngine::Texture* m_pTexture;
		ArksEngineComponents::TransformComponent* m_pTransform;
		ArksEngineComponents::PhysicsComponent* m_pPhysics;
		ArksEngine::Core* m_pRenderer;
		const char* m_pPath;
		Vector2<float> mSource;

		// Animation
		bool mAnimated = false;
		int mFrames = 0;
		int mSpeed = 100; // Delay between frames in mili sec
	public:

		SpriteComponent() = default;
		SpriteComponent(ArksEngine::Core* pRenderer, const char* path);
		SpriteComponent(ArksEngine::Core* pRenderer, const char* path, int numOfFrames, int speed);

		void Init() override;

		void Update(double deltaTime) override;

		void Render(float xOffset) override;
	private:
		void AnimationManager();
	};
}


