void EchoBay::Comparator::set_label_size(int rows, int cols)
{
    // Copy internal variables
    _rows = rows;
    _cols = cols;

    // Resize matrix
    if (_problemType == "Classification")
    {
        _nOutput = _nClasses;
        _outputLabel.resize(_rows, _cols * _nClasses);
    }
    else // Regression and Memory Capacity
    {
        // TODO needs a check if _outCols is defined or not
        _nOutput = _outCols;
        _outputLabel.resize(_rows, _outCols);
    }
}