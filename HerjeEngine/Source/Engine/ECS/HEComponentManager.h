#pragma once

namespace HerjeEngine
{
	class ComponentList
	{
	public:
		virtual ~ComponentList(){}
		virtual void AddComponent(){}
		virtual void ResetComponent(size_t index){}
	};

	template<typename T>
	class SpecificComponentList : public ComponentList
	{
	public:
		std::vector<T>& GetComponents() { return m_Components; }
		T& GetComponent(size_t index) 
		{
			if (index >= m_Components.size())
			{
				HE_CORE_ASSERT(false, "Index out of range");
				return {};
			}
			return m_Components[index];
		}

		void AddComponent() override { m_Components.push_back(T()); }
		void ResetComponent(size_t index) 
		{
			if (index >= m_Components.size())
			{
				HE_CORE_ASSERT(false, "Component index out of range");
				return;
			}
			m_Components[index] = T();
		}

		std::vector<T> m_Components;
	};


	class HEComponentManager
	{
	public:
		HEComponentManager();
		~HEComponentManager();

		template<typename T>
		uint64_t RegisterComponent()
		{
			if (m_RegisteredComponents >= m_MaxComponents)
			{
				HE_CORE_ASSERT(false, "Engine Component List is full!!!");
				return 0;
			}

			// Shift one extra bit because the first bit is reserved for IsActive
			uint64_t ComponentSignature = static_cast<uint64_t>(1 << (m_RegisteredComponents + 1));

			m_ComponentListIndexes[ComponentSignature] = m_RegisteredComponents;
			m_ComponentLists[m_RegisteredComponents] = new SpecificComponentList<T>();

			m_RegisteredComponents++;
			return ComponentSignature;
		}

		template<typename T>
		T& GetComponent(const size_t& entityID,const uint64_t& componentSignature) const
		{
			auto* componentList = GetComponentList(componentSignature);
			HE_CORE_ASSERT(componentList, "No Component list found for component");
			
			// this is unsafe...
			return GetComponentList(componentSignature)[entityID];
		}

		const ComponentList* GetComponentList(const uint64_t componentSignature) const;
		


		void AddComponentsForNewEntity();
		void ResetComponentsForEntity(size_t index);

	private:
		// We only allow 63 components as the first bit in the 
		// 64bit Signature is reserved for the IsActive state
		int m_MaxComponents = 63;
		int m_RegisteredComponents = 0;


		std::unordered_map<uint64_t, int> m_ComponentListIndexes;

		// Maybe std::vector<std::unique_ptr> is better?
		ComponentList** m_ComponentLists;
	};


}


