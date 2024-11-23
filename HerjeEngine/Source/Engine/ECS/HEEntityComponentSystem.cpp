#include "HEPreCompiled.h"
#include "HEEntityComponentSystem.h"

namespace HerjeEngine
{
	HEEntityComponentSystem::HEEntityComponentSystem()
	{
		RegisterComponent<TransformComponent>();
		RegisterComponent<VelocityComponent>();

		HE_LOG_CORE_INFO("ECS Initialised");
	}

	HEEntityComponentSystem::~HEEntityComponentSystem()
	{
		HE_LOG_CORE_INFO("ECS Shutdown");
	}

	HEEntityComponentSystem& HEEntityComponentSystem::Get()
	{
		static HEEntityComponentSystem ECS;
		return ECS;
	}

	size_t HEEntityComponentSystem::AddEntity(uint64_t signature)
	{
		bool createdNew;
		size_t entityID = m_EntityManager.CreateEntity(signature, createdNew);
		if (createdNew)
		{
			m_ComponentManager.AddComponentsForNewEntity();
		}
		else
		{
			m_ComponentManager.ResetComponentsForEntity(entityID);
		}

		return entityID;
	}

	void HEEntityComponentSystem::DeactivateEntity(size_t id)
	{
		m_EntityManager.DeactivateEntity(id);
		m_ComponentManager.ResetComponentsForEntity(id);
	}
}
