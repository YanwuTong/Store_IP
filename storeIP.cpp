//storeIP.cpp
//written by Yanwu Tong

#include "storeIP.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

storeIP::storeIP() {}

int storeIP::findPrime(int num){
  if(num <= 2){
    return 2;
  }
  if(num % 2 ==0){
    num += 1;
  }
  for(int i = num; i <= 52488; i += 2){
    float temp = static_cast<float>(i);
    int mid = static_cast<int>(sqrt(temp));
    int j;
    for( j = 3; j <= mid; j += 2){
      if(i % j == 0){
  break;
      }
    }
    if(j > mid){
      return i;
    }
  }
  return 0;
}

void storeIP::setSize(int num){
  table.resize(num);
  capacity = num;
}


void storeIP::setCoe(){
  srand(time(NULL));
  a1 = rand() % (capacity - 1) + 1;
  a2 = rand() % (capacity - 1) + 1;
  a3 = rand() % (capacity - 1) + 1;
  a4 = rand() % (capacity - 1) + 1;
  return;
}


int storeIP::hash(std::string address){
  std::vector<std::string> result;
  boost::split(result, address, boost::is_any_of("."));
  /*
  for(size_t i = 0; i<result.size();i++){
    std::cout << result[i] << std::endl;
  }
  */
  int p1 = std::stoi(result[0]);
  int p2 = std::stoi(result[1]);
  int p3 = std::stoi(result[2]);
  int p4 = std::stoi(result[3]);
  int temp = p1 * a4 + p2 * a3 + p3 * a2 + p4 * a1;
  return temp % capacity;
}

void storeIP::insert(std::string address){
  int index = hash(address);
  for(size_t i = 0; i < table[index].size(); i++){
    if(table[index][i] == address){
      std::cout << "Error : could not insert " << address << " because it already exist." << std::endl;
      return;
    }
  }
  table[index].push_back(address);
  sucIns += 1;
  
  for(size_t i = 0; i < capacity; i++){
    if(num < table[i].size() || num == table[i].size()){
      num = table[i].size();
      slot = i;
    }
  }

  return;
}

void storeIP::delet(std::string address){
  int index = hash(address);
  for(size_t i = 0; i < table[index].size(); i++){
    if(table[index][i] == address){
      table[index].erase(table[index].begin()+i);
      sucDel +=1;
      return;
    }
  }
  std::cout << "Error : could not delete " << address << " becasue it does not exist." << std::endl;
  return;
}

void storeIP::lookup(std::string address){
  int index = hash(address);
  for(size_t i = 0; i < table[index].size(); i++){
    if(table[index][i] == address){
      std::cout << address + ": found." << std::endl;
      return;
    }
  }
  std::cout << address + ": not found." << std::endl;
  return;
}

int storeIP::empty(){
  int temp = 0;
  for(size_t i = 0; i < capacity; i++){
    if(table[i].size() == 0){
      temp += 1;
    }
  }
  return temp;
}

int storeIP::one(){
  int temp = 0;
  for(size_t i = 0; i < capacity; i++){
    if(table[i].size() == 1){
      temp += 1;
    }
  }
  return temp;
}

/*
void storeIP::col(){
  size_t temp = 0;
  int index = 0;
  for(size_t i = 0; i < capacity; i++){
    if(table[i].size() > temp){
      temp = table[i].size();
      index = i;
    }
  }
  std::cout << temp << " " << index << std::endl;
  return;
}
*/

void storeIP::stat(){
  std::string s;
  s = s + std::to_string(a1) + " " + std::to_string(a2) + " " +
    std::to_string(a3) + " " + std::to_string(a4) + "\n" +
    std::to_string(sucIns) + "\n" + 
    std::to_string(sucDel) + "\n";
  std::cout << s ;
  std::cout << empty() << std::endl;
  std::cout << one() << std::endl;
  //col();
  std::cout << num << " " << slot << std::endl;
  return;
}
