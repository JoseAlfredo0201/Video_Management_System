#ifndef UTILITIES1_H
#define UTILITIES1_H

#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include"Video.h"

using namespace std;

inline string formatMinutes(int minutos){
  int horas = minutos/60;
  int minutes = minutos % 60;
  string ans;

  if (minutes < 10)
    ans = to_string(horas) + ":0" + to_string(minutes);
  else 
    ans = to_string(horas) + ":" + to_string(minutes);




  return ans;
}


#endif // UTILITIES_H

