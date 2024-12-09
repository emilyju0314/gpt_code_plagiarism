NeuralNetwork::NeuralNetwork(const NeuralNetwork &other) : layers(other.layers.size()), learning_rate(other.learning_rate) {
    const size_t N = other.layers.size();
    for(register size_t i = 0; i < N; ++i) {
        layers[i] = new utilities::NeuralLayer(*other.layers[i]);
    }
}