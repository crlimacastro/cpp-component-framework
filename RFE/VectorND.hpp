#pragma once
#include "pch.h"

namespace rfe
{
	// Base class for a Vector of N dimension of type T
	template <size_t N, typename T>
	struct VectorND
	{
		T data[N];

		VectorND() = default;
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
			for (size_t i = 0; i < N; i++)
			{
				data[i] += rhs.data[i];
			}
			return *this;
		}
		VectorND& operator+=(const VectorND& rhs)
		{
			return *this = *this + rhs;
		}
		VectorND operator-(const VectorND& rhs) const
		{
			for (size_t i = 0; i < N; i++)
			{
				data[i] -= rhs.data[i];
			}
			return *this;
		}
		VectorND& operator-=(const VectorND& rhs)
		{
			return *this = *this - rhs;
		}
		VectorND operator*(const T rhs) const
		{
			for (size_t i = 0; i < N; i++)
			{
				data[i] *= rhs;
			}
			return *this;
		}
		VectorND& operator*=(const float& rhs)
		{
			return *this = *this * rhs;
		}
		VectorND operator/(const T rhs) const
		{
			for (size_t i = 0; i < N; i++)
			{
				data[i] *= rhs;
			}
			return *this;
		}
		VectorND& operator/=(const float& rhs)
		{
			return *this = *this / rhs;
		}
	};
}