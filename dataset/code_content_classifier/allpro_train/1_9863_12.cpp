#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <memory>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cfloat>
#include <cassert>
#include <random>

struct Coordinate {
	double x, y;
};
struct Angle {
	double sin, cos;
	Angle operator-() const;
};
struct Vector {
	double x, y;
	double length() const;
	Angle to_angle() const;
	Vector rotate(const Angle& angle) const;
	double cross(const Vector& that) const;
};
Coordinate operator+(const Coordinate& c, const Vector& v);
Coordinate operator+(const Vector& v, const Coordinate& c);
Vector operator-(const Coordinate& to, const Coordinate& from);
double lower_bound(double min, double max, const std::function<bool(double)>& predicate) {
	while (min + 1e-9 < max) {
		auto mid = (min + max) / 2;
		if (predicate(mid)) max = mid;
		else min = mid;
	}
	return max;
}
double cal_height(const std::vector<Coordinate> left, const std::vector<Coordinate> right, double area) {
	double bottom = 0;
	int li{ 0 }, ri{ 0 };
	while (true) {
		auto top = std::min(left[li + 1].y, right[ri + 1].y);
		auto lv = left[li + 1] - left[li];
		auto rv = right[ri + 1] - right[ri];
		auto lbx = (bottom - left[li].y) / lv.y * lv.x + left[li].x;
		auto rbx = (bottom - right[ri].y) / rv.y * rv.x + right[ri].x;
		auto ltx = (top - left[li].y) / lv.y * lv.x + left[li].x;
		auto rtx = (top - right[ri].y) / rv.y * rv.x + right[ri].x;
		auto bottom_length = std::abs(lbx - rbx);
		auto top_length = std::abs(ltx - rtx);
		auto height = top - bottom;
		auto square = (bottom_length + top_length) * height / 2;
		if (area > square + 1e-9) {
			area -= square;
			bottom = top;
			if (left[li + 1].y > right[ri + 1].y) {
				++ri;
			}
			else {
				++li;
			}
		}
		else {
			return lower_bound(bottom, top, [height, bottom, bottom_length, top_length, area](double mid) {return (mid - bottom) * ((top_length - bottom_length) * (mid - bottom) / height + bottom_length * 2) / 2 >= area; });
		}
	}
	return -1;
}
std::pair<std::vector<Coordinate>, std::vector<Coordinate>> normalize(const std::vector<Coordinate>& coordinates, const int base) {
	std::vector<Coordinate> moved(coordinates);
	const auto origin = coordinates[base];
	const auto angle = (coordinates[(base + 1) % coordinates.size()] - coordinates[base]).to_angle();
	for (auto& c : moved) {
		c = (c - origin).rotate(-angle) + Coordinate{ 0, 0 };
	}
	auto top = base + 1;
	std::vector<Coordinate> right{ moved[(base + 1) % moved.size()] }, left{ moved[base] };
	while (moved[top % moved.size()].y <= moved[(top + 1) % moved.size()].y) {
		right.push_back(moved[++top % moved.size()]);
	}
	top = base;
	while (moved[(top + moved.size()) % moved.size()].y <= moved[(top - 1 + moved.size()) % moved.size()].y) {
		--top;
		left.push_back(moved[(top + moved.size()) % moved.size()]);
	}
	return std::make_pair(left, right);
}
int main() {
	while (true) {
		int n; double d, v; std::cin >> n >> d >> v; if (n == 0) break;
		std::vector<Coordinate> coordinates(n); for (auto& c : coordinates) std::cin >> c.x >> c.y;
		double max_height = 0;
		for (auto i = 0; i < n; ++i) {
			auto pair = normalize(coordinates, i);
			auto height = cal_height(std::move(pair.first), std::move(pair.second), v / d);
			max_height = std::max(max_height, height);
		}
		std::cout << std::setprecision(9) << std::fixed << max_height << '\n';
	}
}

/*

https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Final/0253?year=2011

*/

Coordinate operator+(const Coordinate& c, const Vector& v)
{
	return Coordinate{ c.x + v.x, c.y + v.y };
}

Coordinate operator+(const Vector& v, const Coordinate& c)
{
	return Coordinate{ v.x + c.x, v.y + c.y };
}

Vector operator-(const Coordinate& to, const Coordinate& from)
{
	return Vector{ to.x - from.x, to.y - from.y };
}

double Vector::length() const
{
	return std::sqrt(x * x + y * y);
}

Angle Vector::to_angle() const
{
	return Angle{ y / length(), x / length() };
}

Vector Vector::rotate(const Angle& angle) const
{
	return Vector{angle.cos * x - angle.sin * y, angle.sin * x + angle.cos * y};
}

double Vector::cross(const Vector& that) const
{
	return x * that.y - y * that.x;
}

Angle Angle::operator-() const
{
	return Angle{ -sin, cos };
}

