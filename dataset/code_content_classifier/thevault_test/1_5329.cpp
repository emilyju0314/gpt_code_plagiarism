ts::UString ts::UString::Dump(const void *data,
                              size_type size,
                              uint32_t flags,
                              size_type indent,
                              size_type line_width,
                              size_type init_offset,
                              size_type inner_indent)
{
    UString s;
    s.appendDump(data, size, flags, indent, line_width, init_offset, inner_indent);
    return s;
}