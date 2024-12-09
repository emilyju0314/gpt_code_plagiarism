void
AttributeGroup::Select(int index, void *address, int length)
{
    if(index < static_cast<int>(typeMap.size()))
    {
        typeMap[index].address = address;
        typeMap[index].selected = true;
        typeMap[index].length = length;
    }
}