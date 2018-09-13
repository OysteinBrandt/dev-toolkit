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

#include <iterator>

namespace alg
{

/*********************************************************************************/

template <typename Container, typename T>
void remove_trailing(Container &c, T val)
{
    c.erase(std::find_if(c.rbegin(), c.rend(), std::bind(std::not_equal_to<T>(), std::placeholders::_1, val)).base(), c.end());
}

/*********************************************************************************/

template <typename Container, typename Predicate>
void remove_trailing(Container &c, Predicate p)
{
    c.erase(std::find_if(c.rbegin(), c.rend(), std::not_fn(p)).base(), c.end());
}

/*********************************************************************************/

//template<typename ContainerA, typename ContainerB>
//void remove_trailing(ContainerA& c1, const ContainerB& c2)
//{
//}

/*********************************************************************************/

}

/*
remove_trailing_until

  template <class CHAR_TYPE, class F>
  inline void trimRight(std::basic_string<CHAR_TYPE, std::char_traits<CHAR_TYPE>, std::allocator<CHAR_TYPE>> &str, F functor)
  {
    str.erase(std::find_if(str.rbegin(), str.rend(), functor).base(), str.end());
  }
*/