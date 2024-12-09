Array IfGreaterElse(const Array& x1, Scalar x2, Scalar pos, const Array& neg) {
    CheckArithmeticDtypes(GetKind(x1.dtype()), x2.kind(), false);
    Array out = Empty(x1.shape(), ResultType(pos, neg), x1.device());
    // TODO(niboshi): Create mask array and reuse in backprop.

    {
        NoBackpropModeScope scope{};
        x1.device().backend().CallOp<IfGreaterElseASSAOp>(x1, x2, pos, neg, out);
    }

    BackwardBuilder bb{"if_greater_else", neg, out};
    if (BackwardBuilder::Target bt = bb.CreateTarget(0)) {
        bt.Define([x1 = x1.AsGradStopped(), x2](BackwardContext& bctx) {
            const Array& gout = *bctx.output_grad();
            bctx.input_grad() = IfGreaterElse(x1, x2, Scalar{0, GetKind(gout.dtype())}, gout).AsType(x1.dtype(), false);
        });
    }
    bb.Finalize();

    return out;
}