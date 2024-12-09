bool recvT4Val (CPHEADER& hcb, Val& v, string vrb_key, Serialization_e ser)
{
  // Up front error checking.
  if (hcb.type != 4000) throw logic_error(hcb.file_name + " is not type 4000");
  // Per JDG: If users want non-blocking, let them
  // if (hcb.cons_len > -2) throw logic_error(hcb.file_name + " uses blocking grabs");
  if (!hcb.open) return false;

  v = None; // clear out old value
  int ngot;
  VRB vrb;
  Array<char> cut_buf(MAX_BUF_SIZE);

  (void)m_vrbinit(vrb, 0, -1);
  m_vrbclr(vrb, 0);
  m_grabx(hcb, &vrb, ngot);
	
	// A successful ngot is of hcb.xfer_len, which is 1.
  if (ngot != 1) {
    m_vrbfree(vrb, 0);
    return false;
  }

  void* in_buf;
  int_4 mbs = MAX_BUF_SIZE;
  char fmt = 'B';
  int_4 buf_size = m_vrbfind(vrb, vrb_key, in_buf, mbs, 0, fmt);
  if (buf_size != -1) {
    cut_buf.expandTo(buf_size);
    int num_bytes = m_vrbget(vrb, vrb_key, &cut_buf[0], 
			     buf_size, 0, fmt);
    try {
      LoadValFromArray(cut_buf, v, ser); 
      m_vrbfree(vrb, 0);
      return (v.tag != 'Z');
    } catch (exception& e) {
      cerr << "[recvT4Val] " << e.what() << endl;
      m_vrbfree(vrb, 0);
      return false;
    }
  }

  m_vrbfree(vrb, 0);
  return false;
}