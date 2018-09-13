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
    ::sort_subrange
        Intention/Description
            Sorts a range as if the entire collection was sorted.

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

namespace alg
{

/*********************************************************************************/

/*
    Implemented as seen from Sean Parent's talk
    Better Code: Data Structures
    https://youtu.be/sWgDk-o-6ZE?t=35m13s
*/

template <typename Itr> // Itr models RandomAccessIterator
void sort_subrange(Itr f, Itr l, Itr sf, Itr sl)
{
    if (sf == sl) return;
    if (sf != f)
    {
        std::nth_element(f, sf, l);
        ++sf;   // std::advance ?
    }
    std::partial_sort(sf, sl, l);
}

/*********************************************************************************/

}