#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 10   //Zeilen
#define WIDTH  2    //Spalten

void WAYPOINTS_Initialize(void)
{
}

void WAYPOINTS_GetWaypoints(double *p_waypoint)
{
        FILE *myfile;
        double myvariable;
        int i;
        int j;
        int a=0;
        //double waypoint_array[10][2]={0};
    
        myfile=fopen("Waypoints.txt", "r");
        
        for(i = 0; i < HEIGHT; i++)
        {
            for (j = 0 ; j < WIDTH; j++)
            {
                
               // fscanf(myfile,"%lf",&myvariable);   //Auslesen TXT File, Ausgabe als double, Speichern in myvariable, Abbruch nach Leerzeichen oder Zeilenumbruch
                *(p_waypoint+a)=myvariable;         //Speichern des Wertes in waypoint_array
                //waypoint_array[i][j]=myvariable;
                //printf("%lf", waypoint_array[i][j]);
                a++;                                //Waypoint-Array +1
                
            }
            //printf("\n");
        }
        fclose(myfile);

    }


