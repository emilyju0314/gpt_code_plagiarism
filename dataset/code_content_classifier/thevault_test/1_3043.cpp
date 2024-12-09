std::string FloatToString ( float& value )
{
	std::ostringstream o;
    
	if (!(o << value))
	{
		printf("Failed conversion.");
	}
	return o.str();
}