/*
  ==============================================================================

    ToneStage.h
    Created: 1 Sep 2022 11:17:50am
    Author:  AkshayDhengre

  ==============================================================================
*/

#pragma once

#include<cmath>

class ToneFilter

{
public:
    void coefficientTFEquations()
    {
        
    }
    
    double process(double input)
    {
        x = input;
        double y =  A0 * x + A1 * xz + A2 * xzz - B1 * yz - B2 * yzz;
        
        xzz = xz;
        xz = x;
        yzz = yz;
        yz = y;
        
        return y;
    }
    
 //--------------------------------------------------------------------------
   
private:

    double SampleRate = 48000.0;
    const double T = 0.85;
    const double dt = (1 / SampleRate);
    
    const double R4 = 2.2e3;
    const double R3 = 6.8e3;
    const double R5 = 6.8e3;
    const double C2 = 0.022e-6;
    const double C1 = 0.1e-6;
    const double Rpot = 20e3; 
    const double k1 = ( 1 - T) * Rpot;
    const double k2 = T * Rpot;
    const double c = (2 / dt);
    
    
    // Transfer function coefficients

    const double a0 = R3 + R4 + Rpot;
    const double a1 = (C1 * R5 * (R3 + Rpot) + C2 * (R3 * (R4 + R5 + Rpot) + R4 * (R5 + Rpot)));    
    const double a2 = C1 * C2 * R5 * (R3 * (R4 + Rpot) + R4 * Rpot);
    const double b0 = (1 - T) * Rpot + R3;
    const double b1 = C2 * ((1 - T) * R4 * Rpot + R3 * (R4 + R5 + Rpot));
    const double b2 = T * C1 * C2 * R3 * R5 * Rpot;
    
   
    // Bilinear Transform
    double B0 = (b0 + (b1 * c) + b2 * (c));
    double B1 = ((2 * b0) - (2 * b2) * (c));
    double B2 = (b0 - (b1 * c) + b2 * (c));
    double A0 = (a0 + (a1 * c) + a2 * (c));
    double A1 = ((2 * a0) - (2 * a2) * (c));
    double A2 = (a0 - (a1 * c) + a2 * (c));
   
    double z = 0;
    double x = 0;
    double xz = 0;
    double xzz = 0;
    double y = 0;
    double yz = 0;
    double yzz = 0;
   
    };