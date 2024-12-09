std::unique_ptr<HttpResponse> ControllableHttpResponse::RequestHandler(
    base::WeakPtr<ControllableHttpResponse> controller,
    scoped_refptr<base::SingleThreadTaskRunner> controller_task_runner,
    bool* available,
    const std::string& relative_url,
    bool relative_url_is_prefix,
    const HttpRequest& request) {
  if (!*available)
    return nullptr;

  if (request.relative_url == relative_url ||
      (relative_url_is_prefix &&
       base::StartsWith(request.relative_url, relative_url,
                        base::CompareCase::SENSITIVE))) {
    *available = false;
    return std::make_unique<ControllableHttpResponse::Interceptor>(
        controller, controller_task_runner, request);
  }

  return nullptr;
}