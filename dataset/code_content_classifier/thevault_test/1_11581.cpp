P1VectorVTKFunction(const GV& gv, const V &v_, const std::string &s_,
                        int ncomps = 1)
        : v(v_), s(s_), ncomps_(ncomps), mapper(gv)
    {
        if (v.size() != (unsigned int)(mapper.size() * ncomps_))
            DUNE_THROW(Dune::IOError, "P1VectorVTKFunction: size mismatch");
    }