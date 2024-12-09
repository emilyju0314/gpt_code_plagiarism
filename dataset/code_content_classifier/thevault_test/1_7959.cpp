std::vector<Byte> GetSectionBytes(ea_t segment_start_address) {
  std::vector<Byte> bytes;
  const segment_t* ida_segment = getseg(segment_start_address);
  if (ida_segment && is_loaded(ida_segment->start_ea)) {
    const ea_t undefined_bytes =
        next_that(ida_segment->start_ea, ida_segment->end_ea, HasNoValue,
                 nullptr /* user data */);
    bytes.resize(
        (undefined_bytes == BADADDR ? ida_segment->end_ea : undefined_bytes) -
        ida_segment->start_ea);
    get_bytes(&bytes[0], bytes.size(), ida_segment->start_ea);
  }
  return bytes;
}