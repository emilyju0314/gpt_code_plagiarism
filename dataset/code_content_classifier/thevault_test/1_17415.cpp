inline bool type_descriptor_is_int(bcf_type_descriptor const type_desc)
{
    switch (type_desc)
    {
        case bcf_type_descriptor::int8:
        case bcf_type_descriptor::int16:
        case bcf_type_descriptor::int32:
            return true;
        default:
            return false;
    }
}