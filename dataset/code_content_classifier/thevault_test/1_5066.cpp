bool ts::DescriptorList::toXML(DuckContext& duck, xml::Element* parent) const
{
    bool success = true;
    for (size_t index = 0; index < _list.size(); ++index) {
        if (_list[index].desc.isNull() || _list[index].desc->toXML(duck, parent, duck.actualPDS(_list[index].pds), tableId() , false) == nullptr) {
            success = false;
        }
    }
    return success;
}