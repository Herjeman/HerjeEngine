#pragma once

#include "Utilities/BitFlag.h"

namespace HerjeEngine
{
	struct Entity
	{
		// Set signature in constructor?
		Entity(){}
		void Reset() { Signature = 0; }
		uint64_t Signature = 0;
	};

	class HEEntityManager
	{
	public:
		HEEntityManager() {}
		~HEEntityManager() {}

		HEEntityManager(const HEEntityManager& obj) = delete;
		HEEntityManager& operator=(const HEEntityManager&) = delete;


		std::vector<Entity>& GetEntities() { return m_Entities; }
		Entity& GetEntityChecked(int index);

		size_t CreateEntity(uint64_t signature, bool& createdNew);
		void DeactivateEntity(uint64_t ID);

		void ClearEntities();

	private:
		std::vector<uint64_t> m_InactiveEntityIndexes;
		std::vector<Entity> m_Entities;
	};
}

