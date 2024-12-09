void XLeader::SetServerModel(XConfig * config, XModel * model, XList * memberModels)
{
    serverModel.Clear();
    for (int i = 0; i < model->paramNum; i++) {
        XTensor * param = model->params[i].tensor;
        serverModel.AddParam(param);
    }

    /* TODO: we can place parameters on different devices */
}