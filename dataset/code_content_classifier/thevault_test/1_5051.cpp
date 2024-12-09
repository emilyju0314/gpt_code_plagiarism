void ts::DescriptorList::add(DuckContext& duck, const AbstractDescriptor& desc)
{
    DescriptorPtr pd(new Descriptor);
    CheckNonNull(pd.pointer());
    desc.serialize(duck, *pd);
    if (pd->isValid()) {
        add(pd);
    }
}