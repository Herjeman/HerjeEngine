#include "HEPreCompiled.h"
#include "HEComponentManager.h"

namespace HerjeEngine
{
	HEComponentManager::HEComponentManager()
	{
		m_ComponentLists = new ComponentList * [m_MaxComponents];
	}

	HEComponentManager::~HEComponentManager()
	{
		for (size_t i = 0; i < m_RegisteredComponents; i++)
		{
			delete m_ComponentLists[i];
		}
	}

	const ComponentList* HEComponentManager::GetComponentList(const uint64_t componentSignature) const
	{
		if (m_ComponentListIndexes.find(componentSignature) == m_ComponentListIndexes.end())
		{
			HE_CORE_ASSERT(false, "Invalid Component Signature");
			return nullptr;
		}
		return m_ComponentLists[m_ComponentListIndexes.at(componentSignature)];
	}

	void HEComponentManager::AddComponentsForNewEntity()
	{
		for (size_t i = 0; i < m_RegisteredComponents; i++)
		{
			HE_CORE_ASSERT(m_ComponentLists[i], "No Registered ComponentList to add to!");
			m_ComponentLists[i]->AddComponent();
		}
	}

	void HEComponentManager::ResetComponentsForEntity(size_t index)
	{
		for (size_t i = 0; i < m_RegisteredComponents; i++)
		{
			HE_CORE_ASSERT(m_ComponentLists[i], "No Registered ComponentList to reset component in!");
			m_ComponentLists[i]->ResetComponent(index);
		}
	}
}

