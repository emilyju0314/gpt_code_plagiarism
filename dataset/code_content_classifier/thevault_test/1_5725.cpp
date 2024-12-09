floatBO EchoBay::Comparator::NRMSE(Eigen::Ref<MatrixBO> predict, Eigen::Ref<MatrixBO> actual, int nOutput, Eigen::Ref<MatrixBO> OutputLabel, const std::string rule)
{
    // Variables
    int i;
    ArrayBO diff_array(predict.rows());
    floatBO RMSE, variance;
    floatBO var_correction;
    ArrayBO NRMSE(predict.cols());

    // Calculate NRMSE
    var_correction = predict.rows() / (floatBO)(predict.rows() - 1);
    for (i = 0; i < nOutput; i++)
    {
        // Calculate difference array
        diff_array = predict.col(i) - actual.col(i);

        RMSE = sqrt(diff_array.pow(2).mean());
        variance = var_correction * (actual.col(i).array().pow(2).mean() - pow(actual.col(i).array().mean(), 2));
        NRMSE(i) = RMSE / sqrt(variance);
    }

    return 100.0 * (1.0 - NRMSE.mean());
}