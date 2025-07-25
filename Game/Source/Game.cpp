#include <HerjeEngine.h>
#include <Engine/ECS/HEECS.h>
#include <Engine/Rendering/HERenderer2D.h>
#include <Utilities/Vector2.h>
#include <Engine/Input/InputSystem.h>
#include <Engine/Input/HEKeycodes.h>
#include <Engine/Core/HEWindow.h>

#include <random>

static void AddRenderables(HerjeEngine::HERenderer2D& rectangleRenderer, const HerjeEngine::HEWindow& window)
{
	const HerjeEngine::Vector2 windowDimensions = window.GetDimensions();
	const HerjeEngine::Vector2 minSize = { 1, 1 };
	const HerjeEngine::Vector2 maxSize = { 5, 5 };

	std::random_device random;
	std::mt19937 generator(random());

	std::uniform_real_distribution<> xDistribution(0, windowDimensions.X);
	std::uniform_real_distribution<> yDistribution(0, windowDimensions.Y);
	std::uniform_real_distribution<> sizeXDistribution(minSize.X, maxSize.X);
	std::uniform_real_distribution<> sizeYDistribution(minSize.Y, maxSize.Y);

	for (size_t i = 0; i <= 5000; i++)
	{
		HerjeEngine::RenderRectangleComponent rect{};
		rect.xPos = static_cast<float>(xDistribution(generator));
		rect.yPos = static_cast<float>(yDistribution(generator));
		rect.Width = static_cast<float>(sizeXDistribution(generator));
		rect.Height = rect.Width;
		rectangleRenderer.AddRectangle(i, rect);
	}
}

class Game : public HerjeEngine::Application
{
public:
	Game() {}
	~Game() {}

	void PreLoop() override
	{
		auto* rectangleRenderer = GetRenderer();
		auto* window = GetWindow();

		if (rectangleRenderer == nullptr || window == nullptr)
		{
			HE_ASSERT(false, "No valid stuff wtf?");
			return;
		}

		AddRenderables(*rectangleRenderer, *window);

	}

	void Update(float deltaTime) override
	{
	}

	void Clean() override
	{
	}

private:


};

HerjeEngine::Application* HerjeEngine::CreateApplication()
{
	return new Game();
}