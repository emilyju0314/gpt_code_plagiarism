void XWorkerBroadcast::Broadcast(XList * args)
{
    int paramCount = 0;

    XWorkerBroadcast * broadcaster = (XWorkerBroadcast*)args->GetItem(paramCount++);
    XTensorKeeper * source = (XTensorKeeper*)args->GetItem(paramCount++);

    /* target models */
    int targetNum = args->GetItemInt(paramCount++);
    XList target;
    for (int i = 0; i < targetNum; i++) {
        XTensorKeeper * model = (XTensorKeeper*)args->GetItem(paramCount++);
        target.Add(model);
    }

    broadcaster->BroadcastData(source, &target);
}