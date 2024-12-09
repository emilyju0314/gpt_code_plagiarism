bool ts::CADescriptor::AddFromCommandLine(DuckContext& duck, DescriptorList& dlist, const UStringVector& values)
{
    bool result = true;
    for (size_t i = 0; i < values.size(); ++i) {
        CADescriptor desc;
        if (desc.fromCommmandLine(values[i], duck.report())) {
            dlist.add(duck, desc);
        }
        else {
            result = false;
        }
    }
    return result;
}