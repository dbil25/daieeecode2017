#include "fonction.h"
#include <math.h>
#include <iostream>
using namespace std;

int fonction(unsigned int value){
  int binaire = 0;
  int division = value;
  int restant = 0;
  int m = 1;
  int decompte = 0;

  while (division != 0) {
    restant = division%2;
    division = floor(division/2);
    binaire = (binaire + restant*m );
    cout << binaire;
    cout << "           ";
    m = m*10;

    if (restant == 1){
      decompte = decompte + 1 ;
    }

  }
  return binaire;


}
