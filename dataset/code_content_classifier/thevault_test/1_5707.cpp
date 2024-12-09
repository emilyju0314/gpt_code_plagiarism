void EchoBay::compute_state(Eigen::Ref<MatrixBO> dst, Eigen::Ref<MatrixBO> Win,
                           Eigen::Ref<SparseBO> Wr, const MatrixBO &src,
                           Eigen::Ref<ArrayBO> stateArr,
                           const Eigen::Ref<const ArrayI8> sampleState, floatBO leaky)
{
    size_t trainSamples = src.rows();
    MatrixBO u(src.cols()+1, src.rows());
    u << src.transpose(), MatrixBO::Ones(1, src.rows()); // TODO improve this to avoid transpose
    int sample = 0;
    // Leaky state
    ArrayBO prevState(stateArr.rows());
    // Leaky factor
    floatBO leakyFactor = (1.0 - leaky);
    // Computation
    for (size_t t = 0; t < trainSamples; ++t)
    {
        // Update leaky state
        prevState = leakyFactor * stateArr;

        // Compute new state
        stateArr = Win * u.col(t) + Wr * stateArr.matrix();
        stateArr = prevState + leaky * stateArr.tanh();

        // Save state for later usage
        if (sampleState(t) != 0)
        {
            dst.row(sample) << stateArr.transpose(), 1.0;
            sample++;
            if (sampleState(t) == -1)
            {
                stateArr.setZero();
            }
        }
    }
}