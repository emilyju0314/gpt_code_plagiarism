void EchoBay::compute_output(const Eigen::Ref<MatrixBO> &Win, const Eigen::Ref<Eigen::SparseMatrix<floatBO, RowMajor>> &Wr,
                             const Eigen::Ref<MatrixBO> &Wout, const std::vector<ArrayBO> input_data,
                             const Eigen::Ref<ArrayBO> start_state, const unsigned int Nu, const unsigned int n_outputs)
{
    /*// Input temporary variable
    Array2f u(Nu);
    u(1) = 1.0;

    // Initialize state
    ArrayXf current_state;
    current_state.resize(start_state.rows());
    ArrayXf biased_state;
    current_state << start_state;
    biased_state.resize(start_state.rows() + 1);

    // Initialize output
    MatrixBO output_value(n_outputs, 1);

    int compute_samples = input_data.size();
    for (int t = 0; t <= compute_samples; t++)
    {
        // update input
        u(0) = input_data[t];

        // Compute new state
        current_state = Win * u.matrix() + Wr * current_state.matrix();
        current_state = current_state.tanh();

        // Compute output
        biased_state << current_state, 1.0;
        output_value = Wout.transpose() * biased_state.matrix();
    }*/
}