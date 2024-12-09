void Server::send_http_response(struct mg_connection *nc, const std::vector<uint8_t>& response, const string& type) {
    if ( response.size() == 0) {
        send_http_error(nc, 404, "Not Found");
    } else {
        mg_printf(nc, "HTTP/1.1 200 OK\r\n"
                          "Content-Length: %u\r\n"
                          "Content-Type: %s\r\n\r\n",
                  (unsigned) response.size(), type.c_str());
        mg_send(nc, &response[0], response.size());
    }
}