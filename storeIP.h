//storeIP.h
//written by Yanwu Tong for cs130a

#ifndef STOREIP_H
#define STOREIP_H

#include <iostream>
#include <string>
#include <vector>


class storeIP {
public:
  /*
  int a1;
  int a2;
  int a3;
  int a4;
  */
  storeIP();
  int findPrime(int num);
  void setSize(int num);
  void setCoe();
  int hash(std::string address);
  void insert(std::string address);
  void delet(std::string address);
  void lookup(std::string address);
  int empty();
  int one();
  //void col();
  void stat();

private:

  int a1;
  int a2;
  int a3;
  int a4;
 
  int sucIns = 0;
  int sucDel = 0;
  size_t num = 0;
  size_t slot;
  size_t capacity;

  std::vector<std::vector<std::string>> table;


};

#endif
  
  
  
  
    
