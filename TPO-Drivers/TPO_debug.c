/*
 * TPO_debug.c
 *
 *  Created on: Oct 14, 2017
 *      Author: maximilano
 */

#include <Infotronic.h>
#include <global_variables.h>
//#include <stdio.h>

// Para debug
extern int pos_fin[8];
extern int pos_ini[8];
extern int is_moving;
//int buf [4]={100,150,1000}; //-90°,0°,90°
//int buf_2 [4]={54,500,1000};
int buf1 [6]={100,150,200,100,125,199}; //-90°,0°,90°
int buf2 [6]={150,100,200,125,150,200}; //-90°,0°,90°
int buf3 [6]={100,125,150,175,200,175}; //-90°,0°,90°
int buf4 [6]={200,150,100,200,100,200}; //-90°,0°,90°


void EINT3_IRQHandler( void )
{
	EXTINT |= ( 1 << EINT3 );	// borro el flag EINT3 de interrupcion externa 3 del registro EXTINT

	static int contador = 0;
	//printf ("HOLA/n");

	//pos_fin[5]=buf[contador];
	//pos_ini[5]= pos_motor[5];

	pos_fin[0]=buf1[contador];
	pos_ini[0]= pos_motor[0];

	pos_fin[1]=buf2[contador];
	pos_ini[1]= pos_motor[1];

	pos_fin[2]=buf3[contador];
	pos_ini[2]= pos_motor[2];

	pos_fin[5]=buf4[contador];
	pos_ini[5]= pos_motor[5];


	printf("BOTON presionado. Posicion: %d \n",pos_motor[5]);

	cont_periodo = 0;	// MUY IMORTANTE: Cuando cae un mensaje nuevo se debe volver a hacer calculos desde mover_motor() con contador_periodo = 0

	contador++;

	//if(contador==3)
	if(contador==5)
		contador=0;



	// Solo para debuggg
	if( GetPIN( 0 , 24 , 1 ) )	// puerto = 0 , pin =  24 ; actividad = ALTO
			SetPIN( 0 , 24 , 0 );	// puerto = 0 , pin =  24 ; estado = 0
		else
			SetPIN( 0 , 24 , 1 );	// puerto = 0 , pin =  24 ; estado = 1



}
