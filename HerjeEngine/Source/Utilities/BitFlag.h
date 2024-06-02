#pragma once
#include "Engine/Core.h"

template<class T>
struct BitFlag
{
public:
	inline void SetFlag(const T Flag) { m_Flag |= Flag; }
	inline void UnsetFlag(const T Flag) { m_Flag &= ~Flag; }
	inline void FlipFlag(const T Flag) { m_Flag ^= Flag; }

	inline bool HasFlag(const T& Flag) const { return (m_Flag & Flag) == Flag; }
	inline bool HasAnyFlag(const T& Flags) const { return (m_Flag & Flags) != 0; }
	inline bool HasRequiredFlags(const T& Flags) const { return (m_Flag & Flags) == m_Flag; }
	inline bool HasFlagsExact(const T& Flags) const { return m_Flag == Flags; }

	inline const T& GetFlag() const { return m_Flag; }
	inline constexpr int GetSize() const { return sizeof(m_Flag); }

	inline constexpr void UnsetAll() { m_Flag = 0; }

private:
	T m_Flag = 0;
};