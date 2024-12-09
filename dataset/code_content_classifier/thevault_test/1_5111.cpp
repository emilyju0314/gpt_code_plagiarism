bool ts::PMT::Stream::getComponentTag(uint8_t& tag) const
{
    // Loop on all stream_identifier_descriptors until a valid one is found.
    for (size_t i = descs.search(DID_STREAM_ID); i < descs.count(); i = descs.search(DID_STREAM_ID, i + 1)) {
        if (!descs[i].isNull() && descs[i]->payloadSize() >= 1) {
            // The payload of the stream_identifier_descriptor contains only one byte, the component tag.
            tag = descs[i]->payload()[0];
            return true;
        }
    }
    return false;
}