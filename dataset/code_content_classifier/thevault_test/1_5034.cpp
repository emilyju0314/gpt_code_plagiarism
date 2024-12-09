bool ts::SDT::Service::locateServiceDescriptor(DuckContext& duck, ServiceDescriptor& desc) const
{
    const size_t index = descs.search(DID_SERVICE);

    if (index >= descs.count()) {
        desc.invalidate();
        return false;
    }
    else {
        assert(!descs[index].isNull());
        desc.deserialize(duck, *descs[index]);
        return desc.isValid();
    }
}