void DeclareExpression(int index, const CpModel& proto,
                       GraphExporter* const exporter) {
  const CpIntegerExpression& expr = proto.expressions(index);
  const std::string label = ExprLabel(index);
  int64 value = 0;
  if (!expr.name().empty()) {
    exporter->WriteNode(label, expr.name(), "oval", kGreen1);
  } else if (GetValueIfConstant(proto, expr, &value)) {
    exporter->WriteNode(label, absl::StrCat(value), "oval", kYellow);
  } else {
    const std::string& type = proto.tags(expr.type_index());
    exporter->WriteNode(label, type, "oval", kWhite);
  }
}