uint32_t InsuranceGUI::convert_bit_to_int(std::vector<uint32_t> bit_vector) {

    uint32_t temp = 0, result = 0;

    // Go through the bit vector
    for (int i = bit_vector.size() - 1; i >= 0; i--) {

        temp = pow(2, (bit_vector.size() - 1 - i));

        if (bit_vector[i] == 1) {
            result += temp;
        }

    }

    return (result >> FIXEDPOINT_FRACTION_BITS);
}