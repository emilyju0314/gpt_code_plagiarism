void ts::SignalizationDemux::handleSection(SectionDemux&, const Section& section)
{
    // We use this handler for ATSC System Time Table (STT) only.
    // This table violates the common usage rules of MPEG sections, see file tsSTT.h.
    if (_handler != nullptr && section.tableId() == TID_STT && hasTableId(TID_STT) && section.sourcePID() == PID_PSIP) {
        const STT stt(_duck, section);
        if (stt.isValid()) {
            _handler->handleSTT(stt, PID_PSIP);
        }
    }
}