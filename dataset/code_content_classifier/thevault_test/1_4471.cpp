void Matrix::setCol(unsigned col_set, const Matrix &in_col)
{
	if (in_col.cols != 1)
	{
		std::cout << "[ERROR]: not a column" << std::endl;
	}
	else if (in_col.rows != rows)
	{
		std::cout << "[ERROR]: the number of rows must match" << std::endl;
	}
	else
	{
		for (unsigned i = 0; i < rows; i++)
		{
			this->matrix[i][col_set] = in_col.matrix[i][0];
		}
	}
}