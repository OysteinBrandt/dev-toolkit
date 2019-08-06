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
    ::has_consecutive_value
        Intention/Description
           Searches a container for the first sequence of count identical items, each equal to `value`.

        Prerequisite

        Parameters
			c		- the container of elements to examine
			count	- the length of the sequence to search for
			value	- the value of the elements to search for

            Type requirements
				- The container must support forward iterators

        Return value
			Boolean value that returns `true` if the sequence is found, otherwise returns `false`

        Notes

        Complexity
			O(N)

        Exceptions
        
        Example
		```cpp
		#include <iostream>
		#include <algorithm>
		#include <iterator>
		
		int main()
		{
		   const char sequence[] = "1001010100010101001010101";
		
		   std::cout << std::boolalpha;
		   std::cout << "Has 4 consecutive zeros: "
		             << has_consecutive_values(sequence,4,'0') << '\n';
		   std::cout << "Has 3 consecutive zeros: "
		             << has_consecutive_values(sequence,3,'0') << '\n';
		}
		```
		Output
		```cpp
		Has 4 consecutive zeros: false
		Has 3 consecutive zeros: true
		```

    TODO:
        
    ALTERNATIVE NAMES:

*/

#include <algorithm>

namespace alg
{

/*********************************************************************************/

template <typename Container, typename Size, typename T>
bool has_consecutive_values(cont Container& c, Size count, const T& value)
{
	return std::search_n(std::begin(c), std::end(c), count, value) != std::end(c);
}

/*********************************************************************************/

}
