void LCD1in8_Driver::LCD_SetPointlColor(POINT Xpoint, POINT Ypoint, COLOR Color){
    if ((Xpoint <= sLCD_DIS.LCD_Dis_Column) && (Ypoint <= sLCD_DIS.LCD_Dis_Page)){
        LCD_SetCursor(Xpoint, Ypoint);
        LCD_SetColor(Color, 1, 1);
    }
}