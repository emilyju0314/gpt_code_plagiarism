void GxCamera::setWhiteBalanceParam(bool WhiteBalanceOn, GX_AWB_LAMP_HOUSE_ENTRY lightSource)
{
    //自动白平衡光照环境
    // GX_AWB_LAMP_HOUSE_ADAPTIVE 自适应
    // GX_AWB_LAMP_HOUSE_FLUORESCENCE 荧光灯
    // GX_AWB_LAMP_HOUSE_INCANDESCENT 白炽灯
    // GX_AWB_LAMP_HOUSE_U30 光源温度3000k
    // GX_AWB_LAMP_HOUSE_D50 光源温度5000k
    // GX_AWB_LAMP_HOUSE_D65 光源温度6500k
    // GX_AWB_LAMP_HOUSE_D70 光源温度7000k
    white_balance.m_bWhiteBalance = WhiteBalanceOn;
    white_balance.lightSource = lightSource;
}