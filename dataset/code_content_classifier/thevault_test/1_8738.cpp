SPARQLQuery(PatternGroup g, int nvars, std::vector<ssid_t> &required_vars)
        : pattern_group(g) {
        result.nvars = nvars;
        result.required_vars = required_vars;
        result.v2c_map.resize(nvars, NO_RESULT);
    }