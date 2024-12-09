MatrixBO cat_matrix(const MatrixBO &a, const MatrixBO &b)
{
    MatrixBO output;
    output.resize(a.rows() + b.rows(), a.cols());
    output.block(0, 0, a.rows(), a.cols()) = a;
    output.block(a.rows(), 0, b.rows(), b.cols()) = b;
    return output;
}