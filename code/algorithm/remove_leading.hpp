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

#include <functional>

namespace alg
{

/*********************************************************************************/

template <typename Container, typename T>
void remove_leading(Container &c, T val)
{
    c.erase(c.begin(), std::find_if(c.begin(), c.end(), std::bind(std::not_equal_to<T>(), std::placeholders::_1, val)));
}

/*********************************************************************************/

template <typename Container, typename Predicate>
void remove_leading_if(Container &c, Predicate p)
{
    //c.erase(c.begin(), std::find_if(c.begin(), c.end(), std::not_fn(p)));
}

/*********************************************************************************/

//template<typename ContainerA, typename ContainerB>
//void remove_leading(ContainerA& c1, const ContainerB& c2)
//{
//  //typedef typename std::iterator_traits<iterator_type>::value_type element_type
//  c1.erase(c1.begin(), std::find_first_of(c.begin(), c.end(), c2.begin(), c2.end(), std::bind(std::not_equal_to<T>(), std::placeholders::_1, val)));
//}

/*********************************************************************************/

} // namespace alg

/*
remove_until

  template <class CHAR_TYPE, class F>
  inline void trimLeft(std::basic_string<CHAR_TYPE, std::char_traits<CHAR_TYPE>, std::allocator<CHAR_TYPE>> &str, F functor)
  {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), functor));
  }

*/