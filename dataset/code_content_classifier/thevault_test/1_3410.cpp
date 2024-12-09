std::string batch_environment::init_from_nodelist(
        std::vector<std::string> const& nodes,
        std::string const& agas_host)
    {
        if (debug_)
            std::cerr << "got node list" << std::endl;

        boost::asio::io_service io_service;

        bool found_agas_host = false;
        std::size_t agas_node_num = 0;
        std::string nodes_list;
        for (std::string s : nodes)
        {
            if (!s.empty()) {
                if (debug_)
                    std::cerr << "extracted: '" << s << "'" << std::endl;

                boost::asio::ip::tcp::endpoint ep =
                    util::resolve_hostname(s, 0, io_service);

                if (!found_agas_host &&
                    ((agas_host.empty() && nodes_.empty()) || s == agas_host))
                {
                    agas_node_ = s;
                    found_agas_host = true;
                    agas_node_num_ = agas_node_num;
                }

                if (0 == nodes_.count(ep)) {
                    if (debug_)
                        std::cerr << "incrementing agas_node_num" << std::endl;
                    ++agas_node_num;
                }

                std::pair<std::string, std::size_t>& data = nodes_[ep];
                if (data.first.empty())
                    data.first = s;
                ++data.second;

                nodes_list += s + ' ';
            }
        }

        // if an AGAS host is specified, it needs to be in the list
        // of nodes participating in this run
        if (!agas_host.empty() && !found_agas_host) {
            throw hpx::detail::command_line_error("Requested AGAS host (" + agas_host +
                ") not found in node list");
        }

        if (debug_) {
            if (!agas_node_.empty()) {
                std::cerr << "using AGAS host: '" << agas_node_
                    << "' (node number " << agas_node_num_ << ")" << std::endl;
            }

            std::cerr << "Nodes from nodelist:" << std::endl;
            node_map_type::const_iterator end = nodes_.end();
            for (node_map_type::const_iterator it = nodes_.begin();
                 it != end; ++it)
            {
                std::cerr << (*it).second.first << ": "
                    << (*it).second.second << " (" << (*it).first << ")"
                    << std::endl;
            }
        }
        return nodes_list;
    }