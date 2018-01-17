#ifndef PID_H
#define PID_H

class PID {
public:
  //PID coefficients
  double Kp;
  double Ki;
  double Kd;
  
  //Error for each terem
  double p_error;
  double i_error;
  double d_error;

  double prev_cte;


  // Constructor
  PID();

  // Destructor
  virtual ~PID();

 // Initialize PID
  void Init(double Kp, double Ki, double Kd);

 // Calculate PID error variables given cross track error.
  void UpdateError(double cte);

 //Calculate the total PID error
 double TotalError();

 //Calculate steering value
 double CalculateSteering();

 //Calculate thorttle value
 double CalculateThrottle();

};

#endif /* PID_H */
