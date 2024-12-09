size_t ts::DescriptorList::binarySize() const
{
    size_t size = 0;

    for (int i = 0; i < int(_list.size()); ++i) {
        size += _list[i].desc->size();
    }

    return size;
}