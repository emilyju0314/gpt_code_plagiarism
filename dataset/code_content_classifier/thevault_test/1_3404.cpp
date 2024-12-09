bool split_ip_address(std::string const& v, std::string& host,
        std::uint16_t& port)
    {
        std::string::size_type p = v.find_first_of(":");

        std::string tmp_host;
        std::uint16_t tmp_port = 0;

        try {
            if (p != std::string::npos) {
                tmp_host = v.substr(0, p);
                tmp_port = boost::lexical_cast<std::uint16_t>(v.substr(p+1));
            }
            else {
                tmp_host = v;
            }

            if (!tmp_host.empty()) {
                host = tmp_host;
                if (tmp_port)
                    port = tmp_port;
            }
        }
        catch (boost::bad_lexical_cast const& /*e*/) {
            // port number is invalid
            return false;
        }
        return true;
    }