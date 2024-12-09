CsvWorker::CsvWorker(char delim, unsigned int rows_count, unsigned int cols_count)
{
	this->delimiter  = delim;
    this->rows_count = rows_count;
    this->cols_count = cols_count;
    row rw(cols_count, "");
	data.resize(rows_count, rw);
}