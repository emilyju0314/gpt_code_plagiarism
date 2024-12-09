constexpr bool lazy_concept_checker(auto fun)
{
    auto fallback = []<typename T = int>(auto)
    {
        return std::false_type{};
    };
    using ret_t = decltype(detail::overloaded{fallback, fun}(1));
    return ret_t::value;
}