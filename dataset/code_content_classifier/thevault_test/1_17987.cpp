sed_mz_uint sed_tdefl_create_comp_flags_from_zip_params(int level, int window_bits, int strategy)
{
  sed_mz_uint comp_flags = s_sed_tdefl_num_probes[(level >= 0) ? sed_mz_MIN(10, level) : sed_mz_DEFAULT_LEVEL] | ((level <= 3) ? sed_tdefl_GREEDY_PARSING_FLAG : 0);
  if (window_bits > 0) comp_flags |= sed_tdefl_WRITE_ZLIB_HEADER;

  if (!level) comp_flags |= sed_tdefl_FORCE_ALL_RAW_BLOCKS;
  else if (strategy == sed_mz_FILTERED) comp_flags |= sed_tdefl_FILTER_MATCHES;
  else if (strategy == sed_mz_HUFFMAN_ONLY) comp_flags &= ~sed_tdefl_MAX_PROBES_MASK;
  else if (strategy == sed_mz_FIXED) comp_flags |= sed_tdefl_FORCE_ALL_STATIC_BLOCKS;
  else if (strategy == sed_mz_RLE) comp_flags |= sed_tdefl_RLE_MATCHES;

  return comp_flags;
}