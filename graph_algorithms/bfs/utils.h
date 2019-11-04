#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <map>

template<typename T0, typename T1>
std::vector<T0> get_keys(const std::map<T0,T1> & m){
  std::vector<T0> result;
  typename std::map<T0,T1>::iterator it;
  for(auto const& e: m){
    result.push_back(e.first);
  }
  return result;
};

#endif
