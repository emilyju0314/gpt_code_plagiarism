void NumberList::Sort()
{
	int i, j;
	for (i = 0; i < this->count - 1; i++)
		for (j = i + 1; j < this->count; j++)
		{
			if (this->numbers[i] > this->numbers[j])
			{
				int aux = this->numbers[i];
				this->numbers[i] = this->numbers[j];
				this->numbers[j] = aux;
			}
		}
}