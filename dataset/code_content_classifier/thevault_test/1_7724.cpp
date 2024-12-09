explicit binomial_distribution(const param_type& parm)
      : _t(parm.t()), _p(parm.p())
    {
        init();
    }