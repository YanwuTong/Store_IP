//prog1A.cpp
//written by Yanwu Tong for cs130a

#include "storeIP.h"
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <cmath>

using namespace std;

int main() {
  
  storeIP hashtable;
  
  string input;

  cin >> input;
 
  int temp = hashtable.findPrime(stoi(input));
  hashtable.setSize(temp);
  /*
  hashtable.a1 = 10;
  hashtable.a2 = 89;
  hashtable.a3 = 210;
  hashtable.a4 = 162;
  */

  
  hashtable.setCoe();

  while(cin >> input){
    if(input == "insert"){
      cin >> input;
      hashtable.insert(input);
    }
    else if(input == "delete"){
      cin >> input;
      hashtable.delet(input);
    }
    else if(input == "lookup"){
      cin >> input;
      hashtable.lookup(input);
    }
    else if(input == "stat"){
      cin >> input;
      hashtable.stat();
    }
 }
  
  return 0;
}
