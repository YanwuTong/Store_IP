//written by Yanwu Tong

#include "storeBin.h"
#include <sstream>
#include <ctype.h>

using namespace std;

int main(){

  storeBin table;
  string input;
  cin >> input;

  int get = stoi(input);
	
  table.power = table.findPower(get);
  //cout << table.power << endl; 
  int x = table.findPrime(get);
  //cout << x << endl;
  table.setSize(x);

  //table.insert("46.55.66.77");
  /*
  table.a.push_back(9);
  table.a.push_back(24);
  table.a.push_back(55);  
  table.a.push_back(9);
  table.a.push_back(20);
  table.a.push_back(58);
  */
  
  while(cin >> input){
    if(input == "insert"){
      cin >> input;
      table.insert(input);
    }
    else if(input == "delete"){
      cin >> input;
      table.delet(input);
    }
    else if(input == "lookup"){
      cin >> input;
      table.lookup(input);
    }
    else if(input == "stat"){
      cin >> input;
      table.stat();
    }
 }
	

	/*
	for(size_t i = 0; i < table.a.size(); i++){
		cout << table.a[i] << endl;
	}
	*/
	



	return 0;
}
