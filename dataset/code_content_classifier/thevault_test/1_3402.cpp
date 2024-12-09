boost::asio::ip::tcp::endpoint
    resolve_hostname(std::string const& hostname, std::uint16_t port,
        boost::asio::io_service& io_service)
    {
        using boost::asio::ip::tcp;

        // collect errors here
        exception_list errors;

        // try to directly create an endpoint from the address
        try {
            tcp::endpoint ep;
            if (util::get_endpoint(hostname, port, ep))
                return ep;
        }
        catch (boost::system::system_error const&) {
            errors.add(boost::current_exception());
        }

        // it's not an address, try to treat it as a host name
        try {
            // resolve the given address
            tcp::resolver resolver(io_service);
            tcp::resolver::query query(hostname,
                std::to_string(port));

            boost::asio::ip::tcp::resolver::iterator it =
                resolver.resolve(query);
            HPX_ASSERT(it != boost::asio::ip::tcp::resolver::iterator());
            return *it;
        }
        catch (boost::system::system_error const&) {
            errors.add(boost::current_exception());
        }

        // report errors
        std::ostringstream strm;
        strm << errors.get_message() << " (while trying to resolve: "
             << hostname << ":" << port << ")";
        HPX_THROW_EXCEPTION(network_error, "util::resolve_hostname",
            strm.str());
        return tcp::endpoint();
    }