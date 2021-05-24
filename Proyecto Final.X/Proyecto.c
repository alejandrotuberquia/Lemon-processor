/////////////////// DATOS DEL PROGRAMA ////////////////////
                                                            
//  TÍTULO:           	Procesador de limones 											
//  MICRO:PIC16F15244 Curiosity Nano.						
//  ESTUDIANTES:Braian Aejandro Tuberquia Arciniegas- 2420182022
//              Juan Felipe Camargo Espinosa-2420182012  




///////////// CONFIGURACIÓN INICIAL PIC ///////////////////

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "flex_lcd.h" //Libreria para LCD.

#pragma config FEXTOSC = OFF // External Oscillator Mode Selection bits->Oscillator not enabled
#pragma config RSTOSC = HFINTOSC_1MHZ // Power-up Default Value for COSC bits->HFINTOSC (1 MHz)
#pragma config CLKOUTEN = OFF // Clock Out Enable bit->CLKOUT function is disabled; I/O function on RA4
#pragma config VDDAR = HI // VDD Range Analog Calibration Selection bit->Internal analog systems are calibrated for operation between VDD = 2.3V - 5.5V

// CONFIG2
#pragma config MCLRE = EXTMCLR // Master Clear Enable bit->If LVP = 0, MCLR pin is MCLR; If LVP = 1, RA3 pin function is MCLR
#pragma config PWRTS = PWRT_OFF // Power-up Timer Selection bits->PWRT is disabled
#pragma config WDTE = OFF // WDT Operating Mode bits->WDT disabled; SEN is ignored
#pragma config BOREN = ON // Brown-out Reset Enable bits->Brown-out Reset Enabled, SBOREN bit is ignored
#pragma config BORV = LO // Brown-out Reset Voltage Selection bit->Brown-out Reset Voltage (VBOR) set to 1.9V
#pragma config PPS1WAY = ON // PPSLOCKED One-Way Set Enable bit->The PPSLOCKED bit can be cleared and set only once in software
#pragma config STVREN = ON // Stack Overflow/Underflow Reset Enable bit->Stack Overflow or Underflow will cause a reset

// CONFIG4
#pragma config BBSIZE = BB512 // Boot Block Size Selection bits->512 words boot block size
#pragma config BBEN = OFF // Boot Block Enable bit->Boot Block is disabled
#pragma config SAFEN = OFF // SAF Enable bit->SAF is disabled
#pragma config WRTAPP = OFF // Application Block Write Protection bit->Application Block is not write-protected
#pragma config WRTB = OFF // Boot Block Write Protection bit->Boot Block is not write-protected
#pragma config WRTC = OFF // Configuration Registers Write Protection bit->Configuration Registers are not write-protected
#pragma config WRTSAF = OFF // Storage Area Flash (SAF) Write Protection bit->SAF is not write-protected
#pragma config LVP = ON // Low Voltage Programming Enable bit->Low Voltage programming enabled. MCLR/Vpp pin function is MCLR. MCLRE Configuration bit is ignored.

// CONFIG5
#pragma config CP = OFF // User Program Flash Memory Code Protection bit->User Program Flash Memory code protection is disabled


///////////// DEFINICIÓN PARA USO DE PUERTOS ///////////////////

#define _XTAL_FREQ 1000000
#define Led_azul PORTBbits.RB7 //Led azul
#define S1 PORTBbits.RB5 //Sensor 
#define SW1 PORTAbits.RA1 // SW1
#define Led_verde PORTAbits.RA5 // Led verde
#define ACQ_US_DELAY 10


/*uint8_t contador = 0;
uint8_t maximo = 20;
char s[20];*/

void PIN_MANAGER_Initialize(void) 
{
  // LATx registers
  LATA = 0x00;
  LATB = 0x00;
  LATC = 0x00;

  // TRISx registers
  TRISA = 0b00010000;
  TRISB = 0b10100000;
  TRISC = 0b00000100;

  // ANSELx registers
  ANSELC = 0;
  ANSELB = 0;
  ANSELA = 0;

  // WPUx registers/
 
  WPUC = 0x04;

  // ODx registers
  ODCONA = 0x04;
  ODCONB = 0x00;
  ODCONC = 0x00;

  // SLRCONx registers
  SLRCONA = 0x37;
  SLRCONB = 0xFF;
  SLRCONC = 0xFF;

  // INLVLx registers
  INLVLA = 0x3F;
  INLVLB = 0xFF;
  INLVLC = 0xFF;

}

char CONT[20];
int contador;
int paca;


void main(void)
{
    PIN_MANAGER_Initialize();
    LATAbits.LATA2=1;
    
    
    Lcd_Init();
    Lcd_Cmd(LCD_CURSOR_OFF);
    __delay_ms(1000);
      while(1){
    if(S1==1){
    __delay_ms(20);
    }
    if(S1==0){
        contador++;
         sprintf(CONT, "NumLimones %d",contador);
        Lcd_Out2(1,2,CONT);
        __delay_ms(1000);
        
    }
    if (contador==10){
              
        sprintf(CONT, "Pacas 1");
        Lcd_Out2(2,2,CONT);
        __delay_ms(500);
        
    }
    if (contador==20){
        
        sprintf(CONT, "Pacas 2");
        Lcd_Out2(2,2,CONT);
        __delay_ms(500);
        
    }
    if (contador==30){
             
        sprintf(CONT, "Pacas 3");
        Lcd_Out2(2,2,CONT);
        __delay_ms(500);
        
    }
    if (contador==40){
             
        sprintf(CONT, "Pacas 4");
        Lcd_Out2(2,2,CONT);
        __delay_ms(500);
        
    }
    if (contador==50){
             
        sprintf(CONT, "Pacas 5");
        Lcd_Out2(2,2,CONT);
        __delay_ms(500);
        
    }
      if (contador==60){
             
        sprintf(CONT, "Pacas 6");
        Lcd_Out2(2,2,CONT);
        __delay_ms(500);
        
    }
    if (contador==70){
             
        sprintf(CONT, "Pacas 7");
        Lcd_Out2(2,2,CONT);
        __delay_ms(500);
        
    }
    if (contador==80){
             
        sprintf(CONT, "Pacas 8");
        Lcd_Out2(2,2,CONT);
        __delay_ms(500);
        
    }
    if (contador==90){
             
        sprintf(CONT, "Pacas 9");
        Lcd_Out2(2,2,CONT);
        __delay_ms(500);
        
    }
    if (contador==100){
             
        sprintf(CONT, "Pacas 10");
        Lcd_Out2(2,2,CONT);
        __delay_ms(500);
        
    }
  }
}