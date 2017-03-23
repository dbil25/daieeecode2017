

#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <map>

using namespace std;




int main(){

  std::map <std::string, int> mots;

  std::string line;
  ifstream myfile("data");
  while ( getline (myfile,line) )
  {
    cout << line << endl;
  }
}
