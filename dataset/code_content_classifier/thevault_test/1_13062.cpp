pplx::task<void> HTTPRequestCustomHeadersAsync()
{
    http_client client(U("http://www.fourthcoffee.com"));

    // Manually build up an HTTP request with header and request URI.
    http_request request(methods::GET);
    request.headers().add(U("MyHeaderField"), U("MyHeaderValue"));
    request.set_request_uri(U("requestpath"));
    return client.request(request).then([](http_response response)
    {
        // Print the status code.
        std::wostringstream ss;
        ss << U("Server returned returned status code ") << response.status_code() << U(".") << std::endl;
        std::wcout << ss.str();
    });

    /* Sample output:
    Server returned returned status code 200.
    */
}