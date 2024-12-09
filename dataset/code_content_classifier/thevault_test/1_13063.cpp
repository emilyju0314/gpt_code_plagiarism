pplx::task<void> UploadFileToHttpServerAsync()
{
    using concurrency::streams::file_stream;
    using concurrency::streams::basic_istream;

    // To run this example, you must have a file named myfile.txt in the current folder. 
    // Alternatively, you can use the following code to create a stream from a text string. 
    // std::string s("abcdefg");
    // auto ss = concurrency::streams::stringstream::open_istream(s); 

    // Open stream to file. 
    return file_stream<unsigned char>::open_istream(U("myfile.txt")).then([](pplx::task<basic_istream<unsigned char>> previousTask)
    {
        try
        {
            auto fileStream = previousTask.get();

            // Make HTTP request with the file stream as the body.
            http_client client(U("http://www.fourthcoffee.com"));
            return client.request(methods::PUT, U("myfile"), fileStream).then([fileStream](pplx::task<http_response> previousTask)
            {
                fileStream.close();

                std::wostringstream ss;
                try
                {
                    auto response = previousTask.get();
                    ss << U("Server returned returned status code ") << response.status_code() << U(".") << std::endl;
                }
                catch (const http_exception& e)
                {
                    ss << e.what() << std::endl;
                }
                std::wcout << ss.str();
            });
        }
        catch (const std::system_error& e)
        {
            std::wostringstream ss;
            ss << e.what() << std::endl;
            std::wcout << ss.str();

            // Return an empty task. 
            return pplx::task_from_result();
        }
    });

    /* Sample output:
    The request must be resent
    */
}