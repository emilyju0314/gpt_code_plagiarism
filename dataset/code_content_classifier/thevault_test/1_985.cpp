inline void P2DumpTable (const OpalTable& t, DumpContext_& dc)
{
  const int len = t.entries();
  *(dc.mem)++ = PY_EMPTY_DICT;
  
  if (len!=0)  { // Empty Table just single }
    
    if (len!=1) *(dc.mem)++ = '(';

    OpalTableIterator ii(t);
    while (ii()) {
      const string& key = ii.key();
      const OpalValue value = ii.value();
      dumpString(key, dc);
      P2DumpValue(value, dc);
    }
    
    *(dc.mem)++ = (len==1) ? PY_SETITEM : PY_SETITEMS;
  }
}