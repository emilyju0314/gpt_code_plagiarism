int mate_len(const bam1_t *rec)
{
  // Extract the insert length and check that it is nonzero.
  assert(rec->core.isize != 0);
  int ins_len = rec->core.isize;

  // Extract the (non-mate) read's start position, and check that it
  // is valid and that the read is indeed mapped.
  assert(rec->core.pos >= 0);
  assert(!(BAM_FUNMAP & rec->core.flag));
  int start = rec->core.pos + 1;

  // Extract the the mate's start position, and check that it is valid
  // and that the mate is indeed mapped.
  assert(rec->core.mpos >= 0);
  assert(!(BAM_FMUNMAP & rec->core.flag));
  int mate_start = rec->core.mpos + 1;

  // Actually compute the mate's length.
  int mate_len;
  if (ins_len > 0) {
    mate_len = ins_len + (start - mate_start);
  } else {
    mate_len = mate_start - (start + ins_len);
  }
  assert(mate_len > 0);

  return mate_len;
}