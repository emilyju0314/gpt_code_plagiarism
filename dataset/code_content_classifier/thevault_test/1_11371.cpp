Halide::Expr Type::max() const {
    if (is_vector()) {
        return Internal::Broadcast::make(element_of().max(), lanes());
    } else if (is_int()) {
        return Internal::IntImm::make(*this, max_int(bits()));
    } else if (is_uint()) {
        return Internal::UIntImm::make(*this, max_uint(bits()));
    } else {
        internal_assert(is_float());
        if (bits() == 16) {
            return Internal::FloatImm::make(*this, 65504.0);
        } else if (bits() == 32) {
            return Internal::FloatImm::make(*this, FLT_MAX);
        } else if (bits() == 64) {
            return Internal::FloatImm::make(*this, DBL_MAX);
        } else {
            internal_error
                << "Unknown float type: " << (*this) << "\n";
            return 0;
        }
    }
}