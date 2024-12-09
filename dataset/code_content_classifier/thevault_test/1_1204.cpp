void expressionUnrollSanityCheck(const IR::Expression *e) {
    if (!e->is<IR::Operation_Unary>() &&
            !e->is<IR::MethodCallExpression>() && !e->is<IR::Member>() &&
            !e->is<IR::PathExpression>() && !e->is<IR::Operation_Binary>() &&
            !e->is<IR::Constant>() && !e->is<IR::BoolLiteral>()) {
        std::cerr << e->node_type_name() << std::endl;
        BUG("Untraversed node");
    }
}