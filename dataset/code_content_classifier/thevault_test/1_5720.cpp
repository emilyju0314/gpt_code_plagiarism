MatrixBO EchoBay::Comparator::get_targetMatrix(const Eigen::Ref<const MatrixBO> label, const Eigen::Ref<const ArrayI8> sampleState)
{
    if (_problemType == "Classification")
    {
        // realOut equals label in classification
        // Count classes
        get_nClasses(label);

        // Resize targetMatrix
        _targetMatrix.resize(label.rows(), _nClasses);

        // Assign labels
        one_hot_encoding(_targetMatrix, label);
    }
    else // Regression and Memory Capacity
    {
        // Count columns of output
        _outCols = label.cols();

        // Copy data in realOut
        MatrixBO realOut(sampleState.count(), _outCols);
        int outRows = 0;
        for (int s = 0; s < sampleState.rows(); s++)
        {
            if (sampleState(s) != 0)
            {
                realOut.row(outRows) = label.row(s);
                outRows++;
            }
        }

        // Resize targetMatrix
        _targetMatrix.resize(realOut.rows(), _outCols);
        _targetMatrix.setZero(); // TODO Is this necessary
        // Assign label
        _targetMatrix = realOut;
    }

    return _targetMatrix;
}