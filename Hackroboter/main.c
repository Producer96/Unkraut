#define MAIN 0x01  //this is the main.c

#include <stdio.h>
#include <stdlib.h>

#include "mainvars.h"
#include "gps.h"
#include "compass.h"
#include "main.h"
#include "waypoints.h"
#include "distancedirection.h"

    


float Koord_array[3]; 					//Array zum Abspeichern der aktuellen Koordinaten
float Correction_array[3];				//Korrekturdaten
float Compass_direction_array[3];		//Richtung Kompass
float Compass_accelleration_array[3];	//Beschleunigungen Kompass
int Calculation_values[MyNumber];		//"Berechnungen"; als Variable Konstante aus mainvars.h

//neue Variablen
int Nr=0;
double Waypoint_Array[10][2];
float Distance_Direction[2];
float Directiondifference;
int control_value;
int Drehrichtung; //0=links; 1=rechts
int Motordrehzahl;


int main(void)
{
	float  *p_main;
    //float *p_main10;//Pointer zum Zeigen auf float-Arrays; Datentyp wichtig wegen Iterationsschrittweite
    //float  *p_float;
    float  *p_float2;
	int    *p_integer;				//Pointer f¸r int-Arrays
    double *p_double;           //Pointer fuer double-Arrays
    
    p_double = &Waypoint_Array[0][0];
    WAYPOINTS_GetWaypoints(p_double, Nr);

	GPS_Rover_Initialize();		//Initialize des GPS-Moduls des Rovers
	GPS_Base_Initialize();		//Initialize Base-GPS
	COMPASS_Initialize();		//Initialize Kompass
    
  
	while(1)
	{
		//Koordinaten des Rovers abfragen
		p_main = &Koord_array[0];			//dem Pointer p_main wird die Addresse des Arrays uebergeben
		
		GPS_Receive_XYZ_Rover(p_main);		//Funktion zum Erhalt der XYZ-Daten des GPS wird aufgerufen
											//uebergabewert Pointer mit Addresse Speicher-Arrays
		
        
		//Korrekturdaten der Basis abfragen
		p_main = Correction_array;			//& und [0] nicht noetig, da pointer automatisch auf ersten Eintrag zeigt
	
		GPS_Receive_CorrectionXYZ_Base(p_main);
		
		//Kompass Richtung abfragen
		p_main = &Compass_direction_array[0];
		
		COMPASS_GetDirection(p_main);
		
		//Beschleunigung aus Kompassmodul auslesen
		p_main = &Compass_accelleration_array[0];
		
		COMPASS_GetAccelleration(p_main);
		
		//"Berechnungen" ausfuehren
		p_integer = &Calculation_values[0];
		
        
		//Distanz und Abweichung berechnen
        p_main = &Koord_array[0];               //enthält Korrdinaten der aktuellen Positon des Rovers
        p_float2 = &Distance_Direction[0];      //enthält Distanz und Richtung zum nächsten Wegpunkt
        p_double = &Waypoint_Array[Nr][0];      //enthält Koordinaten des Ziel-Wegpunktes
        DISTANCEDIRECTION_GetDirectionAndDistance(p_main,p_double,p_float2);        //übergabe von aktueller Position und nächsten Wegpunkt, Rückgabe von Distanz und Richtung
        
        printf("Entfernung: %f\n", Distance_Direction[0]);
        printf(" ");
        printf("Winkel: %fl\n",Distance_Direction[1]);
        
        Directiondifference=Distance_Direction[1]-Compass_direction_array[1]; //? warum 3 Compass_direction ? --> vl vorher umrechnen
        
        //if (Directiondifference<0)
        //{Directiondifference=+360;}
        
        if (Directiondifference<0)
        {Drehrichtung=1;}
        else if (Directiondifference>0)
        {Drehrichtung=0;}
        
       // p_main = &Directiondifference;   //enthält Winkeldifferenz
        //PID_CalculateMotorDrehzahl(p_main2);
        
        
        
        //bei Annäherung zum nächsten Wegpunkt weiterschalten
        if (Distance_Direction[0]<=0.001)  //Wenn Distanz kleiner als 1m --> nächster Wegpunkt
        {
            Nr++;
            printf("Neuer Wegpunkt: %d\n", Nr);
        }
	}
}


/*void pointer_info(float *p_main)
{
	printf("Adresse zeiger: %p\n", &p_main);					//Die Addresse des Zeigers anzeigen
	printf("Wert zeiger: %p\n", p_main);						//der Wert, der im Zeiger steht (Addresse des Ziels)
	printf("Wert von Adresse %f: %d\n", p_main, *p_main);	//die Addresse des Ziels, der Ihnalt des Ziels
}
*/

