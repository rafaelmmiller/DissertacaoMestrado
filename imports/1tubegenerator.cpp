//
//  main.cpp
//  1TubeModel
//
//  Created by Rafael Miller on 03/07/14.
//  Copyright (c) 2014 Rafael M. Miller. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <string>
#include <vector>
#include <fstream>

#define Pi 3.14159265359

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

using namespace std;

int main(int argc, const char * argv[])
{
    ofstream icTable;
    string icTableName = "ic1";
    string icNumber;

    int Npart = 40000, i=1;
    double h = 0.08;//16/sqrt(Npart);
    double x=-8.0, y=-8.0;
    double r, theta;
    double E;
    int contador = 150;
    double delta_r = 0.001, delta_theta = 0.0001;
    string filename;

    int counter = 1;

    contador++;
    icNumber = to_string(contador);

    icTableName += icNumber + ".dat";
    icTable.open(icTableName);
    icTable << 40000 << "\t" << 0.08 << "\t" << 0.08 << "\t" << 0 << "\t" << -8 << "\t" << -8 << endl;

    cout << "ic" << counter << ".dat" << endl;

    cout << endl;

    for(x = -8.0; x < 8.0; x += h) {
      for(y = -8.0; y < 8.0; y += h) {
        r = sqrt(x*x + y*y);

        theta = atan2(y, x);

        E = 12 * exp(-0.0004 * pow(r,5)) +
        12.808*exp((-(r*r) - (4.4*4.4) + 2*r*4.4*cos(theta))/(0.845));

        icTable << x << "\t" << y << "\t" << E << endl;

      }
    }
    icTable.close();
    icTableName = "ic1";

    icTable.close();

    return 0;
}
