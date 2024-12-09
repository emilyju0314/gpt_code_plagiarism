void ExportToGraphFile(const CpModel& proto, File* const file,
                       GraphExporter::GraphFormat format) {
  std::unique_ptr<GraphExporter> exporter(
      GraphExporter::MakeFileExporter(file, format));
  exporter->WriteHeader(proto.model());
  for (int i = 0; i < proto.expressions_size(); ++i) {
    DeclareExpression(i, proto, exporter.get());
  }

  for (int i = 0; i < proto.intervals_size(); ++i) {
    DeclareInterval(i, proto, exporter.get());
  }

  for (int i = 0; i < proto.sequences_size(); ++i) {
    DeclareSequence(i, proto, exporter.get());
  }

  for (int i = 0; i < proto.constraints_size(); ++i) {
    DeclareConstraint(i, proto, exporter.get());
  }

  const char kObjLabel[] = "obj";
  if (proto.has_objective()) {
    const std::string name = proto.objective().maximize() ? "Maximize" : "Minimize";
    exporter->WriteNode(kObjLabel, name, "diamond", kRed);
  }

  for (int i = 0; i < proto.expressions_size(); ++i) {
    const CpIntegerExpression& expr = proto.expressions(i);
    const std::string label = ExprLabel(i);
    for (int j = 0; j < expr.arguments_size(); ++j) {
      ExportLinks(proto, label, expr.arguments(j), exporter.get());
    }
  }

  for (int i = 0; i < proto.intervals_size(); ++i) {
    const CpIntervalVariable& interval = proto.intervals(i);
    const std::string label = IntervalLabel(i);
    for (int j = 0; j < interval.arguments_size(); ++j) {
      ExportLinks(proto, label, interval.arguments(j), exporter.get());
    }
  }

  for (int i = 0; i < proto.sequences_size(); ++i) {
    const CpSequenceVariable& sequence = proto.sequences(i);
    const std::string label = SequenceLabel(i);
    for (int j = 0; j < sequence.arguments_size(); ++j) {
      ExportLinks(proto, label, sequence.arguments(j), exporter.get());
    }
  }

  for (int i = 0; i < proto.constraints_size(); ++i) {
    const CpConstraint& ct = proto.constraints(i);
    const std::string label = ConstraintLabel(i);
    for (int j = 0; j < ct.arguments_size(); ++j) {
      ExportLinks(proto, label, ct.arguments(j), exporter.get());
    }
  }

  if (proto.has_objective()) {
    const CpObjective& obj = proto.objective();
    exporter->WriteLink(kObjLabel, ExprLabel(obj.objective_index()),
                        ModelVisitor::kExpressionArgument);
  }
  exporter->WriteFooter();
}