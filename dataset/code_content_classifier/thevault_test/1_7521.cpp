void Value::init_tagged_pointer(Tag t, void* p) {
    if (sizeof(Value) == sizeof(uintptr_t)) {
        *this->cast<uintptr_t>() = reinterpret_cast<uintptr_t>(p);
        // For 64-bit, we rely on the pointer lower bits being zero.
        SkASSERT(!(fData8[0] & kTagMask));
        fData8[0] |= SkTo<uint8_t>(t);
    } else {
        // For 32-bit, we store the pointer in the upper word
        SkASSERT(sizeof(Value) == sizeof(uintptr_t) * 2);
        this->init_tagged(t);
        *this->cast<uintptr_t>() = reinterpret_cast<uintptr_t>(p);
    }

    SkASSERT(this->getTag()    == t);
    SkASSERT(this->ptr<void>() == p);
}