std::string to_string(auto && in)
{
    using in_t = std::remove_cvref_t<decltype(in)>;
    if constexpr (seqan3::arithmetic<in_t>)
        return std::to_string(in);
    else if constexpr (std::same_as<in_t, std::string>)
        return in;
    else if constexpr (std::constructible_from<std::string, in_t>)
        return std::string{in};
    else
        static_assert(std::constructible_from<std::string, in_t>, "Type cannot be converted to string");
}