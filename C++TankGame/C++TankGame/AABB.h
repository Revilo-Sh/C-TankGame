#pragma once
#include "Vector3.h" 
#include "vector"

constexpr float min(float a, float b) { return a < b ? a : b; }
constexpr float max(float a, float b) { return a > b ? a : b; }

MathClasses::Vector3 min(const MathClasses::Vector3& a, const MathClasses::Vector3& b) {
	return { min(a.x,b.x), min(a.y, b.y) };
}

MathClasses::Vector3 max(const MathClasses::Vector3& a, const MathClasses::Vector3& b) {
	return { max(a.x,b.x), max(a.y, b.y) };
}

constexpr float clamp(float t, float a, float b) {
	return max(a, min(b, t));
}

MathClasses::Vector3 clamp(const MathClasses::Vector3& t, const MathClasses::Vector3& a, const MathClasses::Vector3& b) {
	return max(a, min(b, t));
}

struct AABB{
	AABB() {}
	AABB(const MathClasses::Vector3& min, const MathClasses::Vector3& max) : min(min), max(max) {}

	MathClasses::Vector3 min, max;

	MathClasses::Vector3 Center() const {
		MathClasses::Vector3 (min + max) * 0.5f;
	}

	MathClasses::Vector3 Extents() const {
		return { abs(max.x - min.x) * 0.5f, abs(max.y - min.y) * 0.5f };
	}

	std::vector<MathClasses::Vector3> Corners() const
	{
		std::vector<MathClasses::Vector3> corners(4);
		corners[0] = min;
		corners[1] = { min.x, max.y };
		corners[2] = max;
		corners[3] = { max.x, min.y };
		return corners;
	}
};