void adns_9800::get_delta_x_y(int16_t &delta_x, int16_t &delta_y)
{
    uint16_t delta_x_l = (uint16_t)(read_reg(REG_Delta_X_L));
    uint16_t delta_x_h = (uint16_t)(read_reg(REG_Delta_X_H)) << 8;
    delta_x = (int16_t)(delta_x_h | delta_x_l);
    
    uint16_t delta_y_l = (uint16_t)(read_reg(REG_Delta_Y_L));
    uint16_t delta_y_h = (uint16_t)(read_reg(REG_Delta_Y_H)) << 8;
    delta_y = (int16_t)(delta_y_h | delta_y_l);
}