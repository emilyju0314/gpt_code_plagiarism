floatBO EchoBay::Comparator::MemoryCapacity(Eigen::Ref<MatrixBO> predict, Eigen::Ref<MatrixBO> actual, int nOutput, Eigen::Ref<MatrixBO> OutputLabel, const std::string rule)
{
    // Variables
    int i;
    ArrayBO demean_actual(actual.rows());
	ArrayBO demean_predict(predict.rows());

    floatBO numerator;
    floatBO var_correction, variance_actual, variance_predict;
    ArrayBO MM(predict.cols());

    // Calculate NRMSE
    var_correction = predict.rows() / (floatBO)(predict.rows() - 1);
    for (i = 0; i < nOutput; i++)
    {
        // Calculate difference array
        demean_actual = (actual.col(i).array() - actual.col(i).array().mean());
		demean_predict = (predict.col(i).array() - predict.col(i).array().mean());
		numerator= (demean_actual * demean_predict).mean();

        variance_actual = var_correction * (actual.col(i).array().pow(2).mean() - pow(actual.col(i).array().mean(), 2));
        variance_predict = var_correction * (predict.col(i).array().pow(2).mean() - pow(predict.col(i).array().mean(), 2));

        MM(i) = pow(numerator,2) /(variance_actual * variance_predict);
    }

    return MM.sum();
}