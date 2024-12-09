bool LogicalExpressionUnroll::preorder(const IR::Operation_Unary *u) {
    expressionUnrollSanityCheck(u->expr);

    // If the expression is a methodcall expression, do not insert a temporary
    // variable to represent the value of the methodcall. Instead the
    // methodcall is converted to a dpdk branch instruction in a later pass.
    if (u->expr->is<IR::MethodCallExpression>())
        return false;

    // if the expression is apply().hit or apply().miss, do not insert a temporary
    // variable.
    if (auto member = u->expr->to<IR::Member>()) {
        if (member->expr->is<IR::MethodCallExpression>() &&
            (member->member == IR::Type_Table::hit ||
             member->member == IR::Type_Table::miss)) {
            return false;
        }
    }

    root = u->clone();
    visit(u->expr);
    const IR::Expression *un_expr;
    if (root) {
        if (u->to<IR::Neg>()) {
            un_expr = new IR::Neg(root);
        } else if (u->to<IR::Cmpl>()) {
            un_expr = new IR::Cmpl(root);
        } else if (u->to<IR::LNot>()) {
            un_expr = new IR::LNot(root);
        } else {
            BUG("%1% Not Implemented", u);
        }
    } else {
        un_expr = u->expr;
    }

    auto tmp = new IR::PathExpression(IR::ID(refMap->newName("tmp")));
    root = tmp;
    stmt.push_back(new IR::AssignmentStatement(root, un_expr));
    decl.push_back(new IR::Declaration_Variable(tmp->path->name, u->type));
    return false;
}