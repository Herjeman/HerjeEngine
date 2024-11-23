#include "HEPreCompiled.h"
#include "HEComponentManager.h"
#include "HEEntityComponentSystem.h"
#include "HEEntityManager.h"

namespace HerjeEngine
{
	Entity& HEEntityManager::GetEntityChecked(int index)
	{
		HE_CORE_ASSERT(m_Entities.size() && m_Entities.size() > index, "Get Entity Index is out of range");
		return m_Entities[index];
	}

	size_t HEEntityManager::CreateEntity(uint64_t signature, bool& createdNew)
	{
		if (m_InactiveEntityIndexes.size() > 0)
		{
			int index = m_InactiveEntityIndexes.back();
			Entity& newEntity = m_Entities[index];
			m_InactiveEntityIndexes.pop_back();
			BitFlag::SetFlags(newEntity.Signature, signature |= 1);
			createdNew = false;

			return index;
		}

		m_Entities.push_back(Entity());
		BitFlag::SetFlags(m_Entities.back().Signature, static_cast<uint64_t>(EEntitySignature::IsActive));
		createdNew = true;

		return m_Entities.size() - 1;
	}

	void HEEntityManager::DeactivateEntity(int index)
	{
		HE_CORE_ASSERT(m_Entities.size() && m_Entities.size() > index, "Failed to Destroy Entity: Invalid ID");
		m_Entities[index].Reset();
		m_InactiveEntityIndexes.push_back(index);

	}
	void HEEntityManager::ClearEntities()
	{
		m_InactiveEntityIndexes.clear();
		m_Entities.clear();
	}
}


