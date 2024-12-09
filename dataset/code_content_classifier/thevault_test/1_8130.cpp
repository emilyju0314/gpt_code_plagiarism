deferred_ptr<const Expr> Expr::make_assignment_expression(
        deferred_ptr<const Expr>&& /*lhs_expr*/,
        deferred_ptr<const Expr>&& /*rhs_expr*/,
        deferred_heap&,
        const Runtime_error& throwable_if_not_lvalue
    ) const {
        throw throwable_if_not_lvalue;
    }