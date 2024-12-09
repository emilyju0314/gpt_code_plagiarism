const StringList Utils::getConfig(const std::string& config)
{
    StringList result;
    try
    {
        std::ifstream file;

        file.open(config.c_str(), std::ifstream::in);

        if (file.fail())
        {
            throw Exception(__FILE__, __LINE__,
                                 "Error %d in open(): %s. File name: '%s'",
                                 errno, strerror(errno), config.c_str());
        }

        while (file.good())
        {
            char buff[1024];
            file.getline(buff, sizeof(buff));
            std::string line = buff;

            // remove comments
            std::string::size_type pos = line.find('#');
            if (pos != std::string::npos)
                line.erase(pos, std::string::npos);
            // remove garbage
            boost::trim_if(line,  boost::is_any_of(" \r\n\t"));
            if (line.empty())
            {
                continue; // ignore it
            }

            result.push_back(line);
        }

        file.close();
    }
    catch(Exception& err)
    {
        throw err;
    }
    catch (std::out_of_range&)
    {
        throw Exception(__FILE__, __LINE__, err::OUTRANGE);
    }
    catch(...)
    {
        throw Exception(__FILE__, __LINE__, err::UNSPECIFIED);
    }

    return result;
}