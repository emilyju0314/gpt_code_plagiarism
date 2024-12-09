bad_cast::bad_cast(const std::type_info& from, const std::type_info& to) :
    what_m("bad_cast: ")
{
    what_m << from.name() << " -> " << to.name();
}