int  lf_write(FILE *outf, lf_entry *writeme)
{
  unsigned char blockbuf[60];
  int           uln, ret;

  memcpy( blockbuf+0, &(writeme->crs),   4);
  memcpy( blockbuf+4, &(writeme->cru),   4);
  memcpy( blockbuf+8, &(writeme->srs),   4);
  memcpy( blockbuf+12, &(writeme->sru),  4);
  memcpy( blockbuf+16, &(writeme->sls),  4);
  memcpy( blockbuf+20, &(writeme->slu),  4);
  memcpy( blockbuf+24, &(writeme->cip),  4);
  memcpy( blockbuf+28, &(writeme->cpt),  2);
  memcpy( blockbuf+30, &(writeme->sip),  4);
  memcpy( blockbuf+34, &(writeme->spt),  2);
  memcpy( blockbuf+36, &(writeme->cprg), 1);
  memcpy( blockbuf+37, &(writeme->sprg), 1);
  memcpy( blockbuf+38, &(writeme->cims), 4);
  memcpy( blockbuf+42, &(writeme->sexp), 4);
  memcpy( blockbuf+46, &(writeme->slmd), 4);
  memcpy( blockbuf+50, &(writeme->rhl),  4);
  memcpy( blockbuf+54, &(writeme->rdl),  4);
  memcpy( blockbuf+58, &(writeme->urllen), 2);

  ret = fwrite(&(blockbuf[0]), 60, 1, outf);
  if (ret != 1) {
    fprintf(stderr, "write 60 failed...%d\n", ret);
    perror("arrgh1");
    return 1;
  }

  /* Now let's write out that url */
  uln = ntohs(writeme->urllen);
  ret = fwrite(writeme->url, (size_t) uln, 1, outf);
  if (ret != 1) {
    fprintf(stderr, "write of %d failed %d\n", uln, ret);
    perror("aargh.");
    return 2;
  }
  return 0;
}