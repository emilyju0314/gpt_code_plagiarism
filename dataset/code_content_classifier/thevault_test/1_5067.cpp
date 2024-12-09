bool ts::DescriptorList::fromXML(DuckContext& duck, xml::ElementVector& others, const xml::Element* parent, const UString& allowedOthers)
{
    UStringList allowed;
    allowedOthers.split(allowed);
    return fromXML(duck, others, parent, allowed);
}