void EchoBay::Comparator::one_hot_encoding(Eigen::Ref<MatrixBO> Dst, MatrixBO Src)
{
    int k;
    int len = Src.rows();

    // Reset matrix
    Dst.setZero();
    // Assign encoding
    for (int i = 0; i < len; ++i)
    {
        k = (int)Src(i);
        Dst(i, k) = 1;
    }
}