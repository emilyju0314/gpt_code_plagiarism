glm::vec2 AABB::GetIntersectionDepth(const AABB& other)
{
    glm::vec2 depth(GetWidth(), GetHeight()); // XXX to avoid 0 depth

    if (minX < other.maxX && other.maxX < maxX)
        depth.x = -(other.maxX - minX);
    else if (maxX > other.minX && other.minX > minX)
        depth.x = maxX - other.minX;
    if (minY < other.maxY && other.maxY < maxY)
        depth.y = -(other.maxY - minY);
    else if (maxY > other.minY && other.minY > minY)
        depth.y = maxY - other.minY;

    assert(depth.x != 0.0f);
    assert(depth.y != 0.0f);

    return depth;
}