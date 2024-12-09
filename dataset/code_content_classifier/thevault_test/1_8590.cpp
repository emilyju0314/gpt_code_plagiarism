inline void MixedColumn::insert_int(size_t ndx, int_fast64_t value, MixedColType type)
{
    int_fast64_t types_value = type;
    // Shift value one bit and set lowest bit to indicate that this is not a ref
    int_fast64_t data_value =  1 + (value << 1);
    insert_value(ndx, types_value, data_value); // Throws
}