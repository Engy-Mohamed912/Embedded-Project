#ifndef LCD_h_
#define LCD_h_
#define  DATAPORT    'A'
#define  CTRLPORT    'B'


#define clear_display     0x01
#define returnHome        0x02
#define moveCursorRight   0x06
#define moveCursorLeft    0x08
#define shiftDisplayRight 0x1C
#define shiftDisplayLeft  0x18
#define cursorBlink       0x0F
#define cursorOff         0x0C
#define cursorOn          0x0E
#define Function_set_4bit 0x28
#define Function_set_8bit 0x38
#define Entry_mode        0x06
#define Function_8_bit    0x32
#define Set5x7FontSize    0x20
#define FirstRow          0x80

#define EN   0
#define RS  1
#define RW  2
void LCD_Init (void);
static void Send_Pulse (void);
void LCD_Send_Cmd (unsigned char Cmd);
void LCD_Send_String(unsigned char *data);
void LCD_clear_display (void);
void LCD_movecursor (unsigned char row , unsigned char col);
void LCD_Send_Char (unsigned char Char);
void LCD_Print_Int(int x) ;



#endif
