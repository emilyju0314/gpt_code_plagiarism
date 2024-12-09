MatrixBO EchoBay::Comparator::argmax_label(Eigen::Ref<MatrixBO> predict, Eigen::Ref<MatrixBO> actual)
{
    // Declare label
    MatrixBO label(actual.rows(), actual.cols());
    int argMax;

    for (size_t i = 0; i < (size_t)actual.size(); ++i)
    {
        //Compute Argmax to determine the class
        predict.row(i).maxCoeff(&argMax);
        label(i, 0) = ((floatBO)argMax);
    }

    return label;
}