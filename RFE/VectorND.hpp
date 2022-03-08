#pragma once
#include "pch.h"

namespace rfe
{
	template <typename T>
	struct Vector2D;
	template <typename T>
	struct Vector3D;
	template <typename T>
	struct Quaternion4D;

	// Base class for a Vector of N dimension of type T
	template <size_t N, typename T>
	struct VectorND
	{
		T data[N];

		VectorND()
		{
			for (size_t i = 0; i < N; i++)
			{
				data[i] = T();
			}
		}
		VectorND(T data[N]) : data(data) { }
		VectorND(const VectorND& other)
		{
			std::copy(std::begin(other.data), std::end(other.data), std::begin(data));
		}
		VectorND& operator=(const VectorND& other)
		{
			std::copy(std::begin(other.data), std::end(other.data), std::begin(data));
			return *this;
		}
		VectorND(VectorND&& other) noexcept
		{
			std::swap(data, other.data);
		}
		VectorND& operator=(VectorND&& other) noexcept
		{
			std::swap(data, other.data);
			return *this;
		}

		static VectorND Zero()
		{
			return VectorND();
		}

		static VectorND One()
		{
			VectorND v;
			std::fill_n(v.data, N, 1);
			return v;
		}

		T GetMagnitude() const
		{
			auto total = 0;
			for (size_t i = 0; i < N; i++)
			{
				total += data[i] * data[i];
			}
			return sqrt(total);
		}

		void Normalize()
		{
			auto mag = GetMagnitude();
			if (mag == 0) return;

			for (size_t i = 0; i < N; i++)
			{
				data[i] /= mag;
			}
		}

		VectorND GetNormalized() const
		{
			VectorND v = *this;
			auto mag = v.GetMagnitude();
			for (size_t i = 0; i < N; i++)
			{
				v.data[i] /= mag;
			}
			return v;
		}

		bool operator==(const VectorND& rhs) const
		{
			for (size_t i = 0; i < N; i++)
			{
				if (data[i] != rhs.data[i])
				{
					return false;
				}
				data[i] += rhs.data[i];
			}
			return true;
		}
		bool operator!=(const VectorND& rhs) const
		{
			return !(*this == rhs);
		}
		VectorND operator+(const VectorND& rhs) const
		{
			VectorND v;
			for (size_t i = 0; i < N; i++)
			{
				v.data[i] = data[i] + rhs.data[i];
			}
			return v;
		}
		VectorND& operator+=(const VectorND& rhs)
		{
			return *this = *this + rhs;
		}
		VectorND operator-(const VectorND& rhs) const
		{
			VectorND v;
			for (size_t i = 0; i < N; i++)
			{
				v.data[i] = data[i] - rhs.data[i];
			}
			return v;
		}
		VectorND& operator-=(const VectorND& rhs)
		{
			return *this = *this - rhs;
		}
		VectorND operator*(const T rhs) const
		{
			VectorND v;
			for (size_t i = 0; i < N; i++)
			{
				v.data[i] = data[i] * rhs;
			}
			return v;
		}
		VectorND& operator*=(const T& rhs)
		{
			return *this = *this * rhs;
		}
		VectorND operator/(const T rhs) const
		{
			VectorND v;
			for (size_t i = 0; i < N; i++)
			{
				v.data[i] = data[i] / rhs;
			}
			return v;
		}
		VectorND& operator/=(const T& rhs)
		{
			return *this = *this / rhs;
		}

		operator Vector2D<T>() const
		{
			return { data[0], data[1] };
		}

		operator Vector3D<T>() const
		{
			return { data[0], data[1], data[2] };
		}

		operator Quaternion4D<T>() const
		{
			return { data[0], data[1], data[2], data[3] };
		}
	};
}