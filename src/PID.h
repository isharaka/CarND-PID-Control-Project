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
  void control(double cte, double se, double angle, double& steering_angle, double& throttle);

private:

  /*
  * Coefficients
  */ 
  double Kp_cte;
  double Ki_cte;
  double Kd_cte;

  double Kp_se;
  double Ki_se;
  double Kd_se;

  /*
  * States
  */
  double integral_cte;
  double integral_se;

  double _cte;
  double _se;
};

#endif /* PID_H */
