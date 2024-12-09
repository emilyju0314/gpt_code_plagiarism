void InsuranceGUI::convert_int_to_bit(uint8_t bitrange, uint32_t ref_value) {

    uint32_t temp = 0, value = 0;

    for (int i = bitrange - 1; i >= 0; i--) {

        temp = pow(2, i);

        // 2^i contained in ref_value - push 1
        if (ref_value >= temp) {

            ref_value -= pow(2, i);

            InsuranceGUI::bit_input_vector.push_back(1);

            // 2^i not contained in ref_value - push 0
        } else {

            InsuranceGUI::bit_input_vector.push_back(0);

        }

    }

}