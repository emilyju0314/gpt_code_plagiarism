static size_t curl_cb_stream(
    /** [in] Pointer to the result. */
    char* ptr,
    /** [in] Size each chunk of the result. */
    size_t size,
    /** [in] Number of chunks in the result. */
    size_t nmemb,
    /** [out] Response (a pointer to `std::iostream`). */
    void* response_void) {
  std::iostream* response = static_cast<std::iostream*>(response_void);

  const size_t n = size * nmemb;

  response->write(ptr, n);

  return n;
}