void ts::DVBEnhancedAC3Descriptor::merge(const DVBEnhancedAC3Descriptor& other)
{
    if (!component_type.set()) {
        component_type = other.component_type;
    }
    if (!bsid.set()) {
        bsid = other.bsid;
    }
    if (!mainid.set()) {
        mainid = other.mainid;
    }
    if (!asvc.set()) {
        asvc = other.asvc;
    }
    mixinfoexists = mixinfoexists || other.mixinfoexists;
    if (!substream1.set()) {
        substream1 = other.substream1;
    }
    if (!substream2.set()) {
        substream2 = other.substream2;
    }
    if (!substream3.set()) {
        substream3 = other.substream3;
    }
    if (additional_info.empty()) {
        additional_info = other.additional_info;
    }
}