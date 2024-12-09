XTensor AttEncoder::RunFastPostNorm(XTensor& input, XTensor* mask)
{
    /* clear the history */
    if (useHistory)
        history->ClearHistory();

    XTensor x;
    x = embedder.Make(input, false, 0);

    if (useHistory)
        history->Add(x);

    for (int i = 0; i < nlayer; i++) {

        if (useHistory)
            x = history->Pop();

        XTensor selfAtt;

        /* self attention */
        selfAtt = selfAtts[i].Make(x, x, x, mask, NULL, SELF_ATT);

        /* residual connection */
        SumMe(selfAtt, x);

        /* layer normalization with post-norm for self-attn */
        selfAtt = attLayerNorms[i].Run(selfAtt);

        /* ffn */
        x = ffns[i].Make(selfAtt);

        /* residual connection */
        SumMe(x, selfAtt);

        /* layer normalization with post-norm for ffn */
        x = fnnLayerNorms[i].Run(x);

        if (useHistory)
            history->Add(x);
    }

    if (useHistory)
        x = history->Pop();

    /* clear the history while not training */
    if (useHistory && !isTraining)
        history->ClearHistory();

    if (finalNorm)
        return encoderLayerNorm->Run(x);

    return x;
}