/*
 * casainteligenta.c
 *
 * Created: 5/10/2018 10:49:19 AM
 * Author : Mircea.Sarateanu
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>


static unsigned int puteresolara = 0;
static unsigned int timdiferential = 14;
static unsigned int putereretea = 7;//Puterea in kilowati asignata de catre furnizorul de electricitate
static unsigned int putereconsumata = 0;

static unsigned int baleiaj = 0;
static unsigned int ciclu = 0;

static unsigned int tick = 1;

void afisare_LCD(unsigned int numar1, unsigned int numar2, unsigned int digit)
{
	unsigned int separat[3];
	unsigned int unitati, zeci, sute;
	unsigned int valoare, count, aux;
	valoare = numar1;
	count = 0;
	aux = 0;
	separat[0] = separat[1] = separat[2] = 0;
	while(valoare!=0)
	{
		aux = valoare % 10;
		valoare = valoare / 10;
		separat[count] = aux;
		count ++;
		
	}//END WHILE
	
	sute = separat[2];
	zeci = separat[1];
	unitati = separat[0];//Separa numarul in componente numar1
	
	
	unsigned int vector1[3];
	unsigned int zeci2, unitati2, sute2;
	unsigned int valoare2, count2, aux2;
	
	valoare2 = numar2;
	count2 = 0;
	aux2 = 0;
	
	vector1[0] = vector1[1] = vector1[2] = 0;
	
	while(valoare2 !=0){
		
		aux2 = valoare2 % 10;
		valoare2 = valoare2 / 10;
		vector1[count2] = aux2;
		count2 ++;
		
		
	}//END WHILE
	
	sute2 = vector1[2];
	zeci2 = vector1[1];
	unitati2 = vector1[0];
	
	
	
	if(digit == 0){
		PORTC |= (1<<PC0);
		PORTC &= ~((1<<PC3)|(1<<PC2)|(1<<PC1)|(1<<PC4)|(1<<PC5));
		switch(unitati){
			
			case 0 : PORTD = 0b00111111;  break;
			case 1 : PORTD = 0b00000110;  break;
			case 2 : PORTD = 0b01011011;  break;
			case 3 : PORTD = 0b01001111;  break;
			case 4 : PORTD = 0b01100110;  break;
			case 5 : PORTD = 0b01101101;  break;
			case 6 : PORTD = 0b01111101;  break;
			case 7 : PORTD = 0b00000111;  break;
			case 8 : PORTD = 0b01111111;  break;
			case 9 : PORTD = 0b01101111;  break;
			
			
			
		}
		
	}//END IF
	
	
	if(digit == 1){
		PORTC |=(1<<PC1);
		PORTC &= ~((1<<PC3)|(1<<PC2)|(1<<PC0)|(1<<PC4)|(1<<PC5));
		switch(zeci){
			
			case 0 : PORTD = 0b00111111;  break;
			case 1 : PORTD = 0b00000110;  break;
			case 2 : PORTD = 0b01011011;  break;
			case 3 : PORTD = 0b01001111;  break;
			case 4 : PORTD = 0b01100110;  break;
			case 5 : PORTD = 0b01101101;  break;
			case 6 : PORTD = 0b01111101;  break;
			case 7 : PORTD = 0b00000111;  break;
			case 8 : PORTD = 0b01111111;  break;
			case 9 : PORTD = 0b01101111;  break;
			
			
			
		}
		
		
		
	}//END IF
	
	
	
	
	if(digit == 2){
		PORTC |=(1<<PC2);
		PORTC &= ~((1<<PC3)|(1<<PC1)|(1<<PC0)|(1<<PC4)|(1<<PC5));
		switch(sute){
			
			case 0 : PORTD = 0b00111111;  break;
			case 1 : PORTD = 0b00000110;  break;
			case 2 : PORTD = 0b01011011;  break;
			case 3 : PORTD = 0b01001111;  break;
			case 4 : PORTD = 0b01100110;  break;
			case 5 : PORTD = 0b01101101;  break;
			case 6 : PORTD = 0b01111101;  break;
			case 7 : PORTD = 0b00000111;  break;
			case 8 : PORTD = 0b01111111;  break;
			case 9 : PORTD = 0b01101111;  break;
			
			
			
		}
		
		
		
	}//END IF
	
	if(digit == 3){
		PORTC |=(1<<PC3);
		PORTC &= ~((1<<PC1)|(1<<PC2)|(1<<PC0)|(1<<PC4)|(1<<PC5));
		switch(unitati2){
			
			case 0 : PORTD = 0b00111111;  break;
			case 1 : PORTD = 0b00000110;  break;
			case 2 : PORTD = 0b01011011;  break;
			case 3 : PORTD = 0b01001111;  break;
			case 4 : PORTD = 0b01100110;  break;
			case 5 : PORTD = 0b01101101;  break;
			case 6 : PORTD = 0b01111101;  break;
			case 7 : PORTD = 0b00000111;  break;
			case 8 : PORTD = 0b01111111;  break;
			case 9 : PORTD = 0b01101111;  break;
			
			
			
		}
		
		
		
	}//END IF
	
	
	if(digit == 4){
		PORTC |= (1<<PC4);
		PORTC &= ~((1<<PC3)|(1<<PC2)|(1<<PC1)|(1<<PC0)|(1<<PC5));
		switch(zeci2){
			
			case 0 : PORTD = 0b00111111;  break;
			case 1 : PORTD = 0b00000110;  break;
			case 2 : PORTD = 0b01011011;  break;
			case 3 : PORTD = 0b01001111;  break;
			case 4 : PORTD = 0b01100110;  break;
			case 5 : PORTD = 0b01101101;  break;
			case 6 : PORTD = 0b01111101;  break;
			case 7 : PORTD = 0b00000111;  break;
			case 8 : PORTD = 0b01111111;  break;
			case 9 : PORTD = 0b01101111;  break;
			
			
			
		}
		
		
		
	}
	
	
	if(digit == 5){
		PORTC |= (1<<PC5);
		PORTC &= ~((1<<PC3)|(1<<PC2)|(1<<PC1)|(1<<PC0)|(1<<PC4));
		switch(sute2){
			
			case 0 : PORTD = 0b00111111;  break;
			case 1 : PORTD = 0b00000110;  break;
			case 2 : PORTD = 0b01011011;  break;
			case 3 : PORTD = 0b01001111;  break;
			case 4 : PORTD = 0b01100110;  break;
			case 5 : PORTD = 0b01101101;  break;
			case 6 : PORTD = 0b01111101;  break;
			case 7 : PORTD = 0b00000111;  break;
			case 8 : PORTD = 0b01111111;  break;
			case 9 : PORTD = 0b01101111;  break;
			
			
			
		}
		
		
		
	}
}//END FUNCTION


ISR(TIMER0_OVF_vect){
	
	
	afisare_LCD(puteresolara, tick, baleiaj);
	baleiaj = baleiaj + 1;
	if(baleiaj == 6){baleiaj = 0;}
	
	
	
}

ISR(TIMER1_OVF_vect){
	if(tick<timdiferential){if((PIND&(1<<PD7))==0){
		         tick = 1;
		         PORTB |=(1<<PB1);//Releu pe conventional pentru depanare
		         PORTA |=(1<<PA2);
		         PORTA &=~(1<<PA3);}
				 tick = tick + 1;
				 
							}
							
							
							
		else{
			tick = 1;
	if((PIND&(1<<PD7))==0){
		PORTB &=~(1<<PB1);//Releu pe solar
		PORTA |=(1<<PA3);
		PORTA &=~(1<<PA2);}
		else{
	if(ciclu == 0){//implementeaza un toggle folosind variabila ciclu
		ciclu = 1;
		
	PORTB |=(1<<PB1);//Releu pe conventional
	PORTA |=(1<<PA2);
	PORTA &=~(1<<PA3);
	timdiferential = 10;
	}
	else {
		
		ciclu = 0;
		PORTB &=~(1<<PB1);//Aici este pe solar
		PORTA |=(1<<PA3);
		PORTA &=~(1<<PA2);
		timdiferential = 14;
	}
	
		}
		
		}
		
		
}




void initializare_ADC()
{
	ADMUX = 0;
	ADMUX |= (1<<REFS0);//Vezi pagina 211 din datasheet Atmega16 5V pe AVCC AREF cu capacitate la masa
	ADCSRA |= (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);//Enable ADC si stabilire factor divizare frecventa core cu 128
	
	
}//END FUNCTION


unsigned int citeste_ADC(int intrare)
{
	
	
	unsigned int rezultat;
	ADMUX = 0;
	ADMUX = (1<<REFS0);
	
	if(intrare == 0)
	{
		ADMUX |=(1<<REFS0);
		ADCSRA |= (1<<ADSC);
		while((ADCSRA & (1<<ADIF))==0)
		{
			//Asteapta sfarsitul conversiei
			
		}
		
		rezultat = ADCL + (ADCH*256);
	}
	
	
	if(intrare == 1)
	{
		ADMUX |=(1<<REFS0)|(1<<MUX0);
		ADCSRA |= (1<<ADSC);
		while((ADCSRA & (1<<ADIF))==0)
		{
			//Asteapta sfarsitul conversiei
			
		}
		
		rezultat = ADCL + (ADCH*256);
		
	}
	
	
	return rezultat;
}//END FUNCTION



ISR(TIMER2_OVF_vect){
	
	
	putereconsumata = citeste_ADC(1)/10;
	puteresolara = citeste_ADC(0)/51.2;
	
	
	
}

int main(void)
{
	unsigned int incarca = 0;
   DDRB = 0xFF;
   PORTB = 0;
   DDRC = 0xFF;
   DDRD = 0xFF;
   PORTC = 0;
   PORTD = 0;
   sei();//Activare sistem intrerupere globala
   
   DDRA |= (1<<PA2)|(1<<PA3);//Leduri pentru semnalizarea sursei de putere utilizate, PA2 - LED ROSU - SOLAR, PA3 - LED VERDE - RETEA//
   DDRD &= ~(1<<PD7);//Buton trecere fortata pe energie electrica normala
   initializare_ADC();
   
   TIMSK |= (1<<TOIE0)|(1<<TOIE2)|(1<<TOIE1);
   TCCR0 = 0;
   TCCR0 |= (1<<CS01);//TIMER 0 PENTRU AFISAREA PE DISPLAY
   //CS02	CS01	CS00	sursa
   //0		0		0		fara sursa
   //0		0		1		CLK
   //0		1		0		CLK/8
   //0		1		1		CLK/64
   //1		0		0		CLK/256
   //1		0		1		CLK/1024
   
   
   
   TCCR2 = 0;
   TCCR2 |= (1<<CS21)|(1<<CS20);//TIMER 2 PENTRU CITIREA ADC-ului
   
   //CS22	CS21	CS20	sursa
   //0		0		0		fara sursa
   //0		0		1		CLK
   //0		1		0		CLK/8
   //0		1		1		CLK/32
   //1		0		0		CLK/64
   //1		0		1		CLK/128
   //1		1		0		CLK/256
   //1		1		1		CLK/1024
   
   TCCR1A = 0;
   TCCR1B |= (1<<CS11)|(1<<CS10);//1Hz
   
   
   
    while (1) 
    {
		
		
    }
}

