Matrix Matrix::deleteCol(unsigned col_del) const
{
	if (cols == 0)
	{
		std::cout << "[ERROR]: a single column cannot be deleted" << std::endl;
		return *this;
	}
	else if (col_del >= cols)
	{
		std::cout << "[ERROR]: column number is higher than the maximum" << std::endl;
		return *this;
	}
	Matrix result(rows, cols-1);
	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < col_del; j++)
			result.matrix[i][j] = matrix[i][j];
	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = col_del; j < cols-1; j++)
			result.matrix[i][j] = matrix[i][j+1];
	return result;
}