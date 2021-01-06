//#define EIGENLIB			// uncomment to use Eigen linear algebra library
//#define NO_POINTER_INIT	// uncomment to disable pointer checking

#include "fun_head_fast.h"

// do not add Equations in this area

MODELBEGIN

// insert your equations here, between the MODELBEGIN and MODELEND words

EQUATION("X")
/*
Variável X é um passeio aleatório
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
RESULT(AVE("X"))

EQUATION("X_Max")
RESULT(MAX("X"))








MODELEND

// do not add Equations in this area

void close_sim( void )
{
	// close simulation special commands go here
}
