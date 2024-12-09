viterbi(const model_t & model):
        m_model(model),
        m_states_p(model.state_cnt()),
        m_t(0)
    {}