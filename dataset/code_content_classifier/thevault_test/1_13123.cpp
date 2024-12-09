void XLeader::SetServerModel(XConfig * config, XModel * model)
{
    XList members;
    for (int i = 0; i < jworkers.count; i++) {
        XModel * member = ((XWorkerJob*)jworkers[i])->GetModel();
        members.Add(member);
    }

    SetServerModel(config, model, &members);
}