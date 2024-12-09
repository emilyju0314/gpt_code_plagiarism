void NeuralNetwork::set_data(const long double *data, const size_t N) const {
    if(N != (*layers[0]).N) {
        std::cerr << "Error in NeuralNetwork object at " << this << '\n';
        throw std::length_error("Length doesn't match up the size of the input data vector");
    } else {
        for(register size_t i = 0; i < N; ++i) {
            layers[0] -> data -> matrix[i][0] -> data = data[i];
        }
    }
}