/*
    MIT License

    Copyright (c) 2018 Øystein Brandt

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

/*
    ::most_frequent
        Intention/Description
            Find element that appears most frequently in the range [first, last)

        Prerequisite
            A sorted collection, either direction.
              Equivalent elements must appear next to each other.

        Parameters
            first -
            last -

        Type requirements
          Itr must meed the requirements of ForwardIterator

        Return value
            X_Iterator to found element
              end() if the range is empty
              first() if all elements appear equal amount of times

        Notes

        Complexity
            Linear?

        Exceptions
        
        Example
            #include <vector>
            #include <iostream>
            #include <algorithm>

            std::vector<int> numbers = {1, 2, 3, 3};
            std::sort(begin(numbers), end(numbers));

            auto r = most_frequent(numbers);
            std::cout << "the most frequent number is " << *r << "\n";

    TODO:
        - Return pair of most_frequent and number of occurrences
        - Add function for least_frequent
        - Add parameter for using a predicate to compare elements
        - Check edge cases, (e.g. if empty, all occur once)
        - Indicate type of iterator in template (ForwardIt, InputIt, etc.)
        - Support const iterators
        - Support const collection
        
    ALTERNATIVE NAMES:
        - repeated ++
        - recurring +
        - most_common
        - repetitive --
*/

#include <iterator>

namespace alg
{

  /*********************************************************************************/

  template <typename Itr>
  Itr most_frequent(Itr first, Itr last) noexcept
  {
    static_assert(std::is_base_of_v<std::forward_iterator_tag, typename std::iterator_traits<Itr>::iterator_category>, "most_frequent requires forward iterator");
    auto most_freq = first;
    unsigned largest_frequency{ 0 };

    while (first != last)
    {
      unsigned frequency{ 1 };
      Itr trailer = first;
      ++first;

      for (; first != last && *first == *trailer; ++first, ++trailer, ++frequency) {}

      if (frequency > largest_frequency)
      {
        largest_frequency = frequency;
        most_freq = trailer;
      }
    }

    return most_freq;
  }

  /*********************************************************************************/

  template <typename Collection>
  typename Collection::const_iterator most_frequent(const Collection &c) noexcept
  {
    return most_frequent(c.cbegin(), c.cend());
  }

  /*********************************************************************************/

  template <typename Collection>
  typename Collection::iterator most_frequent(Collection &c) noexcept
  {
    return most_frequent(c.begin(), c.end());
  }

  /*********************************************************************************/

}

#if 0 // Alternative solution that turns out to be slightly faster on arrays in O3, but is approx. 2x slower in debug
template <typename Itr>
Itr most_frequent(Itr first, Itr last) noexcept
{
  static_assert(std::is_base_of_v<std::forward_iterator_tag, typename std::iterator_traits<Itr>::iterator_category>, "most_frequent requires forward iterator");
  auto most_freq = first;
  unsigned largest_frequency{ 0 };

  for (; first != last; ++first)
  {
    unsigned frequency{ 1 };
    while (std::next(first) != last && *std::next(first) == *first)
    {
      ++frequency;
      std::advance(first, 1);
    }

    if (frequency > largest_frequency)
    {
      largest_frequency = frequency;
      most_freq = first;
    }
  }

  return most_freq;
}
#endif
