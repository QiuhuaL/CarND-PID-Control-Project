#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

//constructor
PID::PID() {}


//destructor
PID::~PID() {}

//PIDinitialization  
void PID::Init(double Kp, double Ki, double Kd) {

    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    p_error = 0;
    d_error = 0;
    i_error = 0;
    prev_cte = 0;

}

//update PID error given cte (cross track error)
void PID::UpdateError(double cte) {
	if (prev_cte == 0) 
		prev_cte = cte;	
	p_error = cte;             
    i_error += cte;            
    d_error = cte - prev_cte;  
    prev_cte = cte;
}

//calculate total PID error 
double PID::TotalError() {
	return  Kp * p_error + Kd * d_error + Ki * i_error;
}


