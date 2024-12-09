std::codecvt_base::result do_unshift(std::mbstate_t&, char* from,
            char* /*to*/, char*& next) const override
        {
            next = from;
            return ok;
        }