void XWorkerUpdate::UpdateParameter(XTensorKeeper * paramKeeper, XOptimizer * optimizer)
{

    CheckNTErrors(paramKeeper->flag == PARAM_STATE_COLLECTED, "The state of the parameter is wrong!");

    XTensor * param = paramKeeper->tensor;
    XTensor * grad = paramKeeper->grad;

    CheckNTErrors(grad != NULL, "No gradient!");

    /* update the parameter */
    optimizer->UpdateParam(param, grad);

    /* set the flag */
    paramKeeper->flag = PARAM_STATE_UPDATED;
}