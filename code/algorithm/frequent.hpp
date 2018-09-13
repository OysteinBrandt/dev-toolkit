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
            A sorted collection

        Parameters
            first -
            last -

            Type requirements

        Return value
            X_Iterator to found element

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
        - Add parameter for using a predicate to compare elements
        - Check edge cases, (e.g. if empty, all occur once)
        - Indicate type of iterator in template (ForwardIt, InputIt, etc.)
        - Support const iterators
        - Support const collection
        
    ALTERNATIVE NAMES:
        - repeated ++
        - recurring +
        - common
        - repetitive --
*/

#include <iterator>

namespace alg
{

/*********************************************************************************/

template <typename Itr>
Itr most_frequent(Itr first, Itr last)
{
    auto most_freq = first;
    unsigned largest_occurence{0};

    for (; first != last; ++first)
    {
        unsigned occurence{1};
        while (std::next(first) != last && *std::next(first) == *first)
        {
            ++occurence;
            std::advance(first, 1);
        }

        if (occurence > largest_occurence)
        {
            largest_occurence = occurence;
            most_freq = first;
        }
    }

    return most_freq;
}

/*********************************************************************************/

template <typename Collection>
typename Collection::iterator most_frequent(Collection &c)
{
    return most_frequent(c.begin(), c.end());
}

/*********************************************************************************/

}