#include "mainvars.h"

void GPS_Rover_Initialize(void)
{
	
}

void GPS_Base_Initialize(void)
{
	
}


void GPS_Receive_XYZ_Rover(float *p_Sub)
{
	*p_Sub=1.5;
	*(p_Sub+1)=2.6;
	*(p_Sub+2)=3.7;
}

void GPS_Receive_CorrectionXYZ_Base(float *p_Sub)
{
	*p_Sub=1.1;
	*(p_Sub+1)=2.2;
	*(p_Sub+2)=3.3;
}
