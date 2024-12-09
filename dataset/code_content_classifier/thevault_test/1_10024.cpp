esp_err_t custom_prov_data_handler(uint32_t session_id, const uint8_t *inbuf, ssize_t inlen,
                                            uint8_t **outbuf, ssize_t *outlen, void *priv_data)
    {
        if (inbuf) {
            Log::info("Application", "Received data: ");
        }
        std::string response = "SUCCESS";
        *outbuf = reinterpret_cast<uint8_t*>(const_cast<char*>(response.c_str()));
        if (*outbuf == NULL) {
            Log::info("Application", "System out of memory");
            return ESP_ERR_NO_MEM;
        }
        *outlen = ssize_t(response.length() + 1); /* +1 for NULL terminating byte */

        return ESP_OK;
    }