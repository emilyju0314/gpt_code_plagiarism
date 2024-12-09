void Wart::encode (int width)
{
	string encoded = "";
	int length = store.length();

	int height = ceil(length/width);

	//fills in the extra places in the string
	if (length % width != 0)
	{
		for (int i = length; i < length * width - 1; i++)
		{
			store += " ";
		}
		store += ".";
	}

	//iterates through and adds letters based on where they would be in the encoded array
	for (int j = 0; j < width; j++)
	{
		for (int k = 0; k < height; k++)
		{
			encoded += store[j + width*k];
		}
	}

	store = encoded;
}