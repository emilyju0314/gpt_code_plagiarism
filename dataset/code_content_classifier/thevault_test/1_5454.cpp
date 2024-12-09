void tiramisu::computation::set_access(std::string access_str)
{
    DEBUG_FCT_NAME(3);
    DEBUG_INDENT(4);

    DEBUG(3, tiramisu::str_dump("Setting access " + access_str + " for computation " + this->get_name()));

    this->access = isl_map_read_from_str(this->ctx, access_str.c_str());

    /**
     * Set the access relations of all the computations that have the same name
     * (duplicates and updates).
     */
    std::vector<tiramisu::computation *> same_name_computations =
        this->get_function()->get_computation_by_name(this->get_name());

    if (same_name_computations.size() > 1)
        for (auto c : same_name_computations)
        {
            c->access = isl_map_read_from_str(this->ctx, access_str.c_str());
        }

    /**
     * Check that if there are other computations that have the same name
     * as this computation, then the access of all of these computations
     * should be the same.
     */
    std::vector<tiramisu::computation *> computations =
        this->get_function()->get_computation_by_name(this->get_name());
    for (auto c : computations)
        if (isl_map_is_equal(this->get_access_relation(), c->get_access_relation()) == isl_bool_false)
        {
            ERROR("Computations that have the same name should also have the same access relation.",
                            true);
        }

    assert(this->access != nullptr && "Set access failed");

    DEBUG_INDENT(-4);
}