void mapLocalHttpResponseToError(uint64_t status, Http::ResponseHeaderMap& headers) {
  switch (status) {
  case 408:
    headers.addCopy(Http::InternalHeaders::get().ErrorCode, std::to_string(ENVOY_REQUEST_TIMEOUT));
    break;
  case 413:
    headers.addCopy(Http::InternalHeaders::get().ErrorCode,
                    std::to_string(ENVOY_BUFFER_LIMIT_EXCEEDED));
    break;
  case 503:
    headers.addCopy(Http::InternalHeaders::get().ErrorCode,
                    std::to_string(ENVOY_CONNECTION_FAILURE));
    break;
  default:
    headers.addCopy(Http::InternalHeaders::get().ErrorCode, std::to_string(ENVOY_UNDEFINED_ERROR));
  }

  headers.setStatus(218);
}