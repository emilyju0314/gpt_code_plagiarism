pplx::task<void> HTTPStreamingAsync()
{
    http_client client(U("http://www.fourthcoffee.com"));

    // Make the request and asynchronously process the response. 
    return client.request(methods::GET).then([](http_response response)
    {
        // Print the status code.
        std::wostringstream ss;
        ss << U("Server returned returned status code ") << response.status_code() << U('.') << std::endl;
        std::wcout << ss.str();

        // TODO: Perform actions here reading from the response stream.
        auto bodyStream = response.body();

        // In this example, we print the length of the response to the console.
        ss.str(std::wstring());
        ss << U("Content length is ") << response.headers().content_length() << U(" bytes.") << std::endl;
        std::wcout << ss.str();
    });

    /* Sample output:
    Server returned returned status code 200.
    Content length is 63803 bytes.
    */
}