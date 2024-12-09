void DefineSplitBackward(const Array& ary, const std::vector<Array>& out, int8_t axis_norm) {
    // TODO(hvy): Avoid creating an intermediate vector of reference when BackwardBuilder accepts std::vector<Array>.
    std::vector<ConstArrayRef> out_refs{};
    out_refs.reserve(out.size());
    std::transform(out.begin(), out.end(), std::back_inserter(out_refs), [](const Array& array) { return ConstArrayRef{array}; });

    // TODO(imanishi): Avoid creating shapes of forward outputs;
    std::vector<Shape> shapes;
    shapes.reserve(out.size());
    std::transform(out.begin(), out.end(), std::back_inserter(shapes), [](const Array& array) { return array.shape(); });

    BackwardBuilder bb{"split", ary, out_refs};
    if (BackwardBuilder::Target bt = bb.CreateTarget(0)) {
        bt.Define([axis_norm, shapes = std::move(shapes), dtype = ary.dtype(), &device = ary.device()](BackwardContext& bctx) {
            std::vector<Array> output_grads;
            output_grads.reserve(bctx.output_count());
            for (size_t i = 0; i < bctx.output_count(); ++i) {
                const nonstd::optional<Array>& gy = bctx.output_grad(i);
                output_grads.emplace_back(gy.has_value() ? *gy : Zeros(shapes[i], dtype, device));
            }
            bctx.input_grad() = ConcatenateImpl(output_grads, axis_norm);
        });
    }
    bb.Finalize();
}