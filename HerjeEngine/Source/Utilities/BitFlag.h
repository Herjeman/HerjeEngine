#pragma once
#include "Engine/Core.h"


namespace HerjeEngine 
{
	namespace BitFlag
	{
		template<typename T>
		static inline void SetFlags(T& out, const T& flagsToSet) { out |= flagsToSet; }

		template<typename T>
		static inline void UnsetFlags(T& out, const T& flagsToUnset) { out &= ~flagsToUnset; }

		template<typename T>
		static inline void FlipFlag(T& out, const T& flagsToFlip) { out ^= flagsToFlip; }

		template<typename T>
		static inline bool HasFlags(const T& in, const T& flagsToCheck) { return (in & flagsToCheck) == flagsToCheck; }

		template<typename T>
		static inline bool HasAnyFlag(const T& in, const T& flagsToCheck) { return (in & flagsToCheck) != 0; }

		template<typename T>
		static inline bool HasFlagsExact(const T& in, const T& flagsToCheck) { return in == flagsToCheck; }
	}
}