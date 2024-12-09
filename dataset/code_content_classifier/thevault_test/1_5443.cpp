tiramisu::computation *computation::store_at(tiramisu::computation &comp,
                                             tiramisu::var L0_var)
{
    DEBUG_FCT_NAME(3);
    DEBUG_INDENT(4);

    assert(L0_var.get_name().length() > 0);
    std::vector<int> dimensions =
        this->get_loop_level_numbers_from_dimension_names({L0_var.get_name()});
    this->check_dimensions_validity(dimensions);
    int L0 = dimensions[0];

    std::vector<tiramisu::expr> *dim_sizes = this->compute_buffer_size();

    tiramisu::buffer *buff = new tiramisu::buffer("_" + this->name + "_buffer",
            (*dim_sizes),
            this->get_data_type(),
            tiramisu::a_temporary,
            this->get_function());

    this->automatically_allocated_buffer = buff;

    tiramisu::computation *allocation = buff->allocate_at(comp, L0);
    this->store_in(buff);
    if (comp.get_predecessor() != NULL)
        allocation->between(
            *(comp.get_predecessor()),
            L0_var, comp, L0_var);
    else
        allocation->before(comp, L0);

    DEBUG_INDENT(-4);

    return allocation;
}