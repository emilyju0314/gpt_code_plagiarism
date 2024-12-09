bool
AttributeGroup::IsSelected(int i) const
{
    bool retval = false;

    // If the index is valid, check the selected flag.
    if(i >= 0 && i < static_cast<int>(typeMap.size()))
    {
         retval = typeMap[i].selected;
    }

    return retval;
}