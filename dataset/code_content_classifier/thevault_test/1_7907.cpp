static int is_kforth_word_char(int c)
{
	if( isspace(c) || strchr(";:{}", c) || iscntrl(c) )
		return 0;
	else
		return 1;
}