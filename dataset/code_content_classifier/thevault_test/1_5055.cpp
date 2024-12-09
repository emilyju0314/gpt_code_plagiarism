size_t ts::DescriptorList::removeInvalidPrivateDescriptors()
{
    size_t count = 0;

    for (size_t n = 0; n < _list.size(); ) {
        if (_list[n].pds == 0 && !_list[n].desc.isNull() && _list[n].desc->isValid() && _list[n].desc->tag() >= 0x80) {
            _list.erase(_list.begin() + n);
            count++;
        }
        else {
            n++;
        }
    }

    return count;
}