int EchoBay::Comparator::get_nClasses(const Eigen::Ref<const MatrixBO> label)
{
    // Copy label
    ArrayBO _label = label.col(0).array();
    // Get number of classes
    // Sort vector
    std::sort(_label.data(), _label.data() + _label.size(), std::less<floatBO>());
    // Get uniques
    _nClasses = std::distance(_label.data(), std::unique(_label.data(), _label.data() + _label.size()));
    return _nClasses;
}