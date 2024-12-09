size_t ts::DescriptorList::searchSubtitle(const UString& language, size_t start_index) const
{
    // Value to return if not found
    size_t not_found = count();

    for (size_t index = start_index; index < _list.size(); index++) {

        const DID tag =_list[index].desc->tag();
        const uint8_t* desc = _list[index].desc->payload();
        size_t size = _list[index].desc->payloadSize();

        if (tag == DID_SUBTITLING) {
            // DVB Subtitling Descriptor, always contain subtitles
            if (language.empty()) {
                return index;
            }
            else {
                not_found = count() + 1;
                while (size >= 8) {
                    if (language.similar(desc, 3)) {
                        return index;
                    }
                    desc += 8;
                    size -= 8;
                }
            }
        }
        else if (tag == DID_TELETEXT) {
            // DVB Teletext Descriptor, may contain subtitles
            while (size >= 5) {
                // Get teletext type:
                //   0x02: Teletext subtitles
                //   0x05: Teletext subtitles for hearing impaired
                uint8_t tel_type = desc[3] >> 3;
                if (tel_type == 0x02 || tel_type == 0x05) {
                    // This is a teletext containing subtitles
                    if (language.empty()) {
                        return index;
                    }
                    else {
                        not_found = count() + 1;
                        if (language.similar(desc, 3)) {
                            return index;
                        }
                    }
                }
                desc += 5;
                size -= 5;
            }
        }
    }

    return not_found;
}