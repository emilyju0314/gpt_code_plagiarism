floatBO EchoBay::Comparator::Accuracy(Eigen::Ref<MatrixBO> predict, Eigen::Ref<MatrixBO> actual, int nOutput, Eigen::Ref<MatrixBO> OutputLabel, const std::string rule)
{
    // Determine labels
    MatrixBO label = argmax_label(predict, actual);
    // Compute Confusion Matrix
    Eigen::MatrixXi confusionMat = Eigen::MatrixXi::Zero(nOutput, nOutput);
    ConfusionMatrix(label, actual, nOutput, confusionMat);
    std::cout << "\n" << confusionMat << std::endl;

    floatBO Accuracy = confusionMat.diagonal().sum() / (double)confusionMat.sum();
    return 100 * Accuracy;
}