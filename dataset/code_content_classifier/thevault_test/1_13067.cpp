XTensor AttEncoder::Make(XTensor& input, XTensor* mask)
{
    XTensor nothing;

    return Make(input, mask, nothing);
}