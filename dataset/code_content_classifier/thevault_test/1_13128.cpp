void XLeader::DestroyParamMap()
{
    for(int i = 0; i < serverModel.paramNum; i++){
        if(paramMap != NULL)
            delete[] paramMap[i];
    }
    delete[] paramMap;
    modelNum = 0;
}