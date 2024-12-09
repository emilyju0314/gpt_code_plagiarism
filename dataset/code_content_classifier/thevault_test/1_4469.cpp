Matrix Matrix::getCol(unsigned col_get) const
{
	Matrix mat_col(rows, 1);
	for (unsigned i = 0; i < cols; i++)
		mat_col.matrix[i][0] = this->matrix[i][col_get];
	return mat_col;
}