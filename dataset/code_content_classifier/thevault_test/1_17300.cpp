static LogicalResult VerifyTypesCompatibility(
    Operation::operand_type_range types, bool mask_one_dim, Operation *op) {
  constexpr int64_t kUninitialized = -1;
  int64_t common_rank = kUninitialized;
  llvm::SmallVector<int64_t, 4> common_dims;
  int64_t dim_to_mask = kUninitialized;

  // Initialize common_rank with rank of the first ranked type and verify that
  // following ranked types have the same rank.
  // Similarly, initialize each of the dimensions with the first type that has
  // the dimension size available and verify that all following types have the
  // same size for the dimension. However, if mask_one_dim is true, note down
  // the dimension index on the first mismatch and ignore dimension at that
  // index in following types.
  for (Type ty : types) {
    RankedTensorType ranked_ty = ty.dyn_cast<RankedTensorType>();
    if (!ranked_ty) continue;

    int64_t rank = ranked_ty.getRank();
    if (common_rank == kUninitialized) {
      common_rank = rank;
      common_dims.resize(common_rank, kUninitialized);
    } else if (common_rank != rank) {
      return op->emitError()
             << "operand type " << ranked_ty
             << " is not compatible with preceding operands; expected rank: "
             << common_rank;
    }

    for (int64_t i = 0, e = common_rank; i != e; i++) {
      if (i == dim_to_mask) continue;

      int64_t dim = ranked_ty.getDimSize(i);
      if (dim == kUninitialized) continue;

      int64_t &common_dim = common_dims[i];
      if (common_dim == kUninitialized) {
        common_dim = dim;
      } else if (common_dim != dim) {
        // If mask_one_dim is true, do not emit an error if this is the only
        // dimension with mismatches. Note down the dimension to mask it from
        // the following types.
        if (mask_one_dim && dim_to_mask == kUninitialized) {
          dim_to_mask = i;
          continue;
        }

        return op->emitError() << "operand type " << ranked_ty
                               << " is not compatible with preceding operands; "
                                  "expected dimension at index "
                               << i << ": " << common_dim;
      }
    }
  }
  return success();
}