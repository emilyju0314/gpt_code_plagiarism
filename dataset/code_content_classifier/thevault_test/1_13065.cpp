void XWorkerUpdate::Update(XList * args)
{
    int paramCount = 0;

    CheckNTErrors(args != NULL && args->count == 3, "Illegal argument list!");

    XWorkerUpdate * updater = (XWorkerUpdate*)args->GetItem(paramCount++);
    XTensorKeeper * paramKeeper = (XTensorKeeper*)args->GetItem(paramCount++);
    XOptimizer * optimizer = (XOptimizer*)args->GetItem(paramCount++);

    CheckNTErrors(updater != NULL, "No updater!");

    updater->UpdateParameter(paramKeeper, optimizer);
}