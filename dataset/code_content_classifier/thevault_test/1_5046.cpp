size_t ts::CADescriptor::SearchByPID(const ts::DescriptorList& dlist, ts::PID pid, size_t start_index)
{
    bool found = false;
    for (; !found && start_index < dlist.count(); start_index++) {
        const DescriptorPtr& desc(dlist[start_index]);
        found = !desc.isNull() &&
            desc->isValid() &&
            desc->tag() == DID_CA &&
            desc->payloadSize() >= 4 &&
            (GetUInt16(desc->payload() + 2) & 0x1FFF) == pid;
    }
    return start_index;
}