Threaded_rands(const unsigned int n, const generator_type sel = generator_type::pcg) : n_threads{n}
	{					
		// TODO - Implement thread number checking properly
		// n_threads = get_thread_info(_n_threads);

		for(unsigned int thread_id = 0; thread_id < n; ++thread_id)
	    {
	        if(sel == generator_type::pcg)
	        	gen_vec.push_back(pcg_unique<state_type>(thread_id));
			if(sel == generator_type::xoro128)
	        	gen_vec.push_back(xoroshiro128<state_type>(thread_id));
	        if(sel == generator_type::jsf)
	        	gen_vec.push_back(jsf<state_type>(thread_id));
	    }

	}