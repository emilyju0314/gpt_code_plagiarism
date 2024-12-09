bool recvT4Tab (CPHEADER& hcb, Tab& t, string vrb_key, Serialization_e ser)
{
  Val v;
  if (recvT4Val(hcb, v, vrb_key), ser) {
    if (v.tag == 't') {
      t = v;
      return true;
    }
  }
  else {
    return false;
  }
  
  return false;
}