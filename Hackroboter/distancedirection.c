#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)


void DISTANCEDIRECTION_Initialize(void)
{
}

void DISTANCEDIRECTION_GetDirectionAndDistance(float *p_koord,double *p_waypoint, float *p_return)
{
    //Initialisieren der Koordinaten in Rad
    double rDLatRad = 0.0;                          //rD = Differenz der Koordinaten (für Rechnung wichtig)
    double rDLonRad = 0.0;
    double rLat1Rad = 0.0;
    double rLat2Rad = 0.0;
    double rLon1Rad = 0.0;
    double rLon2Rad = 0.0;
    
    double rLat1=*p_koord;            //Lat1/Lon1 = aktuelle Koordinaten
    double rLat2=*p_waypoint;            //Lat2/Lon2 = Zielkoordinaten des nächsten Wegpunktes
    double rLon1=*(p_koord+1);
    double rLon2=*(p_waypoint+1);
    double a = 0.0;
    double c = 0.0;
    double distance = 0.0;
    double rEarthRadius = 0.0;
    double heading;
    
    
    if ((rLat1 < -90.0) || (rLat1 > 90.0) || (rLat2 < -90.0) || (rLat2 > 90.0)
        || (rLon1 < -180.0) || (rLon1 > 180.0) || (rLon2 < -180.0)
        || (rLon2 > 180.0))
    {
       //FEHLER ABBRUCH!!
    }
    
    rDLatRad = degToRad((rLat2 - rLat1));
    rDLonRad = degToRad((rLon2 - rLon1)) ;
    rLat1Rad = degToRad((rLat1));
    rLat2Rad = degToRad((rLat2));
    rLon1Rad = degToRad((rLon1));
    rLon2Rad = degToRad((rLon1));
    
    
    //aktuelle Ausichtung von aktueller Position zu nächstem Wegpunkt berechnen
    heading = atan2(sin(rDLonRad)*cos(rLat2Rad),cos(rLat1Rad)*sin(rLat2Rad)-sin(rLat1Rad)*cos(rLat2Rad)*cos(rDLonRad));
    heading = heading*(180/3.1415926535);  // umrechnen von rad in grad
    if(heading<0){heading += 360;}   //Falls Winkel negativ, +360 grad
    //printf("Winkel:");
    //printf("Double: %.6f\n", heading);
    
    
    //Distanz zum Wegpunkt berechnen
    a = sin(rDLatRad /2) * sin(rDLatRad /2) + sin(rDLonRad /2) * sin(rDLonRad /2) * cos(rLat1Rad) * cos(rLat2Rad);
    c = 2 * atan2(sqrt(a), sqrt(1 - a));
    rEarthRadius = 6378.1370 - (21.3847 * 90.0 /((fabs(rLat1) + fabs(rLat2))/2.0));
    distance = rEarthRadius * c;
    //printf("Entfernung:");
    //printf("Double: %.6f\n", distance);

    
    //Übergabe der Werte in Pointer
    *p_return=distance;
    *(p_return+1)=heading;
    
    
    //Chord to Arc Correction based on Heading changes. Important for routes with many turns and U-turns ??
    
    /*if ((rHeading1 >= 0.0) && (rHeading1 < 360.0) && (rHeading2 >= 0.0)
     && (rHeading2 < 360.0)) {
     rDHeading = fabs(rHeading1 - rHeading2);
     if (rDHeading > 180.0) {
     rDHeading -= 180.0;
     }
     rDHeadingRad = rDHeading * DEGREE_TO_RADIANS;
     if (rDHeading > 5.0) {
     rResult = rResult * (rDHeadingRad /(2.0 * sin(rDHeadingRad /2)));
     } else {
     rResult = rResult /cos(rDHeadingRad);
     }
     }
     return rResult;
     
     */
}


