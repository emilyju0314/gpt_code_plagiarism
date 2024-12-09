void tiramisu::computation::parallelize(tiramisu::var par_dim_var)
{
    DEBUG_FCT_NAME(3);
    DEBUG_INDENT(4);

    assert(par_dim_var.get_name().length() > 0);
    assert(!this->get_name().empty());
    assert(this->get_function() != NULL);

    std::vector<int> dimensions =
        this->get_loop_level_numbers_from_dimension_names({par_dim_var.get_name()});
    this->check_dimensions_validity(dimensions);

    int par_dim = dimensions[0];
    this->tag_parallel_level(par_dim);

    DEBUG_INDENT(-4);
}