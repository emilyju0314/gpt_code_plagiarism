baum_welch(
        model_t & model,
        bool      init_pi = false,
        bool      init_tr = false,
        bool      init_e  = false)
    :
        m_model(model)
    {
        if (!(init_pi || init_tr || init_e))
            return;  // no initialisation

        // Initialise states start probability
        if (init_pi) {
            auto pi = rand_p_vector(m_model.state_cnt());

            m_model.for_each_state([&pi](state_t & state) {
                state.value.p = pi[state.value.index];
            });
        }

        // Initialise transitions probability
        if (init_tr) {
            m_model.for_each_state([this](state_t & state) {
                auto A = rand_p_vector(m_model.transition_cnt_from(state));

                size_t ij = 0;
                m_model.for_each_trans_from(state,
                [&A,&ij](transition_t & trans) {
                    trans.value.p = A[ij++];
                });
            });
        }

        // Initialise emissions probability
        if (init_e) {
            m_model.for_each_state([this](state_t & state) {
                state.value.emit_p.set_rand();
            });
        }
    }