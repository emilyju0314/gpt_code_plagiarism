void EchoBay::Comparator::ConfusionMatrix(Eigen::Ref<MatrixBO> predict, Eigen::Ref<MatrixBO> actual, int nOutput, Eigen::Ref<Eigen::MatrixXi> confusionMat)
{
    int i, c;
    for (size_t j = 0; j < (size_t)actual.size(); j++)
    {
        c = (int)actual(j, 0);
        for (i = 0; i < nOutput; i++)
        {
            confusionMat(c, i) += (int)predict(j, 0) == i;
        }
    }
}