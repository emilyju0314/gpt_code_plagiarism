void Mean(const Array& a, const Axes& axis, const Array& out) {
    Device& device = a.device();
    device.backend().CallOp<SumOp>(a, axis, out);
    device.backend().CallOp<DivideASOp>(out, internal::CountItemsAlongAxes(a.shape(), axis), out);
}