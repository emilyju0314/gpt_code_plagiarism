inline constexpr size_t typeSize(Type t)
{
    static_assert(sizeof(int8_t) == 1);
    static_assert(sizeof(uint8_t) == 1);
    static_assert(sizeof(int16_t) == 2);
    static_assert(sizeof(uint16_t) == 2);
    static_assert(sizeof(int32_t) == 4);
    static_assert(sizeof(uint32_t) == 4);
    static_assert(sizeof(int64_t) == 8);
    static_assert(sizeof(uint64_t) == 8);
    static_assert(sizeof(float) == 4);
    static_assert(sizeof(double) == 8);
    return (t == int8 ? sizeof(int8_t)
            : t == uint8 ? sizeof(uint8_t)
            : t == int16 ? sizeof(int16_t)
            : t == uint16 ? sizeof(uint16_t)
            : t == int32 ? sizeof(int32_t)
            : t == uint32 ? sizeof(uint32_t)
            : t == int64 ? sizeof(int64_t)
            : t == uint64 ? sizeof(uint64_t)
            : t == float32 ? sizeof(float)
            : t == float64 ? sizeof(double)
            : 0);
}