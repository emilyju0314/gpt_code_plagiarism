bool WisdomContainerEntry::readUInt8Enum(const std::string &name, NvU8 &e) const
{
    bool ok = true;
    WisdomContainerEntry b_entry;
    ok = ok && getEntry(name, IWisdomContainerEntry::ENTRY_TYPE_UINT8, &b_entry);
    ok = ok && b_entry.readUInt8(e);
    return ok;
}