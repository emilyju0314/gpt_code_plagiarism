size_t ts::DescriptorList::searchLanguage(const UString& language, size_t start_index) const
{
    for (size_t index = start_index; index < _list.size(); index++) {
        if (_list[index].desc->tag() == DID_LANGUAGE) {
            // Got a language descriptor
            const uint8_t* desc = _list[index].desc->payload();
            size_t size = _list[index].desc->payloadSize();
            // The language code uses 3 bytes after the size
            if (size >= 3 && language.similar(desc, 3)) {
                return index;
            }
        }
    }

    return count(); // not found
}