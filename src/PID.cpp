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
	Kp_cte(Kp_cte), Ki_cte(Ki_cte), Kd_cte(Kd_cte),
	Kp_se(Kp_se), Ki_se(Ki_se), Kd_se(Kd_se),
	integral_cte(0.0),integral_se(0.0),_cte(0.0),_se(0.0) {}

PID::~PID() {}

void PID::control(double cte, double se, double angle, double& steering_angle, double& throttle) {
	// Calculate current states
	double diffrential_cte = cte - _cte; 
	double diffrential_se = se - _se; 

	integral_cte += cte;
	integral_se += se;

	// Control algorithm
	steering_angle = std::max(-1.0, std::min(-Kp_cte*cte - Ki_cte*integral_cte - Kd_cte*diffrential_cte, 1.0));
	throttle = std::max(-1.0, std::min(-Kp_se*se - Ki_se*integral_se - Kd_se*diffrential_se, 1.0));

	// Store previous states
	_cte = cte;
	_se = se;
}