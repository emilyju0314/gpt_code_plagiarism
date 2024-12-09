Http2ErrorCode
http2_decode_header_blocks(HTTPHdr *hdr, const uint8_t *buf_start, const uint32_t buf_len, uint32_t *len_read, HpackHandle &handle,
                           bool &trailing_header, uint32_t maximum_table_size)
{
  const MIMEField *field;
  const char *value;
  int len;
  bool is_trailing_header = trailing_header;
  int64_t result = hpack_decode_header_block(handle, hdr, buf_start, buf_len, Http2::max_header_list_size, maximum_table_size);

  if (result < 0) {
    if (result == HPACK_ERROR_COMPRESSION_ERROR) {
      return Http2ErrorCode::HTTP2_ERROR_COMPRESSION_ERROR;
    } else if (result == HPACK_ERROR_SIZE_EXCEEDED_ERROR) {
      return Http2ErrorCode::HTTP2_ERROR_ENHANCE_YOUR_CALM;
    }

    return Http2ErrorCode::HTTP2_ERROR_PROTOCOL_ERROR;
  }
  if (len_read) {
    *len_read = result;
  }

  MIMEFieldIter iter;
  unsigned int expected_pseudo_header_count = 4;
  unsigned int pseudo_header_count          = 0;

  if (is_trailing_header) {
    expected_pseudo_header_count = 0;
  }
  for (auto &field : *hdr) {
    value = field.name_get(&len);
    // Pseudo headers must appear before regular headers
    if (len && value[0] == ':') {
      ++pseudo_header_count;
      if (pseudo_header_count > expected_pseudo_header_count) {
        return Http2ErrorCode::HTTP2_ERROR_PROTOCOL_ERROR;
      }
    } else if (len <= 0) {
      return Http2ErrorCode::HTTP2_ERROR_PROTOCOL_ERROR;
    } else {
      if (pseudo_header_count != expected_pseudo_header_count) {
        return Http2ErrorCode::HTTP2_ERROR_PROTOCOL_ERROR;
      }
    }
  }

  // rfc7540,sec8.1.2.2: Any message containing connection-specific header
  // fields MUST be treated as malformed
  if (hdr->field_find(MIME_FIELD_CONNECTION, MIME_LEN_CONNECTION) != nullptr ||
      hdr->field_find(MIME_FIELD_KEEP_ALIVE, MIME_LEN_KEEP_ALIVE) != nullptr ||
      hdr->field_find(MIME_FIELD_PROXY_CONNECTION, MIME_LEN_PROXY_CONNECTION) != nullptr ||
      hdr->field_find(MIME_FIELD_TRANSFER_ENCODING, MIME_LEN_TRANSFER_ENCODING) != nullptr ||
      hdr->field_find(MIME_FIELD_UPGRADE, MIME_LEN_UPGRADE) != nullptr) {
    return Http2ErrorCode::HTTP2_ERROR_PROTOCOL_ERROR;
  }

  // :path pseudo header MUST NOT empty for http or https URIs
  field = hdr->field_find(HTTP2_VALUE_PATH, HTTP2_LEN_PATH);
  if (field) {
    field->value_get(&len);
    if (len == 0) {
      return Http2ErrorCode::HTTP2_ERROR_PROTOCOL_ERROR;
    }
  }

  // turn on that we have a trailer header
  const char trailer_name[] = "trailer";
  field                     = hdr->field_find(trailer_name, sizeof(trailer_name) - 1);
  if (field) {
    trailing_header = true;
  }

  // when The TE header field is received, it MUST NOT contain any
  // value other than "trailers".
  field = hdr->field_find(MIME_FIELD_TE, MIME_LEN_TE);
  if (field) {
    value = field->value_get(&len);
    if (!(len == 8 && memcmp(value, "trailers", 8) == 0)) {
      return Http2ErrorCode::HTTP2_ERROR_PROTOCOL_ERROR;
    }
  }

  if (!is_trailing_header) {
    // Check pseudo headers
    if (hdr->fields_count() >= 4) {
      if (hdr->field_find(HTTP2_VALUE_SCHEME, HTTP2_LEN_SCHEME) == nullptr ||
          hdr->field_find(HTTP2_VALUE_METHOD, HTTP2_LEN_METHOD) == nullptr ||
          hdr->field_find(HTTP2_VALUE_PATH, HTTP2_LEN_PATH) == nullptr ||
          hdr->field_find(HTTP2_VALUE_AUTHORITY, HTTP2_LEN_AUTHORITY) == nullptr ||
          hdr->field_find(HTTP2_VALUE_STATUS, HTTP2_LEN_STATUS) != nullptr) {
        // Decoded header field is invalid
        return Http2ErrorCode::HTTP2_ERROR_PROTOCOL_ERROR;
      }
    } else {
      // Pseudo headers is insufficient
      return Http2ErrorCode::HTTP2_ERROR_PROTOCOL_ERROR;
    }
  }

  return Http2ErrorCode::HTTP2_ERROR_NO_ERROR;
}