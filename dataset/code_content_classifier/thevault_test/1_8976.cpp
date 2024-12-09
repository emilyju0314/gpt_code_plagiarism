bool GetValueIfConstant(const CpModel& model, const CpIntegerExpression& proto,
                        int64* const value) {
  CHECK(value != nullptr);
  const int expr_type = proto.type_index();
  if (model.tags(expr_type) != ModelVisitor::kIntegerVariable) {
    return false;
  }
  if (proto.arguments_size() != 2) {
    return false;
  }
  const CpArgument& arg1_proto = proto.arguments(0);
  if (model.tags(arg1_proto.argument_index()) != ModelVisitor::kMinArgument) {
    return false;
  }
  const int64 value1 = arg1_proto.integer_value();
  const CpArgument& arg2_proto = proto.arguments(1);
  if (model.tags(arg2_proto.argument_index()) != ModelVisitor::kMaxArgument) {
    return false;
  }
  const int64 value2 = arg2_proto.integer_value();
  if (value1 == value2) {
    *value = value1;
    return true;
  } else {
    return false;
  }
}