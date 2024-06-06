#pragma once
#include "Engine/Core.h"
#include "HEEntityManager.h"
#include "HEComponentManager.h"
#include "HESystem.h"

namespace HerjeEngine
{
	// This is a singleton class that manages all Entities, Components and Systems
	// It should be the access point from Game code to register new Components 
	// and Systems. As well as to access Entities.

	struct HE_API MyComponent
	{
		int num = 30;
	};

	class HEEntityComponentSystem
	{
	private:
		HEEntityComponentSystem();
		~HEEntityComponentSystem();

	public:
		HE_API static HEEntityComponentSystem& Get();

		HEEntityComponentSystem(const HEEntityComponentSystem& obj) = delete;
		HEEntityComponentSystem& operator=(const HEEntityComponentSystem&) = delete;

		HE_API size_t AddEntity(uint64_t signature);

		template<typename T>
		HE_API uint64_t RegisterComponent();


		template<typename T>
		HE_API void RegisterSystem();

	private:
		HEComponentManager m_ComponentManager;
		HEEntityManager m_EntityManager;

		std::vector<std::unique_ptr<HESystem>> m_Systems;
	};
		template HE_API uint64_t HEEntityComponentSystem::RegisterComponent<MyComponent>();
}


