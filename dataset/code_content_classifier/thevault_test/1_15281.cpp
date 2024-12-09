void engine_ast::PDPNode::captureCanonicalParams()
{
    params().setPoolingType(canonicalNode()->params().poolType());
    params().setTopLeftPadding(canonicalNode()->params().topLeftPadding());
    params().setBottomRightPadding(canonicalNode()->params().bottomRightPadding());
    params().setPaddingValue(0);
    params().setStride(canonicalNode()->params().stride());
    params().setPoolingWindow(canonicalNode()->params().kernelDims());
}