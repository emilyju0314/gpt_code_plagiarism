Result
hit(const AABB& a, const AABB& b)
{
    auto delta = Vec{ b.center.x - a.center.x, b.center.y - a.center.y };
    auto overlap = (a.half + b.half) - glm::abs(delta);
    if (overlap.x <= 0.0 || overlap.y <= 0.0) {
        return Result{ Vec{ 0, 0 }, Vec{ 0, 0 } };
    }

    auto sign = detail::sign(delta);
    if (overlap.x <= overlap.y) {
        auto pen = Vec{ overlap.x * sign.x, 0 };
        auto normal = Vec{ -sign.x, 0 };
        return Result{ normal, pen };
    } else {
        auto pen = Vec{ 0, overlap.y * sign.y };
        auto normal = Vec{ 0, -sign.y };
        return Result{ normal, pen };
    }
}