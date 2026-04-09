#pragma once

namespace libftpp {
  namespace algo {
    
    class Algorithm {
      private:
      Algorithm();
      ~Algorithm();
      Algorithm(const Algorithm& other);
      Algorithm& operator=(const Algorithm& other);
      
      public:
      template <typename Iterator, typename T>
      static Iterator lower_bound(Iterator first, Iterator last, const T& val);
      
      template <typename Iterator, typename T, typename Compare>
      static Iterator lower_bound(Iterator first, Iterator last, const T& val, Compare comp);
      
      template <typename Iterator, typename Compare>
      static void merge(Iterator first, Iterator mid, Iterator last, Compare comp);
      
      template <typename Iterator, typename Compare>
      static void merge_sort(Iterator first, Iterator last, Compare comp);
      
      template <typename Iterator>
      static void merge_sort(Iterator first, Iterator last);
    };
    
  }
}
#include "Algorithm.tpp"