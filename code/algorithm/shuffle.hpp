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
    ::shuffle
        Intention/Description
			Reorders the elements in the container such that each possible permutation of those elements has equal probability of appearance

        Prerequisite

        Parameters
			c - the container of elements to shuffle randomly

            Type requirements
				The container must support iterators that meet the requirements of `ValueSwappable` and `LegacyRandomAccessIterator`

        Return value
			None

        Notes

        Complexity
			O(N)

        Exceptions
        
        Example

    TODO:
        
    ALTERNATIVE NAMES:

*/

#include <random>
#include <algorithm>

namespace alg
{

/*********************************************************************************/

template <typename Container>
void shuffle(Container& c)
{
	//TODO(obr): Move random_device & mt19937 into a common location?
	
	std::random_device rd;
	std::mt19937 engine{ rd() };
	std::suffle(std::begin(c), std::end(c), engine);
}

/*********************************************************************************/

}
