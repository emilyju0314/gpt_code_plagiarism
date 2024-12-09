static RankedTensorType GetRankedTensorTypeForOperand(Value operand) {
  DenseElementsAttr attr;
  if (matchPattern(operand, m_Constant(&attr))) {
    return attr.getType().dyn_cast<RankedTensorType>();
  }
  return operand.getType().dyn_cast<RankedTensorType>();
}