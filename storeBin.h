//storeBin.h
//written by Yanwu Tong

#ifndef STOREBIN_H
#define STOREBIN_H

#include <iostream>
#include <string>
#include <vector>

class storeBin{
public:

  storeBin();
  int findPrime(int num);
  int findPower(int num);
  void setSize(int num);
  std::string dtob(int x);
  int hash(std::string address);
  void insert(std::string address);
  void delet(std::string address);
  void lookup(std::string address);
  int empty();
  int one();
  void stat();

  int power = 0;
  std::vector<int> a;

  int sucIns = 0;
  int sucDel = 0;
  size_t num = 0;
  size_t slot;
  size_t capacity;

  std::vector<std::vector<std::string>> table;
};




#endif
