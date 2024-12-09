std::function<LiteralIndex()> FirstUnassignedVarAtItsMinHeuristic(
    const std::vector<IntegerVariable>& vars, Model* model) {
  return [/*copy*/ vars, model]() {
    IntegerTrail* const integer_trail = model->GetOrCreate<IntegerTrail>();
    for (const IntegerVariable var : vars) {
      // Note that there is no point trying to fix a currently ignored variable.
      if (integer_trail->IsCurrentlyIgnored(var)) continue;
      const LiteralIndex decision = AtMinValue(var, model);
      if (decision != kNoLiteralIndex) return decision;
    }
    return kNoLiteralIndex;
  };
}