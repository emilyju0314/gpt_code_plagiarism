std::string TypeToString(const ahoy::internal::Type& type) {
    std::stringstream ss;
    ss << type;
    return ss.str();
}