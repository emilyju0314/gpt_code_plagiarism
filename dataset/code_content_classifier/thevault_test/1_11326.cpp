inline std::string serializeToStr(SEXP object) {
    // using R's C API, all SEXP objects will be serialized into a raw vector
    Rcpp::RawVector val = serializeToRaw(object);

    // convert R raw vector into a std::string
    std::string res;

    for (size_t i = 0; i < val.size(); i++) {
        res = res + std::to_string(int(val[i])) + "\t";
    }

    return res;
}