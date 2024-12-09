const std::string tiramisu::computation::get_unique_name() const
{
    std::stringstream namestream;
    namestream << get_name();
    namestream << "@";
    namestream << (void *)this;
    return namestream.str();
}