static void ink_web_dump_url_components(FILE *fp, InkWebURLComponents *c)
{
  fprintf(fp,"sche:'%s', exists %d\n",c->sche,c->sche_exists);
  fprintf(fp,"host:'%s', exists %d\n",c->host,c->host_exists);
  fprintf(fp,"port:'%s', exists %d\n",c->port,c->port_exists);
  fprintf(fp,"path:'%s', exists %d\n",c->path,c->path_exists);
  fprintf(fp,"quer:'%s', exists %d\n",c->quer,c->quer_exists);
  fprintf(fp,"frag:'%s', exists %d\n",c->frag,c->frag_exists);
  fprintf(fp,"para:'%s', exists %d\n",c->para,c->para_exists);

  fprintf(fp,"rel_url:%d\n",c->rel_url);
  fprintf(fp,"leading_slash:%d\n",c->leading_slash);

  fprintf(fp,"\n");
}