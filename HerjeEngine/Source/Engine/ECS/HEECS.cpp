#include "HEPreCompiled.h"
#include "HEECS.h"
#include "Engine/Rendering/HERenderer2D.h"
#include "Engine/Core/Application.h"

void HerjeEngine::ComponentSystem::TryProcess(HEEntityComponentSystem& ECS, const Application& application)
{
	for (EntityID entityIndex = 0; entityIndex <= ECS.GetCurrentHighestEntityID(); entityIndex++)
	{
		const auto& entity = ECS.EntityManager.Entities[entityIndex];
		if (!EntityMatchesSignature(entity))
		{
			continue;
		}
		Process(entityIndex, ECS, application);
	}
}

void HerjeEngine::DrawRectangleSystem::Process(const EntityID entityIndex, HEEntityComponentSystem& ECS, const Application& application)
{
	const Vector2& location = ECS.LocationComponents.Components[entityIndex].Location;
	const Vector2& size = ECS.RectangleComponents.Components[entityIndex].Size;
	application.GetRenderer()->RenderSquare(location, size);
}

void HerjeEngine::MovementSystem::Process(const EntityID entityIndex, HEEntityComponentSystem& ECS, const Application& application)
{
	Vector2& location = ECS.LocationComponents.Components[entityIndex].Location;
	Vector2& velocity = ECS.MovementComponents.Components[entityIndex].Velocity;
	location += velocity * application.GetDeltaTime();
}
