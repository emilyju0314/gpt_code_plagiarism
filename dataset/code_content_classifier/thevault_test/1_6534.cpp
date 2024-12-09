void dump_buf(FILE *std, char *buf, int retlen)
{
  int i, j;

  for (i=0; i<retlen/5; i++) {
    for (j=0; j<5; j++) {
      fprintf(std, "%.02x ", *(buf + (unsigned) 5*i + j));
    }
    fprintf(std, "     ");
    for (j=0; j<5; j++) {
      fprintf(std, "%c ", *(buf + (unsigned) 5*i + j));
    }
    fprintf(std, "\n");
  }
  if (retlen % 5 != 0) {
    for (j=0; j < retlen % 5; j++) {
      fprintf(std, "%.02x ", *(buf + (unsigned) 5*(retlen/5) + j));
    }
    fprintf(std, "     ");
    for (j=0; j<5; j++) {
      fprintf(std, "%c ", *(buf + (unsigned) 5*i + j));
    }
    fprintf(std, "\n");
  }
}