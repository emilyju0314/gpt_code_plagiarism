INT8U MCP_CAN::begin(INT8U idmodeset, INT8U speedset, INT8U clockset)
{
    INT8U res;
 
    res = mcp2515_init(idmodeset, speedset, clockset);
    if (res == MCP2515_OK)
        return CAN_OK;
    
    return CAN_FAILINIT;
}