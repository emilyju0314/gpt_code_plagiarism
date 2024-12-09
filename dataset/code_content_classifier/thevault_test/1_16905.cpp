String::String(bool arg_final_NUL, byte_vec str, int arg_n)
	{
	b = str;
	n = arg_n;
	final_NUL = arg_final_NUL;
	use_free_to_delete = false;
	}