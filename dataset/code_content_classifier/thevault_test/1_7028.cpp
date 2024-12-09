void QTNode::Split()
{
    glm::vec2 center = mLimits.GetCenter();

    mChildren[NE] = new QTNode(AABB(center.x, center.y, mLimits.maxX, mLimits.maxY), this);
    mChildren[NW] = new QTNode(AABB(mLimits.minX, center.y, center.x, mLimits.maxY), this);
    mChildren[SW] = new QTNode(AABB(mLimits.minX, mLimits.minY, center.x, center.y), this);
    mChildren[SE] = new QTNode(AABB(center.x, mLimits.minY, mLimits.maxX, center.y), this);
}