Matrix<long double>* matrix_operators::multiply(const Matrix<long double> *first, const NeuralMatrix *other)  {
    if(first -> M == other -> N) {
        Matrix<long double> *product = new Matrix<long double>(first -> N, other -> M);
        if(product == nullptr) {
            return nullptr;
        }
        register size_t i, j, k;
        for(i = 0; i < first -> N; ++i) {
            for(j = 0; j < other -> M; ++j) {
                product -> matrix[i][j] = 0;
                for(k = 0; k < first -> M; ++k) {
                    product -> matrix[i][j] += first -> matrix[i][k] * other -> matrix[k][j] -> function;
                }
            }
        }
        return product;
    } else {
        throw std::length_error("Dimension mismatch");
    }
}