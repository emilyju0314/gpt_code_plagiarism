void XWorkerBroadcast::BroadcastData(XTensorKeeper * source, XList * targetList)
{
    CheckNTErrors(source->flag == PARAM_STATE_UPDATED,
                  "The parameter is not ready for broadcasting");

    for (int i = 0; i < targetList->count; i++) {
        XTensorKeeper * target = (XTensorKeeper*)targetList->GetItem(i);

        /* data transmit */
        BroadcastP2P(source->tensor, target->tensor);

        /* update the flag */
        target->flag = PARAM_STATE_UPDATED;
    }
}