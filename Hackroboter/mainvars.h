#ifndef MAINVARS
#define MAINVARS


 
#define MyNumber  8
 
 
 
#ifndef MAIN
 #define MAIN 0x00
#endif

#if MAIN==0x01
 #define PREFIX
#else
 #define PREFIX extern
#endif
 
 
 /************Vars************/

 PREFIX int Var_one;
 PREFIX double Var_two;
 

 
#endif
