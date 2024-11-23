#include "HEPreCompiled.h"
#include "Utilities/BitFlag.h"
#include "Engine/ECS/HEEntityManager.h"
#include "HESystem.h"

namespace HerjeEngine
{
    void HESystem::Update(float deltaTime, std::vector<Entity>& entities)
    {
        for (auto& entity : entities)
        {
            if (ShouldProcess(entity.Signature))
            {
                Process(deltaTime, entity);
            }
        }
    }

    bool HESystem::ShouldProcess(uint64_t signature)
    {
        return BitFlag::HasFlags(signature, m_Signature |= 1);
    }
}

