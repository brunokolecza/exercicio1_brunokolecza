//#define EIGENLIB			// uncomment to use Eigen linear algebra library
//#define NO_POINTER_INIT	// uncomment to disable pointer checking

#include "fun_head_fast.h"

// do not add Equations in this area

MODELBEGIN

// insert your equations here, between the MODELBEGIN and MODELEND words

EQUATION("X") // vendas da firma
v[0] = V("a");
v[1] = V("P");
v[2] = V("b");
v[3] = V("Q");
RESULT(v[0] * v[1] + v[2] * v[3] + uniform(-1,1)) 

EQUATION("X_sum")
RESULT(SUM("X"))

EQUATION("X_share") // parcela de mercado da firma
v[0] = V("X");
v[1] = V("X_sum");
if(v[1] != 0)
v[2] = v[0]/v[1];
else
v[2] = 0;
RESULT(v[2])

EQUATION("P") // preco do produto
v[0] = V("X_share") - VL("X_share", 1);
v[1] = V("c");
if (v[0] > 0)
v[2] = VL("P", 1) + v[1] * v[0];
else
v[2] = VL("P", 1) - v[1] * v[0];
RESULT(v[2])

 
EQUATION("Q") // qualidade do produto
v[0] = VL("Q",1) + uniform(-1, 1);
v[1] = VL("Q", 1);
if (v[0] > v[1])
v[2] = v[0];
else
v[2] = v[1];
RESULT(v[2])













MODELEND

// do not add Equations in this area

void close_sim( void )
{
	// close simulation special commands go here
}
