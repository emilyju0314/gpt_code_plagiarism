dndt_lookup_table(dndt_lookup_table_params<RealType> params):
            m_params{params},
            m_table{containers::equispaced_1d_table<RealType, VectorType>{
                    math::m_log(params.chi_part_min),
                    math::m_log(params.chi_part_max),
                    VectorType(params.chi_part_how_many)}}
            {}