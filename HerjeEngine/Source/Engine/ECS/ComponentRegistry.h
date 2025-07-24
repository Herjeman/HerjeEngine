#pragma once
#include "HEPrecompiled.h"
#include "HEECS.h"

#include <algorithm>
#include <ranges>

template<typename T>
class HEComponentRegistrySimple
{
public:
	HE_API T& AddComponent(const EntityID& ownerID, const T& initialValue)
	{
		HE_CORE_ASSERT(Components.size() == OwningEntities.size(), "Component/Owner vector size mismatch!");

		OwningEntities.push_back(ownerID);
		Components.push_back(initialValue);

		return Components.back();
	}

	HE_API std::vector<T>& GetComponents()
	{
		return Components;
	}

	HE_API void GetComponentsForEntity(const EntityID& ownerID, std::vector<T*> out)
	{
		HE_CORE_ASSERT(Components.size() == OwningEntities.size(), "Component/Owner vector size mismatch!");

		for (size_t i = 0; i < OwningEntities.size(); i++)
		{
			if (OwningEntities[i] == ownerID)
			{
				out.push_back(&Components[i]);
			}
		}
	}

	HE_API void RemoveComponentsForEntity(const EntityID& ownerID)
	{
		HE_CORE_ASSERT(Components.size() == OwningEntities.size(), "Component/Owner vector size mismatch!");

		std::vector<size_t> indexesToRemove;

		for (size_t i = 0; i < OwningEntities.size(); i++)
		{
			if (OwningEntities[i] == ownerID)
			{
				indexesToRemove.push_back(i);
			}
		}

		for (const auto& indexToRemove : indexesToRemove)
		{
			std::swap(Components[indexToRemove], Components.back());
			std::swap(OwningEntities[indexToRemove], OwningEntities.back());

			Components.pop_back();
			OwningEntities.pop_back();
		}
	}

	HE_API size_t Count()
	{
		HE_CORE_ASSERT(Components.size() == OwningEntities.size(), "Component/Owner vector size mismatch!");
		return Components.size();
	}
private:
	std::vector<T> Components;
	std::vector<EntityID> OwningEntities;
};