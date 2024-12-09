floatBO EchoBay::Comparator::F1Mean(Eigen::Ref<MatrixBO> predict, Eigen::Ref<MatrixBO> actual, int nOutput, Eigen::Ref<MatrixBO> OutputLabel, const std::string rule)
{
    // Determine labels
    MatrixBO label = argmax_label(predict, actual);
    // Compute Confusion Matrix
    Eigen::MatrixXi confusionMat = Eigen::MatrixXi::Zero(nOutput, nOutput);
    ConfusionMatrix(label, actual, nOutput, confusionMat);
    std::cout << "\n" << confusionMat << std::endl;

    floatBO F1 = 0;
    int actualClasses = 0;

    ArrayI rowSum = confusionMat.rowwise().sum();
    ArrayI colSum = confusionMat.colwise().sum();
    ArrayI confusionDiag = confusionMat.diagonal();

    for (int i = 0; i < nOutput; i++)
    {
        if(rowSum(i) > 0)
        {
            F1 += 2 * confusionDiag(i) / (floatBO)(rowSum(i) + colSum(i));
            actualClasses++;
        }
    }

    // Calculate mean
    F1 = F1 / (floatBO) actualClasses;
    return 100 * F1;
}