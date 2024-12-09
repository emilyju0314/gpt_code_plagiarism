photon_emission_lookup_table(
                photon_emission_lookup_table_params<RealType> params,
                VectorType vals):
                m_params{params},
                m_table{containers::equispaced_2d_table<RealType, VectorType>{
                    math::m_log(params.chi_part_min),
                    math::m_log(params.chi_part_max),
                    math::m_log(params.frac_min),
                    math::m_log(math::one<RealType>),
                    params.chi_part_how_many, params.frac_how_many,
                    vals}}
            {
                m_init_flag = true;
            }