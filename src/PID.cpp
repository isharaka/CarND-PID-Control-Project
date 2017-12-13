#include "PID.h"

#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID(
	double Kp_cte, double Ki_cte, double Kd_cte,
    double Kp_se, double Ki_se, double Kd_se):
	integral_cte(0.0),integral_se(0.0),_cte(0.0),_se(0.0),timestep(0),
	twiddle_index(0), twiddle_state(0), error(0.0), best_error(0.0) {

	K[p_cte] = Kp_cte;
	K[i_cte] = Ki_cte;
	K[d_cte] = Kd_cte;
	K[p_se] = Kp_se;
	K[i_se] = Ki_se;
	K[d_se] = Kd_se;

	dK[p_cte] = 1.0;
	dK[i_cte] = 1.0;
	dK[d_cte] = 1.0;
	dK[p_se] = 1.0;
	dK[i_se] = 1.0;
	dK[d_se] = 1.0;

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

	//std::cout << timestep << " ";

	update_error(cte);

	++timestep;
}

void PID::reset()
{
	integral_cte = 0;
	integral_se = 0;
	_cte = 0;
	_se = 0;
	timestep = 0;
	error = 0;
}

void PID::update_error(double cte)
{
	if (timestep < n_settle_time)
		error = 0;
	else
		error += (cte*cte);
}


bool PID::twiddle()
{
	if (timestep > n_eval_time || error > (n_eval_time - n_settle_time)) {
	    error = error / (n_eval_time - n_settle_time);
	    
	    if ((dK[0] + dK[1] + dK[2]) > 0.2) 
	    {
		    std::cout << "error " << error << " best " << best_error
		    	<< " best K [" << _K[0] << ":" << _K[1] << ":"  << _K[2]
		    	<< "] K [" << K[0] << ":" << K[1] << ":"  << K[2]
		    	<< "] dK [" << dK[0] << ":" << dK[1] << ":"  << dK[2] << "]" << std::endl;

	    	int i = twiddle_index % 3;

	    	switch(twiddle_state)
	    	{
	    		case 0:
	    			best_error = error;
	    			memcpy(_K, K, sizeof(K));

	    			twiddle_state = 1;
	    			K[i] += dK[i];
	    			break;

	    		case 1:
	    			if (error < best_error) {
	    				best_error = error;
	    				memcpy(_K, K, sizeof(K));

	    				dK[i] *= 2.0;

	    				++twiddle_index;
	    				i = twiddle_index % 3;

	    				K[i] += dK[i];
	    			} else {
	    				K[i] -= 2*dK[i];
	    				twiddle_state = 2;
	    			}
	    			break;

	    		case 2:
	    			if (error < best_error) {
	    				best_error = error;
	    				memcpy(_K, K, sizeof(K));

	    				dK[i] *= 2.0;
	    			} else {
	    				K[i] += dK[i];
	    				dK[i] *= 0.5;
	    			}

	    			twiddle_state = 1;
	    			++twiddle_index;
	    			i = twiddle_index % 3;

	    			K[i] += dK[i];
	    			break;
	    	}

			reset();

			return true;
	    } else {
	    	return false;
	    }
	} else {
		return false;
	}
}