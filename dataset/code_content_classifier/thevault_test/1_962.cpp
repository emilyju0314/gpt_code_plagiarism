void sendT4Val (CPHEADER& hcb, const Val& v, string vrb_key, 
		Serialization_e ser)
{
	// Up front error checking.
  if (hcb.type != 4000) throw logic_error(hcb.file_name + " is not type 4000");
  if (!hcb.open) return;
  
  VRB vrb;
  (void)m_vrbinit(vrb, 0, hcb.vrecord_length);

  // Serialize using one of a few serializations: default was OC
  // But by allowing P0 and P2, Python primitives can read
  Array<char> buff;
  DumpValToArray(v, buff, ser);
  int sz    = buff.length();
  char* buf = buff.data(); 
	
  //int_4 pval =
  (void)m_vrbput(vrb, vrb_key, buf, sz, 0, 'B');
  m_filad(hcb, &vrb, 1);
  
  m_vrbfree(vrb, 0);
}