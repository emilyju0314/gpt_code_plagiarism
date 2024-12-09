void init_CPPs()
	{
	static bool need_init = true;

	if ( need_init )
		for ( auto f : CPP_init_funcs )
			f();

	need_init = false;
	}