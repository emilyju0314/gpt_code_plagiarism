Matrix Matrix::operator/(float float_right)
{
	Matrix result(rows, cols);
	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < cols; j++)
			result.matrix[i][j] = matrix[i][j] / float_right;
	return result;
}