void lf_convert_order(lf_entry *convertme)
{
  convertme->crs = ntohl(convertme->crs);
  convertme->cru = ntohl(convertme->cru);
  convertme->srs = ntohl(convertme->srs);
  convertme->sru = ntohl(convertme->sru);
  convertme->sls = ntohl(convertme->sls);
  convertme->slu = ntohl(convertme->slu);
  convertme->cip = ntohl(convertme->cip);
  convertme->cpt = ntohs(convertme->cpt);
  convertme->sip = ntohl(convertme->sip);
  convertme->spt = ntohs(convertme->spt);
  convertme->cims = ntohl(convertme->cims);
  convertme->sexp = ntohl(convertme->sexp);
  convertme->slmd = ntohl(convertme->slmd);
  convertme->rhl = ntohl(convertme->rhl);
  convertme->rdl = ntohl(convertme->rdl);
  convertme->urllen = ntohs(convertme->urllen);
}