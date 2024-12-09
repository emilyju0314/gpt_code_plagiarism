VExprAst::VExprAstPtr VExprAst::MakeCopyWithNewChild(const VExprAstPtrVec& in) const {
  assert(in.size() == child_.size());
  auto ret = std::make_shared<VExprAst>(op_ , in, parameter_, str_parameter_);
  return ret;
}