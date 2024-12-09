function::function(std::string name) {
        assert(!name.empty() && ("Empty function name"));

        this->name = name;
        halide_stmt = Halide::Internal::Stmt();
        ast = NULL;
        context_set = NULL;
        use_low_level_scheduling_commands = false;
        _needs_rank_call = false;

        // Allocate an ISL context.  This ISL context will be used by
        // the ISL library calls within Tiramisu.
        ctx = isl_ctx_alloc();
}