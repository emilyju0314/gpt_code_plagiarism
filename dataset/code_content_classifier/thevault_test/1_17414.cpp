detail::bcf_type_descriptor smallest_int_desc(std::unsigned_integral auto const num)
{
    // bits required to represent number (the +1 because signed integral has smaller range)
    switch (std::bit_ceil(std::bit_width(num) + 1))
    {
        case 128:
        case 64:
            throw bio_error{"Could not write number '", num, "'. Value out of range (only int32 supported)."};
            return {};
        case 32:
            return detail::bcf_type_descriptor::int32;
        case 16:
            return detail::bcf_type_descriptor::int16;
        default:
            return detail::bcf_type_descriptor::int8;
    }
}