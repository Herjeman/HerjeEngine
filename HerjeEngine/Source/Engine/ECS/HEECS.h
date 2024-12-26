#pragma once
#include "HEPrecompiled.h"
#include "Utilities/Vector2.h"

#define ECS_MAXIMUM_ENTITIES 1000
#define ECS_MAXIMUM_COMPONENTS 32
typedef uint32_t Entity;
typedef uint16_t EntityID;

namespace HerjeEngine {

	enum EntitySignature : Entity
	{
		UNDEFINED,
		IS_ACTIVE,
		LOCATION,
		RECTANGLE
	};

	struct HE_API LocationComponent
	{
		Vector2 Location;
	};

	struct HE_API RectangleComponent
	{
		Vector2 Size;
	};

	class HE_API HEEntityManager
	{
	public:
		std::array<Entity, ECS_MAXIMUM_ENTITIES> Entities;
	};

	template <typename ComponentType>
	class HE_API HEComponentManager
	{
	public:
		void SetComponent(const EntityID& ID, const ComponentType& NewComponent, HEEntityManager& EntityManager)
		{
			if (!HEEntityComponentSystem::IsValidEntityIndex(ID))
			{
				return;
			}

			Components[ID] = NewComponent;
			EntityManager.Entities[ID] |= ComponentSignature;
		}
		std::array<ComponentType, ECS_MAXIMUM_ENTITIES> Components;
		EntitySignature ComponentSignature = EntitySignature::UNDEFINED;
	};

	template class HE_API HEComponentManager<LocationComponent>;
	template class HE_API HEComponentManager<RectangleComponent>;

	class DrawRectangleSystem
	{
	public:
		void Process(const class HEEntityComponentSystem& ECS, const class Application& application);

	private:
		bool EntityMatchesSignature(const Entity& Entity) const { return m_EntitySignature == (Entity & m_EntitySignature); }
		Entity m_EntitySignature = EntitySignature::IS_ACTIVE | EntitySignature::LOCATION | EntitySignature::RECTANGLE;
	};

	class HE_API HEEntityComponentSystem
	{
	public:
		HEEntityComponentSystem()
		{
			LocationComponents.ComponentSignature = EntitySignature::LOCATION;
			RectangleComponents.ComponentSignature = EntitySignature::RECTANGLE;
		}

		HEEntityManager EntityManager = {};
		HEComponentManager<LocationComponent> LocationComponents;
		HEComponentManager<RectangleComponent> RectangleComponents;

	public:
		const EntityID AddEntity()
		{
			m_HighestEntityIndex++;
			if (m_HighestEntityIndex >= ECS_MAXIMUM_ENTITIES)
			{
				HE_LOG_CORE_ERROR("ECS Entity Limit reached, rolling over");
				HE_CORE_ASSERT(m_HighestEntityIndex <= ECS_MAXIMUM_ENTITIES, "ECS Entity limit reached");
				m_HighestEntityIndex = 0;
			}
			EntityManager.Entities[m_HighestEntityIndex] = EntitySignature::IS_ACTIVE;
			LocationComponents.Components[m_HighestEntityIndex] = {};
			RectangleComponents.Components[m_HighestEntityIndex] = {};

			return m_HighestEntityIndex;
		}

		void DisableEntity(EntityID& ID)
		{
			if (!IsValidEntityIndex(ID))
			{
				return;
			}
			EntityManager.Entities[ID] = EntitySignature::UNDEFINED;
		}

		void ProcessSystems(const class Application& application)
		{
			m_RectangleSystem.Process(*this, application);
		}

		[[nodiscard]] static const bool IsValidEntityIndex(const EntityID& Index)
		{
			if (Index < 0 || Index >= ECS_MAXIMUM_ENTITIES)
			{
				HE_CORE_ASSERT((0 <= Index && Index < ECS_MAXIMUM_ENTITIES), "Invalid Entity ID");
				return false;
			}
			return true;
		}

	private:
		EntityID m_HighestEntityIndex = 0;
		DrawRectangleSystem m_RectangleSystem;
	};
}

