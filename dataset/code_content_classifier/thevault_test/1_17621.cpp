string Wart::unjumble(string input, int width)
{
	string decode = "";
	int length = input.length();

	int height = ceil(length/width);
	
	//just like encode, but switches the array indeces
	for (int i = 0; i < height; i++)
	{
		for (int k = 0; k < width; k++)
		{
			decode += input[i + height*k];
		}
	}
	return decode;
}