void Matrix::makeGaussElimR()
{
	if (rows != 1)
	{
		unsigned pivot_num = 0;
		unsigned col_shift = 0;
		unsigned col_check = 0;
		while (col_check + col_shift < cols || pivot_num < rows)
		{
			bool allzeros = true;
			for (unsigned row_count = pivot_num; row_count < rows; row_count++)
			{
				if (matrix[row_count][col_check+col_shift] != 0)
				{
					allzeros = false;
					if (row_count != pivot_num)
					{
						swapRows(pivot_num, row_count);
					}
					for (unsigned sub_row_count = row_count+1; sub_row_count < rows; sub_row_count++)
					{
						Matrix newrow = getRow(sub_row_count) - getRow(row_count) * 
								matrix[sub_row_count][col_check+col_shift] *
								(1 / matrix[row_count][col_check+col_shift]);
						setRow(sub_row_count, newrow);	
					}
					col_check += col_shift + 1;
					col_shift = 0;
					break;
				}
			}
			if (allzeros == true)
			{
				col_shift++;
			}
			else
			{
				pivot_num++;
			}
		}
	}
}