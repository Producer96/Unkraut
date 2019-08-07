
void COMPASS_Initialize(void)
{
}

void COMPASS_GetDirection(float *p_Sub)
{
	*p_Sub=1.5;
	*(p_Sub+1)=2.6;
	*(p_Sub+2)=2.6;
}

void COMPASS_GetAccelleration(float *p_Sub)
{
	*p_Sub=1.5;
	*(p_Sub+1)=2.6;
	*(p_Sub+2)=4.8;
}
