size_t ts::CADescriptor::SearchByCAS(const ts::DescriptorList& dlist, uint16_t casid, size_t start_index)
{
    bool found = false;
    for (; !found && start_index < dlist.count(); start_index++) {
        const DescriptorPtr& desc(dlist[start_index]);
        found = !desc.isNull() &&
            desc->isValid() &&
            desc->tag() == DID_CA &&
            desc->payloadSize() >= 4 &&
            GetUInt16(desc->payload()) == casid;
    }
    return start_index;
}