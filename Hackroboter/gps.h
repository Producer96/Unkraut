#ifndef GPS_H
 #define GPS_H 1

void GPS_Base_Initialize(void);
void GPS_Rover_Initialize(void);
void GPS_Receive_XYZ_Rover(float *p_Sub);
void GPS_Receive_CorrectionXYZ_Base(float *p_Sub);

#endif
