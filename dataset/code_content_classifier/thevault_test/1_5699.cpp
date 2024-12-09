SparseBO EchoBay::Reservoir::init_Wr(const int Nr, const double density,
                                     const double scalingFactor, const double leaky,const int extraParam)
{
    // Fixed Parameters
    int non_zero_units = ceil(Nr * Nr * density);
    // Wr declaration
    SparseMatrix<floatBO, 0x1> Wr(Nr, Nr);
    Wr.reserve(non_zero_units);
    Wr.setZero();
    Wr.data().squeeze();

    SparseMatrix<floatBO, 0x1> Eye(Nr, Nr);
    Eye.setIdentity();
    Eye = Eye * (1 - leaky);

    // Accumulate valid indexes
    std::unordered_set<std::pair<int, int>, pair_hash> valid_idx_hash;

    // Initialize Wr according to desired topology
    switch(_type)
    {
        // Random topology
        case 0: wr_random_fill(Wr, Nr, non_zero_units, valid_idx_hash);
                break;
        // Small World topology
        case 1: wr_swt_fill(Wr, Nr, extraParam, valid_idx_hash);
                break;
        // Cyclid Reservoir Jump topology
        case 2: wr_crj_fill(Wr, Nr, extraParam, valid_idx_hash);
                break;
    }
    // Perform spectral radius scaling
    if (_reservoirInizialization == "radius")
    {
        Wr = Wr * leaky + Eye;
        // Get scale radius for Echo State Property
        floatBO scale_radius = wr_scale_radius(Wr, scalingFactor);

        // Rescale Wr
        Wr = (Wr * scale_radius - Eye) / leaky;
    }
    else
    {
        // Rescaling according to Gallicchio 2019 paper (see documentation for details)
        floatBO scaling = 6/sqrt(density * Nr * 12) * scalingFactor;
        Wr = Wr * leaky + Eye;
        Wr = (Wr * scaling - Eye) / leaky;
    }

    // Quantization
    // Quantizer quant(8, false);
    // quant.quantize_matrix<SparseBO>(Wr);
    return Wr;
}