size_t ts::DescriptorList::serialize(uint8_t*& addr, size_t& size, size_t start) const
{
    size_t i;

    for (i = start; i < _list.size() && _list[i].desc->size() <= size; ++i) {
        // Flawfinder: ignore: memcpy()
        ::memcpy(addr, _list[i].desc->content(), _list[i].desc->size());
        addr += _list[i].desc->size();
        size -= _list[i].desc->size();
    }

    return i;
}