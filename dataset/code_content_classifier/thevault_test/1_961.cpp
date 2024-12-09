void initT4Val (CPHEADER& hcb, string name, int_4 hcbfmode)
{
  m_init(hcb, name, "4000", "", 0);
  if ((hcbfmode & HCBF_INPUT) == HCBF_INPUT) {
    m_open(hcb, hcbfmode);
    
    // Setup to grab 1 vrb at a time and non-blocking.
    hcb.xfer_len = 1;
    hcb.cons_len = -2;
  }
  else if ((hcbfmode & HCBF_OUTPUT) == HCBF_OUTPUT) {
    hcbfmode |= HCBF_NOABORT;
    m_open(hcb, hcbfmode);
    hcb.vrecord_length = 0;
  }
  else {
    m_error("[initT4Val]: HCBF mode not specified.");
  }
}