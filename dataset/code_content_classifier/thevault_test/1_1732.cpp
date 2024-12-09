LineParser::ParseResult CLFParser::Parse(const char* line, UrlRecord* record) {
  if (line == NULL || record == NULL) return PARSE_FAIL;

  if (SplitEntries(line) == false) return PARSE_FAIL;

  // handle date, like [10/Oct/2000:13:55:36 -0700]
  if (!ParseTime(entries_[3].c_str(), &record->last_access)) {
    return PARSE_FAIL;
  }
  if (record->last_access <= oldest()) {
    return PARSE_IGNORE;
  }

  // handle request, like "GET /page HTTP/1.0"
  ParseResult result = ParseRequest(entries_[4].c_str(), record->url);
  if (result != PARSE_OK) return result;

  // handle status and bytes
  record->statuscode = atoi(entries_[5].c_str());
  record->contentHashCode = atoi(entries_[6].c_str());

  // Set attributes, which can't be determined by CLF parser.
  record->host[0] = '\0';
  record->last_filewrite = -1;
  record->last_modified = -1;
  record->siteid[0] = '\0';

  return PARSE_OK;
}