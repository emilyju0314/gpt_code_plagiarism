tiramisu::computation::computation(std::string iteration_domain_str, tiramisu::expr e,
                                   bool schedule_this_computation, tiramisu::primitive_t t,
                                   tiramisu::function *fct)
{

    DEBUG_FCT_NAME(3);
    DEBUG_INDENT(4);

    init_computation(iteration_domain_str, fct, e, schedule_this_computation, t);
    is_let = false;

    DEBUG_INDENT(-4);
}