void Server::send_http_json_response(struct mg_connection *nc, const Json::Value& response, int code, const string& reason) {
    if (response == Json::nullValue) {
        send_http_error(nc, 404, "Not Found");
    } else {
        //string buf = response.toStyledString();
        Json::StreamWriterBuilder wbuilder;
        //wbuilder["indentation"] = "\t";
        std::string buf = Json::writeString(wbuilder, response);
        //string buf = response.asString();

        mg_printf(nc, "HTTP/1.1 %d %s\r\n"
                          "Content-Length: %d\r\n"
                          "Content-Type: application/json\r\n\r\n"
                          "%s",
                  code, reason.c_str(),
                  (int) buf.size(), buf.c_str());
    }
}