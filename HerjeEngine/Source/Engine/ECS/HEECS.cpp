#include "HEPreCompiled.h"
#include "HEECS.h"
#include "Engine/Rendering/HERenderer2D.h"
#include "Engine/Core/Application.h"

void HerjeEngine::DrawRectangleSystem::Process(const HEEntityComponentSystem& ECS, const Application& application)
{
	auto* renderer = application.GetRenderer();
	auto& Entities = ECS.EntityManager.Entities;
	auto& Locations = ECS.LocationComponents.Components;
	auto& Rectangles = ECS.RectangleComponents.Components;

	for (size_t i = 0; i < ECS_MAXIMUM_ENTITIES; i++)
	{
		const auto& Entity = Entities[i];
		if (!EntityMatchesSignature(Entity))
		{
			continue;
		}
		const Vector2& Location = Locations[i].Location;
		const Vector2& Size = Rectangles[i].Size;
		renderer->RenderSquare(Location, Size);
	}
}
