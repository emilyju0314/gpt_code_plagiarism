void SysBuilder_llp :: build_system(FrontendType type, int n_lps, vector<string>& args, int part)
{
    assert(m_conf_read == true);

    // create default clock, this is the Master Clock
    m_default_clock = 0;
    if(m_DEFAULT_CLOCK_FREQ > 0)
        m_default_clock = new Clock(m_DEFAULT_CLOCK_FREQ);

    //create network
    if(m_network_builder->get_type() == NetworkBuilder :: IRIS) {
        dep_injection_for_iris();
    }

    //??????????????? todo: network should be able to use different clock
    m_network_builder->create_network(*m_default_clock, part);

#ifdef LIBKITFOX
    m_kitfox_builder->create_proxy();
#endif

    assert(m_proc_builder->get_fe_type() == ProcBuilder::INVALID_FE_TYPE);
    switch(type) {
        case FT_QSIMCLIENT: {
            m_proc_builder->set_fe_type(ProcBuilder::QSIMCLIENT);
            create_qsimclient_nodes(n_lps, args, part);
            break;
        }
        case FT_TRACE: {
            m_proc_builder->set_fe_type(ProcBuilder::TRACE);
            create_trace_nodes(n_lps, args, part);
            break;
        }
        default: {
            assert(0);
            break;
        }
    }

    //connect components
    connect_components();
}