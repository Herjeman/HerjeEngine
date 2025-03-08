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
		UNDEFINED = 0,
		IS_ACTIVE = 1 << 0,
		LOCATION = 1 << 1,
		RECTANGLE = 1 << 2,
		MOVEMENT = 1 << 3
	};

	struct HE_API LocationComponent
	{
		Vector2 Location;
	};

	struct HE_API RectangleComponent
	{
		Vector2 Size;
	};

	struct HE_API MovementComponent
	{
		Vector2 Velocity;
	};

	class HEEntityManager
	{
	public:
		std::array<Entity, ECS_MAXIMUM_ENTITIES> Entities;
	};

	template <typename ComponentType>
	class HEComponentManager
	{
	public:
		HE_API void SetComponentForEntity(const EntityID& ID, const ComponentType& NewComponent, HEEntityManager& EntityManager)
		{
			if (!HEEntityComponentSystem::IsValidEntityIndex(ID))
			{
				return;
			}

			Components[ID] = NewComponent;
			EntityManager.Entities[ID] |= ComponentSignature;
		}
		HE_API ComponentType* GetComponentForEntity(const EntityID& ID)
		{
			if (!HEEntityComponentSystem::IsValidEntityIndex(ID))
			{
				return nullptr;
			}
			return &Components[ID];
		}
		std::array<ComponentType, ECS_MAXIMUM_ENTITIES> Components;
		EntitySignature ComponentSignature = EntitySignature::UNDEFINED;
	};

	template class HEComponentManager<LocationComponent>;
	template class HEComponentManager<RectangleComponent>;
	template class HEComponentManager<MovementComponent>;

	class ComponentSystem
	{
	public:
		void TryProcess(class HEEntityComponentSystem& ECS, const class Application& application);

	protected:
		virtual void Process(const size_t entityIndex, class HEEntityComponentSystem& ECS, const class Application& application) = 0;
		bool EntityMatchesSignature(const Entity& Entity) const { return m_EntitySignature == (Entity & m_EntitySignature); }
		Entity m_EntitySignature = EntitySignature::UNDEFINED;
	};

	class DrawRectangleSystem : public ComponentSystem
	{
	public:
		DrawRectangleSystem()
		{
			m_EntitySignature = EntitySignature::IS_ACTIVE | EntitySignature::LOCATION | EntitySignature::RECTANGLE;
		}

		void Process(const size_t entityIndex, class HEEntityComponentSystem& ECS, const class Application& application) override;
	};

	class MovementSystem : public ComponentSystem
	{
	public:
		MovementSystem()
		{
			m_EntitySignature = EntitySignature::IS_ACTIVE | EntitySignature::LOCATION | EntitySignature::MOVEMENT;
		}

		void Process(const size_t entityIndex, class HEEntityComponentSystem& ECS, const class Application& application) override;
	};

	class HEEntityComponentSystem
	{
	public:
		HEEntityComponentSystem()
		{
			// Set up Component Managers
			LocationComponents.ComponentSignature = EntitySignature::LOCATION;
			RectangleComponents.ComponentSignature = EntitySignature::RECTANGLE;
			MovementComponents.ComponentSignature = EntitySignature::MOVEMENT;
		}

		HEEntityManager EntityManager = {};
		HEComponentManager<LocationComponent> LocationComponents;
		HEComponentManager<RectangleComponent> RectangleComponents;
		HEComponentManager<MovementComponent> MovementComponents;

	public:
		HE_API const EntityID AddEntity()
		{
			// Add new Entity
			m_HighestEntityIndex++;
			if (m_HighestEntityIndex >= ECS_MAXIMUM_ENTITIES)
			{
				HE_LOG_CORE_ERROR("ECS Entity Limit reached, rolling over");
				HE_CORE_ASSERT(m_HighestEntityIndex <= ECS_MAXIMUM_ENTITIES, "ECS Entity limit reached");
				m_HighestEntityIndex = 0;
			}
			EntityManager.Entities[m_HighestEntityIndex] = EntitySignature::IS_ACTIVE;

			// Add new Component entries for Entity
			LocationComponents.Components[m_HighestEntityIndex] = {};
			RectangleComponents.Components[m_HighestEntityIndex] = {};
			MovementComponents.Components[m_HighestEntityIndex] = {};

			return m_HighestEntityIndex;
		}

		HE_API void DisableEntity(EntityID& ID)
		{
			if (!IsValidEntityIndex(ID))
			{
				return;
			}
			EntityManager.Entities[ID] = EntitySignature::UNDEFINED;
		}

		void ProcessSystems(const class Application& application)
		{
			m_RectangleSystem.TryProcess(*this, application);
			m_MovementSystem.TryProcess(*this, application);
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
		MovementSystem m_MovementSystem;
	};
}

