tiramisu::computation::computation()
{
    this->access = NULL;
    this->schedule = NULL;
    this->stmt = Halide::Internal::Stmt();
    this->time_processor_domain = NULL;
    this->duplicate_number = 0;

    this->schedule_this_computation = false;
    this->data_type = p_none;
    this->expression = tiramisu::expr();

    this->ctx = NULL;

    this->lhs_access_type = tiramisu::o_access;
    this->lhs_argument_idx = -1;
    this->rhs_argument_idx = -1;
    this->wait_argument_idx = -1;
    this->_is_library_call = false;
    this->wait_access_map = nullptr;
    this->wait_index_expr = nullptr;

    this->iteration_domain = NULL;
    this->name = "";
    this->fct = NULL;
    this->is_let = false;
}