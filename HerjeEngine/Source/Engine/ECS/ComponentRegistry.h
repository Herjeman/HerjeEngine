#pragma once
#include "HEPrecompiled.h"
#include "HEECS.h"

#include <ranges>

template<typename T>
class HE_API ComponentRegistrySimple
{
public:
	void AddComponent(const EntityID& ownerID, const T& initialValue) 
	{
		Components.push_back(initialValue);
		OwningEntities.push_back(ownerID);
	}

	auto GetComponentView(const EntityID& ownerID)
	{
		
	}
private:
	std::vector<T> Components;
	std::vector<EntityID> OwningEntities;
};