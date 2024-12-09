std::vector<long double> NeuralNetwork::get_data_vector() const {
    size_t access = layers.size() - 1;
    size_t N = layers[access] -> N;
    std::vector<long double> data(N);
    for(register size_t i = 0; i < N; ++i) {
        data[i] = layers[access] -> data -> matrix[i][0] -> function;
    }
    return data;
}