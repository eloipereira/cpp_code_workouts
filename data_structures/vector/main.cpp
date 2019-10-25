#include <iostream>
#include <cstdlib>
#include <vector>

// Implementation of vector<T>

template<class T>
class vector
{
public:
  // Put class variables here.
  T* elements;
  int n;  
    
  //void* malloc(size_t size_of_memory_in_bytes);
  //sizeof(T)
  //free(void* ptr)
    
  vector()
  {
     elements = (T*) malloc(0);
      n = 0;
    // Put constructor code here.
  }

  void push_back(const T& val)
  {
      T* tmp_elements;
      tmp_elements = (T*)malloc((n+1)*sizeof(T));
      
      
      for(int i = 0; i < n; i++){
          //std::cout << "pushed: " << elements[i] << std::endl;
          tmp_elements[i] = elements[i];
      }
      
      if(n == 0){
          
          tmp_elements[0] = val;
          n = n+1;
      } else {
        tmp_elements[n] = val;
          n = n + 1;
      }
      free(elements);
      elements = tmp_elements;
    // Put code here.
  }

 // Worst case: O(n)
 // Best case: O(1)
    // Average case:
   
  // 2 : 2 : +2 +1
  // 3 : 4 : +1
  // 4 : 4 : +4 +1
  // 5 : 8 : +1
  // 6 : 8 : +1
  // 7 : 8 : +1
  // 8 : 8 : +8 +1
  // O(?) = ((N +1) + N*1) / N    
   
    
  T& at(int index)
  {
      return elements[index];
    // Put code here.
  }

  size_t size()
  {
      return n;
    // Put code here.
  }
};

int main()
{
  vector<size_t> v;
  for (size_t i = 0; i < 100; i++)
  {
    
    v.push_back(i);
  }
  for (size_t i = 0; i < v.size(); i++)
  {
    std::cout << "v[" << i << "] = " << v.at(i) << std::endl;
  }
  return 0;
}
