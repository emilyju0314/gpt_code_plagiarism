_lcp_support_tree(cache_config& config, const t_cst* cst = nullptr)
	{
		m_cst				   = cst;
		std::string fc_lcp_key = "fc_lcp_" + util::to_string(util::id());
		std::string tmp_file   = cache_file_name(fc_lcp_key, config);
		{
			int_vector<0>		temp_lcp;
			int_vector_buffer<> lcp_buf(cache_file_name(conf::KEY_LCP, config));
			construct_first_child_lcp(lcp_buf, temp_lcp);
			// TODO: store LCP values directly
			store_to_file(temp_lcp, tmp_file);
		}
		{
			{
				m_lcp =
				t_lcp(config, fc_lcp_key); // works for lcp_kurtz, lcp_wt and lcp_bitcompressed
			}
		}
		sdsl::remove(tmp_file);
	}