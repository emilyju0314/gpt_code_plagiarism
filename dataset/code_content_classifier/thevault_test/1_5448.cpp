void tiramisu::computation::init_computation(std::string iteration_space_str,
        tiramisu::function *fction,
        const tiramisu::expr &e,
        bool schedule_this_computation,
        tiramisu::primitive_t t)
{
    DEBUG_FCT_NAME(3);
    DEBUG_INDENT(4);

    DEBUG(3, tiramisu::str_dump("Constructing the computation: " + iteration_space_str));

    assert(fction != NULL);
    assert(iteration_space_str.length() > 0 && ("Empty iteration space"));

    // Initialize all the fields to NULL (useful for later asserts)
    access = NULL;
    stmt = Halide::Internal::Stmt();
    time_processor_domain = NULL;
    duplicate_number = 0;
    automatically_allocated_buffer = NULL;
    predicate = tiramisu::expr();
    // In the constructor of computations, we assume that every created
    // computation is the first computation, then, if this computation
    // was created by add_definitions(), we change is_first_definition
    // to false, otherwise we keep it.
    // We do the same for first_definition.
    is_first = true;
    first_definition = NULL;
    this->definitions_number = 1;
    this->definition_ID = 0;
    this->_is_library_call = false;
    this->_is_nonblock_or_async = false;
    this->_drop_rank_iter = false;

    this->lhs_access_type = tiramisu::o_access;
    this->lhs_argument_idx = -1;
    this->rhs_argument_idx = -1;
    this->wait_argument_idx = -1;
    this->_is_library_call = false;
    this->wait_access_map = nullptr;
    this->wait_index_expr = nullptr;

    this->schedule_this_computation = schedule_this_computation;
    this->data_type = t;

    this->ctx = fction->get_isl_ctx();

    iteration_domain = isl_set_read_from_str(ctx, iteration_space_str.c_str());
    this->name_unnamed_iteration_domain_dimensions();
    name = std::string(isl_space_get_tuple_name(isl_set_get_space(iteration_domain),
                       isl_dim_type::isl_dim_set));

    number_of_dims = isl_set_dim(iteration_domain, isl_dim_type::isl_dim_set);
    for (unsigned i = 0; i < number_of_dims; i++) {
        if (isl_set_has_dim_name(iteration_domain, isl_dim_type::isl_dim_set, i)) {
            std::string dim_name(isl_set_get_dim_name(iteration_domain, isl_dim_type::isl_dim_set, i));
            this->access_variables.push_back(make_pair(i, dim_name));
        }
    }

    fct = fction;
    fct->add_computation(this);
    this->set_identity_schedule_based_on_iteration_domain();
    this->set_expression(e);
    this->set_inline(false);

    // Set the names of output dimensions to be equal to the names of iteration domain schedules.
    std::vector<std::string> nms = this->get_iteration_domain_dimension_names();
    // Rename the dimensions of the schedule domain so that when we set the names of
    // the schedule range dimension to be equal to the names of the domain, we do not
    // get a conflict.
    for (int i = 0; i< this->get_iteration_domain_dimensions_number(); i++)
        this->set_schedule_domain_dim_names({i}, {generate_new_variable_name()});
    for (int i = 0; i< nms.size(); i++)
        this->set_loop_level_names({i}, {nms[i]});

    // If there are computations that have already been defined and that
    // have the same name, check that they have constraints over their iteration
    // domains.
    std::vector<tiramisu::computation *> same_name_computations =
        this->get_function()->get_computation_by_name(name);
    if (same_name_computations.size() > 1)
    {
        if (isl_set_plain_is_universe(this->get_iteration_domain()))
        {
            ERROR("Computations defined multiple times should"
                            " have bounds on their iteration domain", true);
        }

        for (auto c : same_name_computations)
        {
            if (isl_set_plain_is_universe(c->get_iteration_domain()))
            {
                ERROR("Computations defined multiple times should"
                                " have bounds on their iteration domain", true);
            }
        }
    }

    this->updates.push_back(this);

    DEBUG_INDENT(-4);
}