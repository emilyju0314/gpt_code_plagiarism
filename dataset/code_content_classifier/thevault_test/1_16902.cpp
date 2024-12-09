void activate__CPPs()
	{
	static bool need_init = true;

	if ( need_init )
		for ( auto f : CPP_activation_funcs )
			f();

	need_init = false;
	}