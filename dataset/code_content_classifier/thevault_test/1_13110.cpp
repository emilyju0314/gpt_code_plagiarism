uint64_t NMTModel::GetParamNum()
{
    TensorList params;
    GetParams(params);
    uint64_t totalNum = 0;
    for (int i = 0; i < params.Size(); i++) {
        totalNum += uint64_t(params[i]->unitNum);
    }

    return totalNum;
}