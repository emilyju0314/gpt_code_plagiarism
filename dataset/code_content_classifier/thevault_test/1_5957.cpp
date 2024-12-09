Status ParseMlirModule(llvm::StringRef mlir_module_string,
                       mlir::MLIRContext* mlir_context,
                       mlir::OwningModuleRef* mlir_module) {
  TF_RET_CHECK(!mlir_module_string.empty())
      << "unexpected empty serialized MLIR module string";
  TF_RET_CHECK(mlir_module) << "unexpected null MLIR module pointer";

  // Make sure we catch any error reported by MLIR and forward it to the TF
  // error reporting system.
  mlir::StatusScopedDiagnosticHandler error_handler(mlir_context);

  // Parse the module.
  *mlir_module = mlir::parseSourceString(mlir_module_string, mlir_context);
  if (!*mlir_module) {
    return error_handler.Combine(
        errors::InvalidArgument("could not parse MLIR module"));
  }

  return Status::OK();
}