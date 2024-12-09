std::string
    resolve_public_ip_address()
    {
        using boost::asio::ip::tcp;

        // collect errors here
        exception_list errors;

        try {
            boost::asio::io_service io_service;
            tcp::resolver resolver(io_service);
            tcp::resolver::query query(boost::asio::ip::host_name(), "");
            tcp::resolver::iterator it = resolver.resolve(query);
            tcp::endpoint endpoint = *it;
            return endpoint.address().to_string();
        }
        catch (boost::system::system_error const&) {
            errors.add(boost::current_exception());
        }

        // report errors
        std::ostringstream strm;
        strm << errors.get_message()
                << " (while trying to resolve public ip address)";
        HPX_THROW_EXCEPTION(network_error, "util::resolve_public_ip_address",
            strm.str());
        return "";
    }