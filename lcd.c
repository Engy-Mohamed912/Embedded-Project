void LCD_GotoXY(uint8_t _x, uint8_t _y)
{
	if(_y)
		_x |= 0x40;
	_x |= 0x80;

	LCD_Cmd(_x);
}