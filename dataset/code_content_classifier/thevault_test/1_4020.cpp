dndt_lookup_table(const std::vector<char>& raw_data)
            {
                using namespace utils;

                constexpr size_t min_size =
                    sizeof(char)+ //single or double precision
                    sizeof(m_params);

                if (raw_data.size() < min_size)
                    throw std::runtime_error("Binary data is too small \
                    to be a Quantum Synchrotron G-function lookup-table.");

                auto it_raw_data = raw_data.begin();

                if (serialization::get_out<char>(it_raw_data) !=
                    static_cast<char>(sizeof(RealType))){
                    throw std::runtime_error("Mismatch between RealType used \
                    to write and to read the Quantum Synchrotron G-function lookup-table");
                }

                m_params = serialization::get_out<
                    dndt_lookup_table_params<RealType>>(it_raw_data);
                m_table = containers::equispaced_1d_table<
                    RealType, VectorType>{std::vector<char>(it_raw_data,
                        raw_data.end())};

                m_init_flag = true;
            }