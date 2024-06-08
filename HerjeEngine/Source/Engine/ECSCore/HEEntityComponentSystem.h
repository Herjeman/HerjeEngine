#pragma once
#include "Engine/Core.h"
#include "HEEntityManager.h"
#include "HEComponentManager.h"
#include "HESystem.h"
#include "Utilities/Vector2.h"

namespace HerjeEngine
{
	enum class HE_API EEntitySignature : uint64_t
	{
		IsActive = 1 << 0,
		Transform = 1 << 1,
		Velocity = 1 << 2
	};


	struct HE_API TransformComponent
	{
		FVector2 Location;
		FVector2 Scale;
		float Rotation;
	};

	struct HE_API VelocityComponent
	{
		FVector2 Velocity;
	};

	class HEEntityComponentSystem
	{
	private:
		HEEntityComponentSystem();
		~HEEntityComponentSystem();

	public:
		// TODO: Probably not expose this, bur create wrappers 
		HE_API static HEEntityComponentSystem& Get();

		HEEntityComponentSystem(const HEEntityComponentSystem& obj) = delete;
		HEEntityComponentSystem& operator=(const HEEntityComponentSystem&) = delete;

		// TODO: Probably not expose this, bur create wrappers 
		HE_API size_t AddEntity(uint64_t signature);
		HE_API void DeactivateEntity(size_t id);

		template<typename T>
		uint64_t RegisterComponent();
		

		template<typename T>
		void RegisterSystem();

	private:
		HEComponentManager m_ComponentManager;
		HEEntityManager m_EntityManager;

		std::vector<std::unique_ptr<HESystem>> m_Systems;
	};

	template uint64_t HEEntityComponentSystem::RegisterComponent<TransformComponent>();
	template uint64_t HEEntityComponentSystem::RegisterComponent<VelocityComponent>();
}


