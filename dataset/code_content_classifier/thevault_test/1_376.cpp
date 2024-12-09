torch::Tensor pack(torch::Tensor input, int bits) {
    CHECK_INPUT(input);

    return cuda_pack(input, bitsToIntType(bits));
}