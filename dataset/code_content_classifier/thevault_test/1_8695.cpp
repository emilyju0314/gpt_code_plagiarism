bool
S3Request::set_header(const char *header, int header_len, const char *val, int val_len)
{
  if (!header || header_len <= 0 || !val || val_len <= 0) {
    return false;
  }

  bool ret         = false;
  TSMLoc field_loc = TSMimeHdrFieldFind(_bufp, _hdr_loc, header, header_len);

  if (!field_loc) {
    // No existing header, so create one
    if (TS_SUCCESS == TSMimeHdrFieldCreateNamed(_bufp, _hdr_loc, header, header_len, &field_loc)) {
      if (TS_SUCCESS == TSMimeHdrFieldValueStringSet(_bufp, _hdr_loc, field_loc, -1, val, val_len)) {
        TSMimeHdrFieldAppend(_bufp, _hdr_loc, field_loc);
        ret = true;
      }
      TSHandleMLocRelease(_bufp, _hdr_loc, field_loc);
    }
  } else {
    TSMLoc tmp = nullptr;
    bool first = true;

    while (field_loc) {
      tmp = TSMimeHdrFieldNextDup(_bufp, _hdr_loc, field_loc);
      if (first) {
        first = false;
        if (TS_SUCCESS == TSMimeHdrFieldValueStringSet(_bufp, _hdr_loc, field_loc, -1, val, val_len)) {
          ret = true;
        }
      } else {
        TSMimeHdrFieldDestroy(_bufp, _hdr_loc, field_loc);
      }
      TSHandleMLocRelease(_bufp, _hdr_loc, field_loc);
      field_loc = tmp;
    }
  }

  if (ret) {
    TSDebug(PLUGIN_NAME, "Set the header %.*s: %.*s", header_len, header, val_len, val);
  }

  return ret;
}