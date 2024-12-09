static void
ink_web_decompose_url_into_structure(const char *url, InkWebURLComponents *c)
{
  ink_web_decompose_url(url, c->sche, c->host, c->port, c->path, c->frag, c->quer, c->para, &(c->sche_exists), &(c->host_exists),
                        &(c->port_exists), &(c->path_exists), &(c->frag_exists), &(c->quer_exists), &(c->para_exists),
                        &(c->rel_url), &(c->leading_slash));

  c->is_path_name = 1;
  if (c->sche_exists &&
      ((strcasecmp(c->sche, "mailto") == 0) || (strcasecmp(c->sche, "telnet") == 0) || (strcasecmp(c->sche, "news") == 0))) {
    c->is_path_name = 0;
  }
}