std::string convert_delimiters(std::string paths)
        {
#if defined(HPX_WINDOWS)
            std::replace(paths.begin(), paths.end(), ':', ';');
#endif
            return paths;
        }