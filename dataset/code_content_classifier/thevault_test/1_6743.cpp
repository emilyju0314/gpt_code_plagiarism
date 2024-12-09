int Address::get_nodeaddr(int address)
{
	int a;
	char *temp;
	
	temp = print_nodeaddr(address);
	a = str2addr(temp);
	delete [] temp;
	return a;
}