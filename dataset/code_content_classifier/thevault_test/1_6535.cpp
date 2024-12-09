ts_strtok_state *ts_strtok_init(char *string)
{
  ts_strtok_state *retval;

  if (string == NULL)
    return NULL;

  retval = (ts_strtok_state *) malloc(sizeof(ts_strtok_state));
  if (retval == NULL)
    return NULL;

  retval->string_dupe = strdup(string);
  if (retval->string_dupe == NULL) {
    free(retval);
    return NULL;
  }
  retval->nxt_ptr = retval->string_dupe;
  retval->chars_remaining = strlen(retval->string_dupe);

  return retval;
}