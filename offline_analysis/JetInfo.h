#include <iostream>
#include <math.h>
#include <vector>
using namespace std; 
    struct JetInfo {
      float eff;
      float sf;
      JetInfo() : eff(0.), sf(0.) {}
      JetInfo(float mceff,float datasf) : eff(mceff), sf(datasf) {}
    };

