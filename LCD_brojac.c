
char txt[7];
unsigned brojac;

//Podesavanje sistemskih bitova za LCD (podesavanja za LCD biblioteku)
sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D7 at RB3_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D4 at RB0_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D7_Direction at TRISB3_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D4_Direction at TRISB0_bit;



void main()
{

 Lcd_init();//Inicijalizacija LCD

 //Izlazni port
 TRISD = 0;

 //Ulazni port/kanal
 TRISC.B0 = 1;
 TRISC.B1 = 1;

 PORTD=0;
 brojac=100;

 Lcd_Cmd(_LCD_CURSOR_OFF); //Komanda za iskljucivanje kursora na LCD-u

   while(1)
  {

     if(PORTC.B0==1) //Inkrementiranje brojaca zadavanjem digitalnog signala na ulazu
	 {
		brojac=brojac+1;
	 }
	 else if (PORTC.B1==1)  //Dekrementiranje brojaca zadavanjem digitalnog signala na ulazu
         {
            brojac=brojac-1;
         }

     Delay_ms(20);


     IntToStr(brojac, txt);

     Lcd_out(1,1,"Brojac:"); //Ispisivanje teksta u prvom redu 2x16 LCD-a
     Lcd_out(2,1,txt); //Ispisivanje teksta u drugom redu 2x16 LCD-a

     Delay_ms(50);



  }

}