#pragma once
#include "Engine/Core.h"

namespace HerjeEngine {

	struct HE_API FVector2
	{
		float X;
		float Y;
		FVector2() : X(0), Y(0) {}
		FVector2(float x, float y) : X(x), Y(y) {}

		FVector2 operator+ (const FVector2& vec)
		{
			FVector2 out;
			out.X = this->X + vec.X;
			out.Y = this->Y + vec.Y;
			return out;
		}

		FVector2 operator- (const FVector2& vec)
		{
			FVector2 out;
			out.X = this->X - vec.X;
			out.Y = this->Y - vec.Y;
			return out;
		}

		FVector2 operator* (const float& factor)
		{
			FVector2 out;
			out.X = X * factor;
			out.Y = Y * factor;
			return out;
		}

		inline float Magnitude() const;
		inline static float Magnitude(const FVector2& A);

		inline void Normalize();
		inline static FVector2 Normalize(const FVector2& A);

		inline static FVector2 GetForwardVector2D(const float& Radians);
		inline static float GetForwardAngleRadians2D(const FVector2& A);

		inline static float GetAngleBetween(const FVector2& A, const FVector2& B);
		inline static float GetAngleBetweenNormalized(const FVector2& A, const FVector2& B);

		inline static float DotProduct(const FVector2& A, const FVector2& B);
	};
}


