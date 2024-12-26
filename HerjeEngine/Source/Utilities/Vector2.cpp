#include "HEPreCompiled.h"
#include "Vector2.h"

namespace HerjeEngine {
	inline float Vector2::Magnitude() const
	{
		return std::sqrt(X * X + Y * Y);
	}

	inline float Vector2::Magnitude(const Vector2& A)
	{
		return std::sqrt(A.X * A.X + A.Y * A.Y);
	}

	inline void Vector2::Normalize()
	{
		float Hypotenuse = Magnitude();
		if (Hypotenuse == 0)
		{
			return;
		}
		X = X / Hypotenuse;
		Y = Y / Hypotenuse;
	}

	inline Vector2 Vector2::Normalize(const Vector2& A)
	{
		float Hypotenuse = Magnitude(A);
		return Vector2(A.X / Hypotenuse, A.Y / Hypotenuse);
	}

	inline Vector2 Vector2::GetForwardVector2D(const float& Radians)
	{
		return Vector2(std::cos(Radians), std::sinf(Radians));
	}

	inline float Vector2::GetForwardAngleRadians2D(const Vector2& A)
	{
		return std::atan2f(A.X, A.Y);
	}

	inline float Vector2::GetAngleBetween(const Vector2& A, const Vector2& B)
	{
		return std::acosf(DotProduct(A, B) / A.Magnitude() * B.Magnitude());
	}

	inline float Vector2::GetAngleBetweenNormalized(const Vector2& A, const Vector2& B)
	{
		return std::acosf(DotProduct(A, B));
	}

	inline float Vector2::DotProduct(const Vector2& A, const Vector2& B)
	{
		return A.X * B.X + A.Y * B.Y;
	}
}