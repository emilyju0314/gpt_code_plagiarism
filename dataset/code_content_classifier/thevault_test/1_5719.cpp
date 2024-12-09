void EchoBay::Comparator::set_targetLabel(const Eigen::Ref<const MatrixBO> label, const Eigen::Ref<const ArrayI8> sampleState)
{
    if (_problemType == "Classification")
    {
        _targetLabel = label;
        _nClasses = get_nClasses(_targetLabel);
    }
    else // Regression and Memory Capacity
    {
        // Count columns of output
        _outCols = label.cols();

        // Copy data in realOut
        _targetLabel.resize(sampleState.count(), _outCols);
        int outRows = 0;
        for (int s = 0; s < sampleState.rows(); s++)
        {
            if (sampleState(s) != 0)
            {
                _targetLabel.row(outRows) = label.row(s);
                outRows++;
            }
        }
    }
}