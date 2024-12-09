bool TranslatorVisitor::asimd_VADDL(bool U, bool D, size_t sz, size_t Vn, size_t Vd, bool op, bool N, bool M, size_t Vm) {
    return WideInstruction(*this, U, D, sz, Vn, Vd, N, M, Vm, op ? WidenBehaviour::Second : WidenBehaviour::Both, [this](size_t esize, const auto&, const auto& reg_n, const auto& reg_m) {
        return ir.VectorAdd(esize, reg_n, reg_m);
    });
}