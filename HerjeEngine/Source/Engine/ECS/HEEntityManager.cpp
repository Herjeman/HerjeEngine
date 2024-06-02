#include "HEPreCompiled.h"
#include "HEEntityManager.h"

namespace HerjeEngine
{
	HEEntityManager& HEEntityManager::Get()
	{
		static HEEntityManager entityManager;
		return entityManager;
	}

	Entity& HEEntityManager::CreateEntity()
	{
		if (m_InactiveEntityIndexes.size() > 0)
		{
			Entity& newEntity = m_Entities[m_InactiveEntityIndexes.back()];
			m_InactiveEntityIndexes.pop_back();
			newEntity.Reset();
			newEntity.Signature.SetFlag(static_cast<uint32_t>(EEntitySignature::IsActive));

			return newEntity;
		}

		m_Entities.push_back(Entity(m_HighestActiveEntityID));
		m_Entities.back().Signature.SetFlag(static_cast<uint32_t>(EEntitySignature::IsActive));
		m_HighestActiveEntityID++;

		return m_Entities.back();
	}

	void HEEntityManager::DestroyEntity(int ID)
	{
		bool success = false;
		for (int i = 0; i < m_Entities.size(); i++)
		{
			if (m_Entities[i].ID == ID)
			{
				m_Entities[i].Signature.UnsetFlag(static_cast<uint32_t>(EEntitySignature::IsActive));
				m_InactiveEntityIndexes.push_back(i);
				success = true;
				break;
			}
		}
		HE_CORE_ASSERT(success, "Failed to Destroy Entity: Invalid ID");
	}
	void HEEntityManager::ClearEntities()
	{
		m_InactiveEntityIndexes.clear();
		m_Entities.clear();
		m_HighestActiveEntityID = 0;
	}
}


