void lf_dump(FILE *dumpf, lf_entry *dumpme)
{
  char addr1buf[128], addr2buf[128];

  lf_convert_order(dumpme);
  lf_ntoa(dumpme->cip, addr1buf);
  lf_ntoa(dumpme->sip, addr2buf);
  fprintf(dumpf, "%lu:%lu %lu:%lu %lu:%lu %s:%hu %s:%hu %u %u ",
	  dumpme->crs, dumpme->cru, dumpme->srs, dumpme->sru,
	  dumpme->sls, dumpme->slu, addr1buf, dumpme->cpt,
	  addr2buf, dumpme->spt, dumpme->cprg, dumpme->sprg);
  fprintf(dumpf, "%lu %lu %lu %lu %lu %u %s\n",
	  dumpme->cims, dumpme->sexp, dumpme->slmd, dumpme->rhl,
	  dumpme->rdl, dumpme->urllen, dumpme->url);
  lf_convert_order(dumpme);
}