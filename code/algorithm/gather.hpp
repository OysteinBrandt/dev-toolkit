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
    ::name_of_algo
        Intention/Description
            

        Prerequisite

        Parameters
            first -
            last -

            Type requirements

        Return value

        Notes

        Complexity

        Exceptions
        
        Example

    TODO:
        
    ALTERNATIVE NAMES:

*/

#include <algorithm>
#include <functional>

namespace alg
{

  /*********************************************************************************/

  /*
      Implemented as seen from Sean Parent's talk
      GoingNative 2013 C++ Seasoning
      https://youtu.be/W2tWOdzgXHA
  */

  // Itr models BidirectionalIterator, Predicate models UnaryPredicate
  template <typename Itr, typename Predicate>
  auto gather(Itr first, Itr last, Itr loc, Predicate p) -> std::pair<Itr, Itr>
  {
    return { std::stable_partition(first, loc, std::not_fn(p)), 
             std::stable_partition(loc, last, p) };
  }

  /*********************************************************************************/

}
