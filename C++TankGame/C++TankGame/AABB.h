#pragma once
#include "Vector3.h" 
#include "vector"



struct AABB{
	AABB() {}
	AABB(const MathClasses::Vector3& min, const MathClasses::Vector3& max) : min(min), max(max) {}

	MathClasses::Vector3 min, max;

	MathClasses::Vector3 Center() const {
		MathClasses::Vector3 (min + max) * 0.5f;
	}

	MathClasses::Vector3 Extents() const {
		return { abs(max.x - min.x) * 0.5f, abs(max.y - min.y) * 0.5f, abs(max.z - min.z) * 0.5f};
	}

	////////////////////////////////////////////////
	// Adding Points To the Corners
	////////////////////////////////////////////////

	std::vector<MathClasses::Vector3> Corners() const
	{
		std::vector<MathClasses::Vector3> corners(4);
		corners[0] = min;
		corners[1] = { min.x, max.y, min.z };
		corners[2] = max;
		corners[3] = { max.x, min.y, max.z };
		return corners;
	}

	void fit(const MathClasses::Vector3* points, unsigned int count) {
		min = { FLT_MAX, FLT_MAX, FLT_MAX };
		max = { FLT_MIN, FLT_MIN, FLT_MAX };

		for (unsigned int i = 0; i < count; i++, ++points) {
			min = MathClasses::Vector3::min(min, *points);
			max = MathClasses::Vector3::max(max, *points);
		}
	}

	void fit(const std::vector< MathClasses::Vector3*>& points) {
		min = { FLT_MAX, FLT_MAX, FLT_MAX };
		max = { FLT_MAX, FLT_MAX, FLT_MAX };
		

		for (auto& p : points) {
			min = MathClasses::Vector3::min(min, *p);
			max = MathClasses::Vector3::max(max, *p);
		}
	}

	////////////////////////////////////////////////
	// Checking To See If AABB VS ABB Is Overlapping
	////////////////////////////////////////////////

	bool Overlaps(const MathClasses::Vector3& p) const {
		return !(p.x < min.x || p.y < min.y || p.x > max.x || p.y > max.y);
	}

	bool Overlaps(const AABB& other) const {
		return !(max.x < other.min.x || max.y < other.min.y || min.x > other.max.x || min.x > other.max.y);
	}

	MathClasses::Vector3 ClosentPoint(const MathClasses::Vector3& p) const {
		return MathClasses::Vector3::clamp(p, min, max);
	}

};