ts::PDS ts::DescriptorList::privateDataSpecifier(size_t index) const
{
    assert(index < _list.size());
    return _list[index].pds;
}