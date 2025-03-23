#pragma once
#include "Engine/Core.h"

// THIS IS A COMMENT

namespace HerjeEngine
{
	template<typename EventType>
	class EventDispatcher;

	template<typename EventType>
	class EventListener
	{
		using CallbackFunction = std::function<void(const EventType&)>;
	public:
		EventListener(CallbackFunction function, EventDispatcher<EventType>& dispatcher)
			: m_Dispatcher(dispatcher)
		{
			dispatcher.AddListener(this, function);
		}
		~EventListener()
		{
			m_Dispatcher.RemoveListener(this);
		}

	private:
		EventDispatcher<EventType>& m_Dispatcher;
	};



	template<typename EventType>
	class EventDispatcher
	{
		using CallbackFunction = std::function<void(const EventType&)>;
		friend class EventListener<EventType>;

	public:
		EventDispatcher() {}

		inline void QueueEvent(const EventType event) { m_QueuedEvents.push_back(event); }
		void DispatchEvent(const EventType& event) const;
		void DispatchQueuedEvents();
		bool HasListeners() const { return !m_Listeners.empty(); }

	protected:
		void AddListener(const EventListener<EventType>* listener, CallbackFunction function);
		void RemoveListener(EventListener<EventType>* listener);


	private:
		std::map<const EventListener<EventType>*, CallbackFunction> m_Listeners;
		std::vector<EventType> m_QueuedEvents;
	};

	template<typename EventType>
	inline void EventDispatcher<EventType>::AddListener(const EventListener<EventType>* listener, CallbackFunction function)
	{
		if (m_Listeners.find(listener) != m_Listeners.end())
		{
			return;
		}

		m_Listeners[listener] = function;
	}

	template<typename EventType>
	inline void EventDispatcher<EventType>::RemoveListener(EventListener<EventType>* listener)
	{
		const auto listenerIndex = m_Listeners.find(listener);

		if (listenerIndex != m_Listeners.end())
		{
			m_Listeners.erase(listenerIndex);
		}
	}

	template<typename EventType>
	inline void EventDispatcher<EventType>::DispatchEvent(const EventType& event) const
	{
		for (auto const& [id, function] : m_Listeners)
		{
			(function)(event);
		}
	}

	template<typename EventType>
	inline void EventDispatcher<EventType>::DispatchQueuedEvents()
	{
		for (const EventType& event : m_QueuedEvents)
		{
			DispatchEvent(event);
		}

		m_QueuedEvents = {};
	}
}
