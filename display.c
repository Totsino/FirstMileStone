void Display_at_100(void)
{
LCD_PORT_A_B();
 while(1)
{
	
  LCD_Cmd(0x01); //Clearing Screen
  LCD_Cmd(0x80); //Cruser to first index in first line
  delay_milli(500);
  LCD_Data('1');
  delay_milli(1);
  LCD_Data('0');
  delay_milli(1);
  LCD_Data('0');
  delay_milli(1);
  LCD_Data(' ');
  delay_milli(1);
  LCD_Data('M');
  delay_milli(1);
  LCD_Data(' ');
  delay_milli(1);
	LCD_Data('R');
  delay_milli(1);
  LCD_Data('E');
  delay_milli(1);
  LCD_Data('A');
  delay_milli(1);
  LCD_Data('C');
  delay_milli(1);
  LCD_Data('H');
  delay_milli(1);
  LCD_Data('E');
	delay_milli(1);
  LCD_Data('D');
	delay_milli(500);
}
