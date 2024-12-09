void ts::UString::appendDump(const void *data,
                             size_type size,
                             uint32_t flags,
                             size_type indent,
                             size_type line_width,
                             size_type init_offset,
                             size_type inner_indent)
{
    const uint8_t* raw = static_cast<const uint8_t*>(data);

    // Make sure we have something to display (default is hexa)
    if ((flags & (HEXA | C_STYLE | BINARY | BIN_NIBBLE | ASCII)) == 0) {
        flags |= HEXA;
    }
    if ((flags & COMPACT) != 0) {
        // COMPACT implies SINGLE_LINE.
        flags |= SINGLE_LINE;
    }

    // Width of an hexa byte: "XX" (2) or "0xXX," (5)
    size_type hexa_width = 0;
    UString byte_prefix;
    UString byte_suffix;

    if (flags & C_STYLE) {
        hexa_width  = 5;
        byte_prefix = u"0x";
        byte_suffix = u",";
        flags |= HEXA; // Enforce hexa flag
    }
    else if (flags & (HEXA | SINGLE_LINE)) {
        hexa_width  = 2;
    }
    else {
        hexa_width  = 0;
    }

    // Specific case: simple dump, everything on one line.
    if (flags & SINGLE_LINE) {
        reserve(length() + (hexa_width + 1) * size);
        for (size_type i = 0; i < size; ++i) {
            if (i > 0 && (flags & COMPACT) == 0) {
                append(1, u' ');
            }
            append(byte_prefix);
            append(Hexa(raw[i], 0, UString(), false, true));
            append(byte_suffix);
        }
        return;
    }

    // Width of offset field
    size_type offset_width;

    if ((flags & OFFSET) == 0) {
        offset_width = 0;
    }
    else if (flags & WIDE_OFFSET) {
        offset_width = 8;
    }
    else if (init_offset + size <= 0x10000) {
        offset_width = 4;
    }
    else {
        offset_width = 8;
    }

    // Width of a binary byte
    size_type bin_width;

    if (flags & BIN_NIBBLE) {
        bin_width = 9;
        flags |= BINARY;  // Enforce binary flag
    }
    else if (flags & BINARY) {
        bin_width = 8;
    }
    else {
        bin_width = 0;
    }

    // Pre-allocation to avoid too frequent reallocations.
    reserve(length() + indent + inner_indent + (hexa_width + bin_width + 5) * size);

    // Number of non-byte characters
    size_type add_width = indent + inner_indent;
    if (offset_width != 0) {
        add_width += offset_width + 3;
    }
    if ((flags & HEXA) && (flags & (BINARY | ASCII))) {
        add_width += 2;
    }
    if ((flags & BINARY) && (flags & ASCII)) {
        add_width += 2;
    }

    // Computes max number of dumped bytes per line
    size_type bytes_per_line;

    if (flags & BPL) {
        bytes_per_line = line_width;
    }
    else if (add_width >= line_width) {
        bytes_per_line = 8;  // arbitrary, if indent is too long
    }
    else {
        bytes_per_line = (line_width - add_width) /
            (((flags & HEXA) ? (hexa_width + 1) : 0) +
             ((flags & BINARY) ? (bin_width + 1) : 0) +
             ((flags & ASCII) ? 1 : 0));
        if (bytes_per_line > 1) {
            bytes_per_line = bytes_per_line & ~1; // force even value
        }
    }
    if (bytes_per_line == 0) {
        bytes_per_line = 8;  // arbitrary, if ended up with none
    }

    // Display data
    for (size_type line = 0; line < size; line += bytes_per_line) {

        // Number of bytes on this line (last line may be shorter)
        size_type line_size = line + bytes_per_line <= size ? bytes_per_line : size - line;

        // Beginning of line
        append(indent, u' ');
        if (flags & OFFSET) {
            append(Hexa(init_offset + line, offset_width, UString(), false, true));
            append(u":  ");
        }
        append(inner_indent, u' ');

        // Hexa dump
        if (flags & HEXA) {
            for (size_type byte = 0; byte < line_size; byte++) {
                append(byte_prefix);
                append(Hexa(raw[line + byte], 0, UString(), false, true));
                append(byte_suffix);
                if (byte < bytes_per_line - 1) {
                    append(1, u' ');
                }
            }
            if (flags & (BINARY | ASCII)) { // more to come
                if (line_size < bytes_per_line) {
                    append((hexa_width + 1) * (bytes_per_line - line_size) - 1, u' ');
                }
                append(2, u' ');
            }
        }

        // Binary dump
        if (flags & BINARY) {
            for (size_type byte = 0; byte < line_size; byte++) {
                int b = int(raw[line + byte]);
                for (int i = 7; i >= 0; i--) {
                    append(1, UChar(u'0' + ((b >> i) & 0x01)));
                    if (i == 4 && (flags & BIN_NIBBLE) != 0) {
                        append(1, u'.');
                    }
                }
                if (byte < bytes_per_line - 1) {
                    append(1, u' ');
                }
            }
            if (flags & ASCII) { // more to come
                if (line_size < bytes_per_line) {
                    append((bin_width + 1) * (bytes_per_line - line_size) - 1, u' ');
                }
                append(2, u' ');
            }
        }

        // ASCII dump
        if (flags & ASCII) {
            for (size_type byte = 0; byte < line_size; byte++) {
                // Display only ASCII characters. Other encodings don't make sense on one bytes.
                const UChar c = UChar(raw[line + byte]);
                push_back(c >= 0x20 && c <= 0x7E ? c : u'.');
            }
        }

        // Insert a new-line, cleanup spurious spaces.
        while (!empty() && back() == u' ') {
            pop_back();
        }
        push_back(u'\n');
    }
}