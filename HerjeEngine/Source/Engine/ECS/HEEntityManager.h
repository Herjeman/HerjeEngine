#pragma once

#include "Utilities/BitFlag.h"

namespace HerjeEngine
{
	enum class EEntitySignature : uint32_t
	{
		IsActive = 1 << 0
	};

	struct Entity
	{
		Entity(int id) : ID(id) {}
		void Reset() { Signature.UnsetAll(); }
		int ID;
		BitFlag<uint32_t> Signature;
	};

	class HEEntityManager
	{
	public:
		HEEntityManager(const HEEntityManager& obj) = delete;
		HEEntityManager& operator=(const HEEntityManager&) = delete;

		static HEEntityManager& Get();
		std::vector<Entity>& GetEntities() { return m_Entities; }

		Entity& CreateEntity();
		void DestroyEntity(int ID);

		void ClearEntities();

	private:
		HEEntityManager() {}
		~HEEntityManager() {}

		int m_HighestActiveEntityID = 0;
		std::vector<int> m_InactiveEntityIndexes;
		std::vector<Entity> m_Entities;
	};
}

