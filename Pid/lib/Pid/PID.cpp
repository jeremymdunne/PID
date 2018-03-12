#include "PID.h"



PID::PID(float kP, float kI, float kD){
  _kP = kP;
  _kI = kI;
  _kD = kD;
}

PID::PID(float kP, float kI, float kD, float maxI, float maxError){
  _kP = kP;
  _kI = kI;
  _kD = kD;
  _max_I = maxI;
  _max_error = maxError;
}

void PID::setSP(float setPoint){
  _SP = setPoint;
}

float PID::calculate(float currentValue, long elapsedMillis){
  error = currentValue - _SP;
  pError =  error* _kP;
  iError += error * _kI * elapsedMillis/1000;
  if(_max_I != 0)
  if(fabs(iError) > _max_I) iError = iError/fabs(iError) * _max_I;
  dError = _kD * (dError  - error)/(elapsedMillis/1000);

  totalError = pError + iError + dError;
  if(_max_error != 0)
  if(fabs(totalError) > _max_error) totalError = totalError/fabs(totalError) * _max_error;
  return totalError;
}
