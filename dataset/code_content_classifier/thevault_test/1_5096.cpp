void ts::ExtendedEventDescriptor::splitAndAdd(DuckContext& duck, DescriptorList& dlist) const
{
    // Common data in all descriptors.
    ExtendedEventDescriptor eed;
    eed.language_code = language_code;
    eed.language_code.resize(3, SPACE);

    // We loop on new descriptor generation until all the following conditions are met:
    // - At least one descriptor was generated.
    // - All entries are serialized.
    // - The event text is fully serialized.
    // We fill each descriptor with complete entries. If an entry does not fit, start a new descriptor.
    // If one entry is so large that it does not fit in a descriptor alone, it is truncated.
    // The event text is potentially split into several descriptors.

    // Iterate over all entries.
    EntryList::const_iterator it = entries.begin();

    // Iterate over event text.
    size_t text_index = 0;

    size_t desc_count = 0;
    while (desc_count == 0 || it != entries.end() || text_index < text.length()) {

        // Create a new descriptor, reset variable fields, keep common fields.
        eed.entries.clear();
        eed.text.clear();

        // We simulate the serialization.
        uint8_t buffer[MAX_DESCRIPTOR_SIZE];

        // Descriptor binary size so far, from descriptor_tag to length_of_items, inclusive: 7 bytes.
        // Required minimum remaining space for text: 1 byte.
        size_t remain = MAX_DESCRIPTOR_SIZE - 8;

        // Insert as many item entries as possible
        while (it != entries.end()) {
            const ByteBlock desc(duck.toDVBWithByteLength(it->item_description));
            const ByteBlock item(duck.toDVBWithByteLength(it->item));
            if (desc.size() + item.size() > remain) {
                break;
            }
            eed.entries.push_back(*it);
            remain -= desc.size() + item.size();
            ++it;
        }

        // If first entry in current descriptor is too long to fit into one descriptor, truncate it.
        if (it != entries.end() && eed.entries.size() == 0) {
            Entry entry(*it);
            uint8_t* addr = buffer;
            const size_t desc_size = duck.toDVBWithByteLength(entry.item_description, addr, remain);
            const size_t item_size = duck.toDVBWithByteLength(entry.item, addr, remain);
            assert(desc_size <= entry.item_description.length());
            assert(item_size <= entry.item.length());
            entry.item_description.resize(desc_size);
            entry.item.resize(item_size);
            eed.entries.push_back(entry);
            ++it;
        }

        // In fact, there is one more remaining bytes, the text length.
        remain++;

        // Insert as much as possible of extended description
        uint8_t* addr = buffer;
        const size_t text_size = duck.toDVBWithByteLength(text, addr, remain, text_index);
        eed.text = text.substr(text_index, text_size);
        text_index += text_size;

        // Descriptor ready, add it in list
        dlist.add(duck, eed);
        desc_count++;
    }
}