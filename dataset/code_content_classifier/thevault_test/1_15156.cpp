ConvDtypes GetBestConvDtypes(Dtype out_dtype) {
    // TODO(imanishi): Support TRUE_HALF_CONFIG data type configuration if the compute capability is 5.3 or later.
    // TODO(niboshi): Devices with CC>=6.1 should support (int8, int32, int8) and (int8, int32, float32).

    // Float output
    switch (out_dtype) {
        case Dtype::kFloat16:
            if (out_dtype == Dtype::kFloat16) {
                // PSEUDO_HALF_CONFIG
                return ConvDtypes{Dtype::kFloat16, Dtype::kFloat32, Dtype::kFloat16};
            }
            return ConvDtypes{Dtype::kFloat32, Dtype::kFloat32, Dtype::kFloat32};
        case Dtype::kFloat32:
            return ConvDtypes{Dtype::kFloat32, Dtype::kFloat32, Dtype::kFloat32};
        case Dtype::kFloat64:
            return ConvDtypes{Dtype::kFloat64, Dtype::kFloat64, Dtype::kFloat64};
        default:
            break;
    }

    // Non-float output
    return ConvDtypes{Dtype::kFloat64, Dtype::kFloat64, Dtype::kFloat64};
}