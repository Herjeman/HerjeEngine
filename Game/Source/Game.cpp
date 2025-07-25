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

static void GetRandomVectors(const HerjeEngine::Vector2& min, const HerjeEngine::Vector2& max, int count, std::vector<HerjeEngine::Vector2>& out)
{
	std::random_device random;
	std::mt19937 generator(random());

	std::uniform_real_distribution<> xDistribution(min.X, max.X);
	std::uniform_real_distribution<> yDistribution(min.Y, max.Y);

	for (size_t i = 0; i < count; i++)
	{
		out.push_back({ static_cast<float>(xDistribution(generator)), static_cast<float>(yDistribution(generator)) });
	}
}

static constexpr int NUMBER_OF_ENTITIES = 10000;

class Game : public HerjeEngine::Application
{
public:
	Game() {}
	~Game() {}

	std::vector<HerjeEngine::Vector2> m_Locations;
	std::vector<HerjeEngine::Vector2> m_Sizes;
	std::vector<HerjeEngine::Vector2> m_Velocities;

	void PreLoop() override
	{
		constexpr float VELOCITY_MAX = 10;
		const HerjeEngine::Vector2 size_min(1, 1);
		const HerjeEngine::Vector2 size_max(5, 5);

		auto* window = GetWindow();

		GetRandomVectors({ 0, 0 }, window->GetDimensions(), NUMBER_OF_ENTITIES, m_Locations);
		GetRandomVectors(size_min, size_max, NUMBER_OF_ENTITIES, m_Sizes);
		GetRandomVectors({ -VELOCITY_MAX, -VELOCITY_MAX }, { VELOCITY_MAX, VELOCITY_MAX }, NUMBER_OF_ENTITIES, m_Velocities);
	}

	void Update(float deltaTime) override
	{
		for (size_t i = 0; i < NUMBER_OF_ENTITIES; i++)
		{
			m_Locations[i] += m_Velocities[i] * deltaTime;
		}
	}

	void Draw() override
	{
		auto* rectangleRenderer = GetRenderer();
		std::vector<HerjeEngine::HERect> rectsToRender;
		rectsToRender.reserve(NUMBER_OF_ENTITIES);

		for (size_t i = 0; i < NUMBER_OF_ENTITIES; i++)
		{
			rectsToRender.push_back({ m_Locations[i], m_Sizes[i] });
		}

		rectangleRenderer->RenderRectangles(rectsToRender);
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