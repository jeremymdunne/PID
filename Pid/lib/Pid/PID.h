#ifndef _PID_H
#define _PID_H
#include <Math.h>

class PID{
public:
  PID(float kP, float kI, float kD);
  PID(float kP, float kI, float kD, float maxI, float maxError);
  float calculate(float currentValue, long elapsedMillis);
  void setSP(float setPoint);
private:
  float _kP, _kI, _kD,_SP;
  float _max_I = 0, _max_error = 0;
  float error = 0, pError = 0, iError = 0, dError = 0, totalError = 0;
};



#endif
