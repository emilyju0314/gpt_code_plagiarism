int QTNode::GetChildIndex(QTEntity* entity) const
{
    assert(!IsLeaf());

    for (uint i = 0; i < QTNODE_NUM_CHILDREN; i++)
        if (entity->GetAABB().FitsIn(mChildren[i]->mLimits))
            return i;

    return -1;
}