/*
  ADXL335.h - Library for reading the ADXL335 Accelerometer
  Created by Derek Chafin, September 14, 2011
  Released into the public domain.
*/

#ifndef ADXL335_h
#define ADXL335_h

#include "WProgram.h"

class ADXL335
{
  public:
    ADXL335(int pin_x, int pin_y, int pin_z, float aref);
    void setThreshold(float deadzone);
    boolean getFreefall();
    float getX();
    float getY();
    float getZ();
    float getRho();
    float getPhi();
    float getTheta();
    void update();
  private:
    int zeroCorrection();
    float geta2d(float gx, float gy);
    float geta3d(float gx, float gy, float gz);
    void processDeadzone(float* gv);
    float getGravity(int reading);
    float _getRho(float ax, float ay, float az);
    float _getPhi(float ax, float ay, float az);
    float _getTheta(float ax, float ay, float az);
    int _zero_x;
    int _zero_y;
    int _zero_z;
    int _pin_x;
    int _pin_y;
    int _pin_z;
    float _bias;
    float _xg;
    float _yg;
    float _zg;
    float _aref;
    float _mvG;
    float _deadzone;
    float _rad2deg;
};
#endif
