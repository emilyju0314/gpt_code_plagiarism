dndt_lookup_table(dndt_lookup_table_params<RealType> params,
                VectorType vals):
            m_params{params},
            m_table{containers::equispaced_1d_table<RealType, VectorType>{
                    math::m_log(params.chi_part_min),
                    math::m_log(params.chi_part_max),
                    vals}}
            {
                m_init_flag = true;
            }