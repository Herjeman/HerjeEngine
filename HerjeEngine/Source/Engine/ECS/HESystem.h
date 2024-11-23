#pragma once
#include "Engine/Core.h"

namespace HerjeEngine
{
	class HE_API HESystem
	{
	public:
		HESystem(uint64_t signature) : m_Signature(signature) { Initialize(); };
		virtual ~HESystem(){}

		void Update(float deltaTime, std::vector<struct Entity>& entities);

		virtual void Initialize() {};
		virtual void Process(float deltaTime, struct Entity& entity) {};

		bool ShouldProcess(uint64_t signature);

	protected:
		uint64_t m_Signature = 0;
	};
}


