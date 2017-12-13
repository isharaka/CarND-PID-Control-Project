#ifndef PID_H
#define PID_H

class PID {
public:

  /*
  * Constructor
  */
  PID(double Kp_cte, double Ki_cte, double Kd_cte,
      double Kp_se, double Ki_se, double Kd_se);

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Calculate control inputs given measurments
  */
  void control(
    double cte,             // in   - cross track error
    double se,              // in   - speed error
    double angle,           // in   - current steering angle
    double& steering_angle, // out  - steering angle command
    double& throttle);      // out  - throttle command

  /*
  * Twiddle algorithm
  */
  bool twiddle();           // returns true if simulator needs to be reset

private:

  void reset();
  void update_error(double cte);

 /*
  * Coefficients
  */

  enum {
  p_cte = 0,
  i_cte,
  d_cte,
  p_se,
  i_se,
  d_se,

  nK
  };
  
  double K[nK];

  /*
  * Twiddle coeffcients
  */

  /*
  * Controller States
  */
  double integral_cte;
  double integral_se;

  double _cte;
  double _se;

  /*
  * Twiddle variables
  */

  enum {
    n_settle_time = 150,
    n_eval_time = 1350
  };

  double dK[nK];    // deltas
  double _K[nK];    // best gains

  int timestep;
  int twiddle_index;
  int twiddle_state;
  double error;
  double best_error;
};

#endif /* PID_H */
