void Matrix::setRow(unsigned row_set, const Matrix &in_row)
{
	if (in_row.rows != 1)
	{
		std::cout << "[ERROR]: not a row" << std::endl;
	}
	else if (in_row.cols != cols)
	{
		std::cout << "[ERROR]: the number of columns must match" << std::endl;
	}
	else
	{
		for (unsigned j = 0; j < cols; j++)
		{
			this->matrix[row_set][j] = in_row.matrix[0][j];
		}
	}
}