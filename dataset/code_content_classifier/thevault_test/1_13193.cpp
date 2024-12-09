luna::response make_response_(luna::response &&response, luna::headers &headers_)
{
    for(const auto header : headers_)
    {
        // don't override anything already here
        if(response.headers.count(header.first) == 0)
        {
            response.headers[header.first] = header.second;
        }
    }
    return response;
}