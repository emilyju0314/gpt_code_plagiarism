neural_networks::utilities::NeuralMatrix::NeuralMatrix(const size_t n, const size_t m, bool is_null, bool random) : Matrix<Neuron *>(n, m) {
    if(!is_null) {
        // size_t sum = 0;
        register size_t i, j;
        if(!random) {
            for (i = 0; i < N; ++i) {
                for (j = 0; j < M; ++j) {

                    this->matrix[i][j] = new Neuron;
                    // sum += sizeof(matrix[i][j]);
                }
            }
        } else { // otherwise if we were given a randomization request
            // for a guassian distribution
            // seeding it
            std::default_random_engine generator(static_cast<size_t>(time(0)));
            std::normal_distribution<long double> distribution(0.0, 2.0);
            for (i = 0; i < N; ++i) {
                for (j = 0; j < M; ++j) {
                    this->matrix[i][j] = new Neuron(distribution(generator));
                    // sum += sizeof(matrix[i][j]);
                }
            }
        }
        // std::cout << "Allocated " << sum << "B of memory at " << this << "\n";
    }
}