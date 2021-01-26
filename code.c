// LCD module connections
sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;
// End LCD module connections
//fonction pour convertir la valeur analogique fournie par le capteur de temperature, a une valeur numerique affichée sur LCD
unsigned int conv_temp(unsigned int input){
          unsigned int result;
          result=((input*50)/1023)+10;
          return result;
          }
//fonction pour convertir la valeur analogique fournie par le capteur de tension, a une valeur numerique affichée sur LCD
float conv_volt(unsigned int input){
          float result;
          result=(input*12.00)/1023;
          return result;
          }
void main(){
  unsigned int dw1;  // pour stocker la val analogique de capt de temperature
  unsigned int dw2;  // pour stocker la val analogique de capt de tension
  char txt1[14];     // covertir le type de DW1 vers une CHAR pour l'afficher sur LCD
  char txt2[14];     // covertir le type de DW2 vers une CHAR pour l'afficher sur LCD
  TRISA  = 0xFF;              // PORTA is input
  TRISB  = 0x00;              // PORTB is output
  PORTB = 0x00;               // initialiser tous les vals a zero
  ADC_Init();                 // Initialize ADC module with default settings
  Lcd_Init();                 // Initialize LCD
  Lcd_Cmd(_LCD_CLEAR);        // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);   // Cursor off
  Lcd_Out(1,2,"grp10 : projet1");  // salutation
  Delay_ms(2000);
  Lcd_Cmd(_LCD_CLEAR);        // Clear display
  // l'utilisation d'une boucle infinit pour maintien l'operation de captage et affichage des vals
  do {
    dw1 = ADC_Read(0);                     // Get 10-bit results of AD conversion (AN0)
    WordToStr(conv_temp(dw1),txt1);        // convertir le type de valeur vers une chaine de caractere CHAR
    Lcd_Out(1,4,txt1);                     // Write text in first row
    Lcd_Out(1,10,"°C");                    // Write text in first row
    dw2 = ADC_Read(1);                     // Get 8-bit results of AD conversion (AN1)
    FloatToStr_fixlen(conv_volt(dw2),txt2,4);        // convertir le type de valeur vers une chaine de caractere CHAR
    Lcd_Out(2,4,txt2);                     // Write text in second row
    Lcd_Out(2,10,"-V");                    // Write text in second row
    if( conv_temp(dw1)>=30 ) portb.B6 = 1;
    else portb.b6 = 0;
    if(conv_volt(dw2)<=2.4 ) portb.b7=1;
    else portb.b7=0;
    delay_ms(200);
  } while(1);
}