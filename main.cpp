#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <climits>

int main() {
  std::ifstream infile("input.txt", std::ios::in);
  std::string line;
  std::stringstream ss; 
  int M, l=0;
  std::map<int, std::string> m;
  std::vector<int> v;
  while (std::getline(infile, line))
  {
      if(l==0 && line.length() !=0){
          ss<<line;
          std::string temp;
          while (!ss.eof()) {
          ss >> temp;
          if (std::stringstream(temp) >> M)
          temp = "";
        }
      }
      //std::cout << M << std::endl;

    if(l>=4){
          std::size_t ff=line.find(':');
          std::string item = line.substr(0, ff+1);
          std::string price = line.substr(ff+1, line.size()-item.size());
          std::stringstream sp(price);
          int x =0;
          sp >> x;
          //std::cout<<x<<std::endl;
          m.insert({ x, item });
          v.push_back(x);
        }
    l++;
    }
    sort(v.begin(), v.end());
    std::map<int, std::string>::iterator iter;
    int minDiff = INT_MAX; 
    int minIdx = 0;
      for(int i=0;i<v.size()-M+1;i++) {
      int diff = v[M+i-1] - v[i];

      if(diff<=minDiff) {
        minDiff = diff;
        minIdx = v[i];
      }
    }
    //std::cout<<minDiff<<std::endl;
    std::ofstream outfile ("output.txt");
    std::string str = "The goodies selected for distribution are:\n\n";
    outfile << str;
    auto itr = m.find(minIdx);
    for (int i=0; i<M; i++) {
        outfile << itr->second<<" " <<itr->first<<std::endl;
       // std::cout<<itr->second<<itr->first<<std::endl;
        itr++;
    }

    str="\nAnd the difference between the chosen goodie with highest price and the lowest price is ";

    outfile<<str<<minDiff;
  }
