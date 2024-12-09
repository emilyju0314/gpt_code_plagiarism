void ts::ParentalRatingDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    while (size >= 4) {
        const uint8_t rating = data[3];
        strm << margin << "Country code: " << DeserializeLanguageCode(data)
             << UString::Format(u", rating: 0x%X ", {rating});
        if (rating == 0) {
            strm << "(undefined)";
        }
        else if (rating <= 0x0F) {
            strm << "(min. " << int(rating + 3) << " years)";
        }
        else {
            strm << "(broadcaster-defined)";
        }
        strm << std::endl;
        data += 4; size -= 4;
    }

    display.displayExtraData(data, size, indent);
}