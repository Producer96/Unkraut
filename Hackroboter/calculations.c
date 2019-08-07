#include "calculations.h"


void CALCULATIONS_integers(int *p_calc, int array_length)
{
	int i;
	for (i=0;i<array_length;i++)
	{
		*(p_calc+i)=(i+1)*(i+1);
	}
}
