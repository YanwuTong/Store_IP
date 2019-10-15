//storeBin.cpp
//written by Yanwu Tong

#include "storeBin.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <bitset>
#include <bits/stdc++.h>
#include <cmath>


storeBin::storeBin() {};

int storeBin::findPrime(int num){
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

int storeBin::findPower(int num){
  int temp = 0;
  if(num == 1){
    return 0;
  }
  if(num % 2 == 0){
    temp += 1;
  }
  return temp + findPower(num/2);
}

void storeBin::setSize(int num){
  table.resize(num);
  capacity = num;
  return;
}


std::string storeBin::dtob(int x){
  std::bitset<8> mybits(x);
  std::string temp = mybits.to_string<char,
  std::string::traits_type,std::string::allocator_type>();
  return temp;
}


int storeBin::hash(std::string address){
  std::vector<std::string> result;
  boost::split(result, address, boost::is_any_of("."));
  int p1 = std::stoi(result[0]);
  int p2 = std::stoi(result[1]);
  int p3 = std::stoi(result[2]);
  int p4 = std::stoi(result[3]);

  /*
  std::cout << p1 << std::endl;
  std::cout << p2 << std::endl;
  std::cout << p3 << std::endl;
  std::cout << p4 << std::endl;
  */
  
  std::string t1 = dtob(p1);
  std::string t2 = dtob(p2);
  std::string t3 = dtob(p3);
  std::string t4 = dtob(p4);
  std::string temp_address = "";
  temp_address = temp_address + t1 + t2 + t3 + t4;

  //std::cout << temp_address << std:: endl;

  int n = temp_address.length();
  char charadd[n+1];
  strcpy(charadd, temp_address.c_str());

  //std::cout << charadd << std::endl;

  int length = 32;
  int helper = 0;
  int final = 0;
  int tem;

  std::vector<int> x;

  
  int temp = length % power;
  if(temp != 0){
    tem = temp - 1;

    for(int i = 0; i < temp; i++){
      int num = (int)charadd[i] - 48;
      final += num * pow(2,tem);
      tem --;
    }

    x.push_back(final);
    final = 0;
    length -=temp;
  }


  while(length >= power){
    tem = power - 1;
    for(int i = temp + helper; i < temp + helper + power; i++){
      int num = (int)charadd[i] - 48;
      final += num * pow(2,tem);
      tem --;
    }
    x.push_back(final);
    final = 0;
    length -= power;
    helper += power;
  }

  /*
  int temp = length % power;
  if(temp != 0){
  	tem = length-1;
  	for(int i = helper; i < helper + temp; i++){
  		int num = (int)charadd[i] -48;
  		final += num * pow(2,tem);
  		tem--;
  	}
  	x.push_back(final);
  	final = 0;
  }
  */



  /*
  for(size_t i = 0; i < x.size(); i++){
    std::cout << x[i] << std::endl;
  }
  */
  
  
  if(a.size() < x.size()){
    srand(time(NULL));
    int random;
    for(size_t k = 0; k < x.size(); k++){
      random = rand() % (capacity - 1) + 1;
      a.push_back(random);
    }
  }
  

  /*
  for(size_t i = 0; i < a.size(); i++){
    std::cout << a[i] << std::endl;
  }
  */
  
  

  int sum = 0;
  for(size_t i = 0; i < x.size(); i++){
    sum += x[x.size()-i-1]*a[i];
  }


  return sum % capacity;
  
}

void storeBin::insert(std::string address){
  int index = hash(address);
  for(size_t i = 0; i < table[index].size(); i++){
    if(table[index][i] == address){
      std::cout << "Error : could insert address " << address << " because it already exists." << std::endl;
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


void storeBin::delet(std::string address){
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

void storeBin::lookup(std::string address){
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

int storeBin::empty(){
  int temp = 0;
  for(size_t i = 0; i < capacity; i++){
    if(table[i].size() == 0){
      temp += 1;
    }
  }
  return temp;
}

int storeBin::one(){
  int temp = 0;
  for(size_t i = 0; i < capacity; i++){
    if(table[i].size() == 1){
      temp += 1;
    }
  }
  return temp;
}

void storeBin::stat(){
  std::string s = "";
  for(size_t i = 0; i < a.size() - 1; i++){
    s = s + std::to_string(a[i]) + " ";
  }
  s = s + std::to_string(a[a.size()-1]);
  s += "\n";
  s = s + std::to_string(sucIns) + "\n" + std::to_string(sucDel) + "\n";
  std::cout << s ;

  std::cout << empty() << std::endl;
  std::cout << one() << std::endl;
  std::cout << num << " " << slot << std::endl;

  return;
}
