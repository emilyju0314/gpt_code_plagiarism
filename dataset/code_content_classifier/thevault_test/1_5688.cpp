void EchoBay::Reservoir::init_WinLayers_swt()
{
    // Reset Win
    WinLayers.clear();

    // Determine the input scaling rule
    int countScale = _layerConfig[0].scaleInput.size();//-1;
    std::vector<ArrayI> NIindex = _WinIndex;
    std::vector<ArrayI> NOIndex = _WoutIndex;
    int NiCount = NIindex[0].size();
    int NoCount;

    // Homogeneous scaling
    if (countScale == 1)
    {
        MatrixBO temp = MatrixBO::Zero(_layerConfig[0].Nr, _Nu);
        temp.block(0,0,NiCount, _Nu) = _layerConfig[0].scaleInput[0] * MatrixBO::Random(NiCount, _Nu);

        WinLayers.push_back(temp);
    }
    else
    {
        // Differentiated input scaling
        MatrixBO Win(_layerConfig[0].Nr, _Nu);
        for (int cols = _Nu - 1; cols >= 0; cols--)
        {
            MatrixBO temp = MatrixBO::Zero(_layerConfig[0].Nr, 1);
            // Select a block of inputs
            temp.block(0,0,NiCount, 1) =  _layerConfig[0].scaleInput[cols] * MatrixBO::Random(NiCount, 1);
            Win.col(cols) = temp;
        }
        
        WinLayers.push_back(Win);
    }
    // Fill subsequent layers
    for (int i = 1; i < _nLayers; ++i)
    {
        MatrixBO temp = MatrixBO::Zero(_layerConfig[i].Nr, _layerConfig[i-1].Nr + 1);
        NiCount = NIindex[i].size();
        NoCount = NOIndex[i-1].size();
        temp.block(0,floor(_layerConfig[i-1].Nr/2),NiCount, NoCount) = _layerConfig[i].scaleInput[0] * MatrixBO::Random(NiCount, NoCount);
        temp.block(0,_layerConfig[i-1].Nr,NiCount, 1) = _layerConfig[i].scaleInput[0] * MatrixBO::Random(NiCount, 1);
        WinLayers.push_back(temp);
        // MatrixBO temp(_layerConfig[i].Nr, _layerConfig[i-1].Nr + 1);
        // WinLayers.push_back(_layerConfig[i].scaleInput[0] * MatrixBO::Random(_layerConfig[i].Nr, _layerConfig[i - 1].Nr + 1));       
    }
}