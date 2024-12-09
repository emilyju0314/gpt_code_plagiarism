long binSearch(long* array, long size, long value)
{
	long average_index = 0; // переменная для хранения индекса среднего элемента массива
	long first_index = 0; // индекс первого элемента в массиве
	long last_index = size - 1; // индекс последнего элемента в массиве
	if (last_index == -1)
	{
		return last_index; // массив пуст
	}
	while (first_index < last_index)
	{
		average_index = first_index + (last_index - first_index) / 2; // меняем индекс среднего значения
		value <= array[average_index] ? last_index = average_index : first_index = average_index + 1;    // найден ключевой элемент или нет 
	}
	if (array[last_index] == value)
	{
		return last_index;
	}
	else
	{
		return -1;
	}
}