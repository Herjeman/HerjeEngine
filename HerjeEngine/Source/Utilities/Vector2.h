#pragma once
#include "Engine/Core.h"

namespace HerjeEngine {

	struct HE_API Vector2
	{
		float X;
		float Y;
		Vector2() : X(0), Y(0) {}
		Vector2(float x, float y) : X(x), Y(y) {}

		Vector2 operator+ (const Vector2& other)
		{
			Vector2 out;
			out.X = this->X + other.X;
			out.Y = this->Y + other.Y;
			return out;
		}

		Vector2 operator+= (const Vector2& other)
		{
			this->X += other.X;
			this->Y += other.Y;
			return *this;
		}

		Vector2 operator-= (const Vector2& other)
		{
			this->X -= other.X;
			this->Y -= other.Y;
			return *this;
		}

		Vector2 operator- (const Vector2& other)
		{
			Vector2 out;
			out.X = this->X - other.X;
			out.Y = this->Y - other.Y;
			return out;
		}

		Vector2 operator* (const float& factor)
		{
			Vector2 out;
			out.X = X * factor;
			out.Y = Y * factor;
			return out;
		}

		inline float Magnitude() const;
		inline static float Magnitude(const Vector2& A);

		inline void Normalize();
		inline static Vector2 Normalize(const Vector2& A);

		inline static Vector2 GetForwardVector2D(const float& Radians);
		inline static float GetForwardAngleRadians2D(const Vector2& A);

		inline static float GetAngleBetween(const Vector2& A, const Vector2& B);
		inline static float GetAngleBetweenNormalized(const Vector2& A, const Vector2& B);

		inline static float DotProduct(const Vector2& A, const Vector2& B);

		inline static Vector2 Up() { return Vector2{ 0.0f, -1.0f }; }
		inline static Vector2 Down() { return Vector2{ 0.0f, 1.0f }; }
		inline static Vector2 Left() { return Vector2{ -1.0f, 0.0f }; }
		inline static Vector2 Right() { return Vector2{ 1.0f, 0.0f }; }
		inline static Vector2 Zero() { return Vector2{ 0.0f, 0.0f }; }
	};
}


