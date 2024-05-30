#pragma once
constexpr float minf(float a, float b) { return a < b ? a : b; }
constexpr float maxf(float a, float b) { return a > b ? a : b; }
constexpr float depthf(float a, float b) { return a > b ? a : b; }

constexpr float clamp(float t, float a, float b) {
	return maxf(a, minf(b, t));
}

