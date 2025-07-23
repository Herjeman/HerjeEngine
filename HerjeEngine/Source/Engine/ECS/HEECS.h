#pragma once
#include "HEPrecompiled.h"
#include "Utilities/Vector2.h"

#define ECS_MAXIMUM_ENTITIES 1000
#define ECS_MAXIMUM_COMPONENTS 32
typedef uint32_t Entity;
typedef uint16_t EntityID;

namespace HerjeEngine {

	enum EEntitySignature : Entity
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
		EEntitySignature ComponentSignature = EEntitySignature::UNDEFINED;
	};

	template class HEComponentManager<LocationComponent>;
	template class HEComponentManager<MovementComponent>;

	class ComponentSystem
	{
	public:
		void TryProcess(class HEEntityComponentSystem& ECS, const class Application& application);

	protected:
		virtual void Process(const EntityID entityIndex, class HEEntityComponentSystem& ECS, const class Application& application) = 0;
		bool EntityMatchesSignature(const Entity& Entity) const { return m_EntitySignature == (Entity & m_EntitySignature); }
		Entity m_EntitySignature = EEntitySignature::UNDEFINED;
	};

	class MovementSystem : public ComponentSystem
	{
	public:
		MovementSystem()
		{
			m_EntitySignature = EEntitySignature::IS_ACTIVE | EEntitySignature::LOCATION | EEntitySignature::MOVEMENT;
		}

		void Process(const EntityID entityIndex, class HEEntityComponentSystem& ECS, const class Application& application) override;
	};

	class HEEntityComponentSystem
	{
	public:
		HEEntityComponentSystem()
		{
			// Set up Component Managers
			LocationComponents.ComponentSignature = EEntitySignature::LOCATION;
			MovementComponents.ComponentSignature = EEntitySignature::MOVEMENT;
		}

		HEEntityManager EntityManager = {};
		HEComponentManager<LocationComponent> LocationComponents;
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
			EntityManager.Entities[m_HighestEntityIndex] = EEntitySignature::IS_ACTIVE;

			// Add new Component entries for Entity
			LocationComponents.Components[m_HighestEntityIndex] = {};
			MovementComponents.Components[m_HighestEntityIndex] = {};

			return m_HighestEntityIndex;
		}

		HE_API void DisableEntity(EntityID& ID)
		{
			if (!IsValidEntityIndex(ID))
			{
				return;
			}
			EntityManager.Entities[ID] = EEntitySignature::UNDEFINED;
		}

		void ProcessSystems(const class Application& application)
		{
			m_MovementSystem.TryProcess(*this, application);
		}

		[[nodiscard]] static const bool IsValidEntityIndex(const EntityID& Index)
		{
			// NOTE: Consider using the HighestEntityIndex here, or at least adding a nonstatic option for that
			if (Index < 0 || Index >= ECS_MAXIMUM_ENTITIES)
			{
				HE_CORE_ASSERT((0 <= Index && Index < ECS_MAXIMUM_ENTITIES), "Invalid Entity ID");
				return false;
			}
			return true;
		}

		const EntityID GetCurrentHighestEntityID() const { return m_HighestEntityIndex; }

	private:
		EntityID m_HighestEntityIndex = 0;
		MovementSystem m_MovementSystem;
	};
}

