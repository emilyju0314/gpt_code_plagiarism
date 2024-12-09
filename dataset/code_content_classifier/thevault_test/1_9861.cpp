int
AttributeGroup::NumAttributesSelected() const
{
    // See if any fields are selected. If none are selected
    // then we will assume that we want to write all of them since
    // it makes no sense to write none.
    int selectCount = 0;
    typeInfoVector::const_iterator pos;
    for(pos = typeMap.begin(); pos != typeMap.end(); ++pos)
    {
        if(pos->selected)
            ++selectCount;
    }

    return selectCount;
}