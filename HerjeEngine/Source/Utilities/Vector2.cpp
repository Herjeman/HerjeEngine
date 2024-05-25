#include "HEPreCompiled.h"
#include "Vector2.h"

namespace HerjeEngine {
	inline float FVector2::Magnitude() const
	{
		return std::sqrt(X * X + Y * Y);
	}

	inline float FVector2::Magnitude(const FVector2& A)
	{
		return std::sqrt(A.X * A.X + A.Y * A.Y);
	}

	inline void FVector2::Normalize()
	{
		float Hypotenuse = Magnitude();
		if (Hypotenuse == 0)
		{
			return;
		}
		X = X / Hypotenuse;
		Y = Y / Hypotenuse;
	}

	inline FVector2 FVector2::Normalize(const FVector2& A)
	{
		float Hypotenuse = Magnitude(A);
		return FVector2(A.X / Hypotenuse, A.Y / Hypotenuse);
	}

	inline FVector2 FVector2::GetForwardVector2D(const float& Radians)
	{
		return FVector2(std::cos(Radians), std::sinf(Radians));
	}

	inline float FVector2::GetForwardAngleRadians2D(const FVector2& A)
	{
		return std::atan2f(A.X, A.Y);
	}

	inline float FVector2::GetAngleBetween(const FVector2& A, const FVector2& B)
	{
		return std::acosf(DotProduct(A, B) / A.Magnitude() * B.Magnitude());
	}

	inline float FVector2::GetAngleBetweenNormalized(const FVector2& A, const FVector2& B)
	{
		return std::acosf(DotProduct(A, B));
	}

	inline float FVector2::DotProduct(const FVector2& A, const FVector2& B)
	{
		return A.X * B.X + A.Y * B.Y;
	}
}