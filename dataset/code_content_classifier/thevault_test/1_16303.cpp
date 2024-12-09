SurfaceAssembler::SurfaceAssembler(Operator* operat,
                                     FiniteElemSpace const* rowFeSpace,
                                     FiniteElemSpace const* colFeSpace,
                                     VectorOfFixVecs<DimVec<double>>& coords)
    : Assembler(operat, rowFeSpace, colFeSpace, -1),
      coords_(coords)
  {
    TEST_EXIT(rowDim_ == colDim_)("rowDim_ != colDim_\n");

    SubQuadrature* subQuadrature;

    if (rowQuad11_)
    {
      subQuadrature = new SubQuadrature(rowQuad11_, rowDim_);
      rowQuad11_ = colQuad11_ = subQuadrature;
      subQuadrature->scaleQuadrature(coords_);
      rowQPInfo11_ = colQPInfo11_ = QPInfo::provideQPInfo(rowQuad11_, NULL);
    }
    if (rowQuad10_)
    {
      subQuadrature = new SubQuadrature(rowQuad10_, rowDim_);
      rowQuad10_ = colQuad10_ = subQuadrature;
      subQuadrature->scaleQuadrature(coords_);
      rowQPInfo10_ = colQPInfo10_ = QPInfo::provideQPInfo(rowQuad10_, NULL);
    }
    if (rowQuad01_)
    {
      subQuadrature = new SubQuadrature(rowQuad01_, rowDim_);
      rowQuad01_ = colQuad01_ = subQuadrature;
      subQuadrature->scaleQuadrature(coords_);
      rowQPInfo01_ = colQPInfo01_ = QPInfo::provideQPInfo(rowQuad01_, NULL);
    }
    if (rowQuad00_)
    {
      subQuadrature = new SubQuadrature(rowQuad00_, rowDim_);
      rowQuad00_ = colQuad00_ = subQuadrature;
      subQuadrature->scaleQuadrature(coords_);
      rowQPInfo00_ = colQPInfo00_ = QPInfo::provideQPInfo(rowQuad00_, NULL);
    }
  }