Matrix Matrix::getRow(unsigned row_get) const
{
	Matrix mat_row(1, cols);
	for (unsigned j = 0; j < cols; j++)
		mat_row.matrix[0][j] = this->matrix[row_get][j];
	return mat_row;
}