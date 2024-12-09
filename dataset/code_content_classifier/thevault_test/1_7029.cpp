QTNode* QTNode::Expand(const AABB& newLimits)
{
    assert(!mParent); // should be root

    // find the direction where we should grow;
    glm::vec2 direction = glm::normalize(mLimits.GetDistance(newLimits));

    float width = mLimits.maxX - mLimits.minX,
          height = mLimits.maxY - mLimits.minY;

    AABB doubledLimits = mLimits;
    int appendTo;

    if (direction.x > 0) { // East
        if (direction.y > 0) { // NE
            doubledLimits = AABB(
                mLimits.minX, mLimits.minY,
                mLimits.maxX + width, mLimits.maxY + height);
            appendTo = SW;
        } else { // SE
            doubledLimits = AABB(
                mLimits.minX, mLimits.minY - height,
                mLimits.maxX + width, mLimits.maxY);
            appendTo = NW;
        }
    } else { // West
        if (direction.y > 0) { // NW
            doubledLimits = AABB(
                mLimits.minX - width, mLimits.minY,
                mLimits.maxX, mLimits.maxY + height);
            appendTo = SE;
        } else { // SW
            doubledLimits = AABB(
                mLimits.minX - width, mLimits.minY - height,
                mLimits.maxX, mLimits.maxY);
            appendTo = NE;
        }
    }
    printf("Doubled the limits to: {%.2f, %.2f, %.2f, %.2f}\n",
        doubledLimits.minX, doubledLimits.minY,
        doubledLimits.maxX, doubledLimits.maxY);

    // New parent node
    QTNode* parent = new QTNode(doubledLimits, nullptr);
    parent->Split();

    delete parent->mChildren[appendTo];
    parent->mChildren[appendTo] = this;
    this->mParent = parent;

    // Increment depth
    auto f = [&](QTNode* qNode) {
        qNode->SetDepth(qNode->GetDepth() + 1);
        return true;
    };
    Traverse(f);

    if (!newLimits.FitsIn(doubledLimits))
        parent = parent->Expand(newLimits);

    return parent;
}