	#include "lib/include.h"
	#include <stdio.h>

	int main(void)
	{
	  //  uint16_t valor = 0;
	    char c = '5';
		char data_str[32] = " ";
		uint8_t letra_recibida = 0; 



	    //Configuraciones
	    Configurar_PLL(_50MHZ);//Confiuracion de velocidad de reloj
	    Configurar_UART7();//Yo FCLK 50MHZ Baudrate 57600
	    Configurar_GPIO(); //Se configura GPIO

    
		//	printString("Sonia\r\n");	//Imprime una cadena
		//printChar(c); 	//imprime solo un caracter 

		//printString("\n");  

	    while(1)
	    {
	        c = readChar(); //lee el caracter enviado por terminal
	         switch(c)		//se establecen if para diferentes casos
	         {
	             case 'r':
	                 //GPIODATA port F 662
	                 GPIOF->DATA = (1<<1); sprintf(data_str, "a\n");
	                 break;
	             case 'b':
	                 //GPIODATA port F 662
	                 GPIOF->DATA = (1<<2); sprintf(data_str, "b\n");
	                 break;
	             case 'g':
	                 //GPIODATA port F 662
	                 GPIOF->DATA = (1<<3); sprintf(data_str, "c\n");
	                 break;
	             case 'y':
	                 //GPIODATA port F 662
	                 GPIOF->DATA = (1<<3) | (1<<1); sprintf(data_str, "d\n");
	                 break;

				 case 'x': sprintf(data_str, "Sonia\n"); break; 


	             default:
		            GPIOF->DATA = (0<<1) | (0<<2) | (0<<3); sprintf(data_str, "\n");
	      	      break;
	         }
			
			 printString(data_str);

			




	    }
}
