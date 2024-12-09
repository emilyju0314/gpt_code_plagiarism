bool NeedsParens(const clang::Expr* expr) {
  if (llvm::dyn_cast<clang::UnaryOperator>(expr) ||
      llvm::dyn_cast<clang::BinaryOperator>(expr) ||
      llvm::dyn_cast<clang::ConditionalOperator>(expr)) {
    return true;
  }
  // Calls to an overloaded operator also need parens, except for foo(...) and
  // foo[...] expressions.
  if (const clang::CXXOperatorCallExpr* op =
          llvm::dyn_cast<clang::CXXOperatorCallExpr>(expr)) {
    return op->getOperator() != clang::OO_Call &&
           op->getOperator() != clang::OO_Subscript;
  }
  return false;
}