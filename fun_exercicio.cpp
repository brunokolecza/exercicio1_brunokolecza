//#define EIGENLIB			// uncomment to use Eigen linear algebra library
//#define NO_POINTER_INIT	// uncomment to disable pointer checking

#include "fun_head_fast.h"

// do not add Equations in this area

MODELBEGIN

// insert your equations here, between the MODELBEGIN and MODELEND words

EQUATION("X")
/*
Vari�vel X � um passeio aleat�rio
*/

RESULT(VL("X",1) + uniform(0,1))

EQUATION("X_Sum")
v[0]= 0;
CYCLE(cur, "FIRM")
{
		v[1] = VS(cur, "X");
		v[0] = v[0] + v[1];
}
RESULT(v[0])

EQUATION("X_Ave")
v[0] = 0; 
CYCLE(cur, "FIRM")
{
		v[1] = VS(cur, "X");
		v[0] = v[0] + v[1];
}
v[2] = v[0]/COUNT("FIRM");
RESULT(v[2])



EQUATION("X_Max")
v[0] = 0;
CYCLE(cur, "FIRM")
{
   	v[1] = VS(cur, "X");
		if(v[1] > v[0])
		{
		v[0] = v[1];
		}
		else
		{
		v[0] = v[0];
		}
}
RESULT(v[0])


EQUATION("X_Share")
v[0] = V("X");
v[1] = V("X_Sum");
if(v[1] != 0)
v[2] = v[0]/v[1];
else
v[2] = 0;
RESULT(v[2])

EQUATION("X_Share_Sum")
v[0] = 0;
CYCLE(cur, "FIRM")
{
		v[1] = VS(cur, "X_Share");
		v[0] = v[0] + v[1];
}
RESULT(v[0])		

// Desafio
EQUATION("Pos_X")
v[0] = v[1] = 0;
CYCLE(cur, "FIRM")
{
		v[1] = v[1] + 1;
		v[2] = VS(cur, "X");
		if(v[2]>v[0])
		{
		v[0] = v[2];
		v[3] = v[1];
		}
}
RESULT(v[3])

EQUATION("Rank")
SORT("FIRM", "X", "DOWN");
v[0] = 0;
CYCLE(cur, "FIRM")
{
		v[0]++;
		WRITES(cur, "firm_rank", v[0]);
}
RESULT(0)

MODELEND

// do not add Equations in this area

void close_sim( void )
{
	// close simulation special commands go here
}
