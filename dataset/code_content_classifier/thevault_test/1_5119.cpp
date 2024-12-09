void ts::TOT::addDescriptors(DuckContext& duck, const DescriptorList& dlist)
{
    // Loop on all descriptors.
    for (size_t index = 0; index < dlist.count(); ++index) {
        if (!dlist[index].isNull() && dlist[index]->isValid()) {
            if (dlist[index]->tag() != DID_LOCAL_TIME_OFFSET) {
                // Not a local_time_offset_descriptor, add to descriptor list.
                descs.add(dlist[index]);
            }
            else {
                // Decode local_time_offset_descriptor in the list of regions.
                LocalTimeOffsetDescriptor lto(duck, *dlist[index]);
                if (lto.isValid()) {
                    regions.insert(regions.end(), lto.regions.begin(), lto.regions.end());
                }
            }
        }
    }
}