const char *lmmacro::maxsuffptr(ngram micro_ng, unsigned int* size)
{
  ngram macro_ng(lmtable::getDict());

  if (micro_ng.dict ==  macro_ng.dict)
    macro_ng.trans(micro_ng);  // micro to macro mapping already done
  else
    map(&micro_ng, &macro_ng); // mapping required

  VERBOSE(2,"lmmacro::lprob: micro_ng = " << micro_ng << "\n"
          << "lmmacro::lprob: macro_ng = " << macro_ng << "\n");

  return lmtable::maxsuffptr(macro_ng,size);
}