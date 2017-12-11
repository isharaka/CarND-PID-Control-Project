#include "PID.h"

#include <algorithm>
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID(
	double Kp_cte, double Ki_cte, double Kd_cte,
    double Kp_se, double Ki_se, double Kd_se):
	integral_cte(0.0),integral_se(0.0),_cte(0.0),_se(0.0) {

	K[p_cte] = Kp_cte;
	K[i_cte] = Ki_cte;
	K[d_cte] = Kd_cte;
	K[p_se] = Kp_se;
	K[i_se] = Ki_se;
	K[d_se] = Kd_se;

}

PID::~PID() {}

void PID::control(double cte, double se, double angle, double& steering_angle, double& throttle) {
	// Calculate current states
	double diffrential_cte = cte - _cte; 
	double diffrential_se = se - _se; 

	integral_cte += cte;
	integral_se += se;

	// Control algorithm
	steering_angle = std::max(-1.0, std::min(-K[p_cte]*cte - K[i_cte]*integral_cte - K[d_cte]*diffrential_cte, 1.0));
	throttle = std::max(-1.0, std::min(-K[p_se]*se - K[i_se]*integral_se - K[d_se]*diffrential_se, 1.0));

	// Store previous states
	_cte = cte;
	_se = se;
}