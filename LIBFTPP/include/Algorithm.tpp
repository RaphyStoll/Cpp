#pragma once
#include <iterator>
#include <vector>
#include "Algorithm.hpp"

namespace libftpp {
namespace algo {

template <typename Iterator, typename T>
Iterator Algorithm::lower_bound(Iterator first, Iterator last, const T& val) {
  typename std::iterator_traits<Iterator>::difference_type count = std::distance(first, last);
  typename std::iterator_traits<Iterator>::difference_type step;
  Iterator it;

  while (count > 0) {
    it = first;
    step = count / 2;
    std::advance(it, step);

    if (*it < val) {
      first = ++it;
      count -= step + 1;
    } else {
      count = step;
    }
  }
  return first;
}

template <typename Iterator, typename T, typename Compare>
Iterator Algorithm::lower_bound(Iterator first, Iterator last, const T& val, Compare comp) {
  typename std::iterator_traits<Iterator>::difference_type count = std::distance(first, last);
  typename std::iterator_traits<Iterator>::difference_type step;
  Iterator it;

  while (count > 0) {
    it = first;
    step = count / 2;
    std::advance(it, step);

    if (comp(*it, val)) {
      first = ++it;
      count -= step + 1;
    } else {
      count = step;
    }
  }
  return first;
}

template <typename Iterator, typename Compare>
void Algorithm::merge(Iterator first, Iterator mid, Iterator last, Compare comp) {
  typedef typename std::iterator_traits<Iterator>::value_type value_type;
  std::vector<value_type> temp;
  
  Iterator i = first;
  Iterator j = mid;
  
  while (i != mid && j != last) {
    if (comp(*i, *j) || (!comp(*j, *i) && !comp(*i, *j))) {
      temp.push_back(*i);
      ++i;
    } else {
      temp.push_back(*j);
      ++j;
    }
  }
  
  while (i != mid) {
    temp.push_back(*i);
    ++i;
  }
  while (j != last) {
    temp.push_back(*j);
    ++j;
  }
  
  Iterator it = first;
  for (size_t k = 0; k < temp.size(); ++k) {
    *it = temp[k];
    ++it;
  }
}

template <typename Iterator, typename Compare>
void Algorithm::merge_sort(Iterator first, Iterator last, Compare comp) {
  typename std::iterator_traits<Iterator>::difference_type dist = std::distance(first, last);
  if (dist < 2)
    return;
    
  Iterator mid = first;
  std::advance(mid, dist / 2);
  
  merge_sort(first, mid, comp);
  merge_sort(mid, last, comp);
  
  merge(first, mid, last, comp);
}

// Surchage sans comparator 
template <typename Iterator>
void Algorithm::merge_sort(Iterator first, Iterator last) {
  typedef typename std::iterator_traits<Iterator>::value_type value_type;
  struct Less {
    bool operator()(const value_type& a, const value_type& b) const {
      return a < b;
    }
  } comp;
  merge_sort(first, last, comp);
}

}
}