static _PyJIT_Result finalizeCompiledFunc(
    BorrowedRef<_PyJITContext> ctx,
    BorrowedRef<PyFunctionObject> func,
    const jit::CompiledFunction& compiled) {
  /* Subscribe to changes in the function to deopt it when needed. */
  auto func_ref = Ref<>::steal(PyWeakref_NewRef(func, nullptr));
  auto deopt_info = Ref<>::steal(DeoptInfo_New());
  auto ctx_ref = Ref<>::steal(PyWeakref_NewRef(ctx, nullptr));
  if (func_ref == nullptr || deopt_info == nullptr || ctx_ref == nullptr ||
      DeoptInfo_AddFuncSubscr(
          deopt_info, func, deopt_func_on_func_change, ctx_ref) < 0 ||
      PyDict_SetItem(ctx->deopt_info, func_ref, deopt_info) < 0) {
    return PYJIT_RESULT_UNKNOWN_ERROR;
  }

  func->vectorcall = compiled.entry_point();
  return PYJIT_RESULT_OK;
}