void Error(const std::string& message) {
  Logger::Log(EVENT_ERROR, "%s", message.c_str());
  HttpResponse response;
  response.Reset(HttpConst::kStatus503, message);
  if (!CgiHandler::WriteResponse(response)) {
    Logger::Log(EVENT_ERROR, "CGI failed to write error response.");
  }
}