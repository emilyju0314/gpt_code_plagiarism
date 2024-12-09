bool XModel::CheckParam()
{
    for (int i = 0; i < paramNum; i++) {
        XTensor * param = params[i].tensor;
        if (!param->isGrad)
            return false;
    }

    return true;
}