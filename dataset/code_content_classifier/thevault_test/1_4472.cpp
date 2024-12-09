Matrix Matrix::deleteRow(unsigned row_del) const
{
	if (rows == 1)
	{
		std::cout << "[ERROR]: a single row cannot be deleted" << std::endl;
		return *this;
	}
	else if (row_del >= rows)
	{
		std::cout << "[ERROR]: row number is higher than the maximum" << std::endl;
		return *this;
	}
	Matrix result(rows-1, cols);
	for (unsigned i = 0; i < row_del; i++)
		for (unsigned j = 0; j < cols; j++)
			result.matrix[i][j] = matrix[i][j];
	for (unsigned i = row_del; i < rows-1; i++)
		for (unsigned j = 0; j < cols; j++)
			result.matrix[i][j] = matrix[i+1][j];
	return result;
}