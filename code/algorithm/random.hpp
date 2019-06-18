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
       -  
    ALTERNATIVE NAMES:

*/

#include <random>

namespace alg
{

/*********************************************************************************/

struct Rng
{
	template<typename T>
	explicit Rng(T lowest, T highest) : lowest_(lowest), highest_(highest)
	{}

	template<typename T>
	T operator()() const
	{
		static std::random_device rd;  // Used to obtain a seed
		static std::mt19937 engine{ rd() };
		if constexpr (std::is_floating_point_v<T>)
		{
			static std::uniform_real_distribution<T> distribution(lowest_, highest_);
			return distribution(engine);
		}
		else
		{
			static std::uniform_int_distribution<T> distribution(lowest_, highest_);
			return distribution(engine);
		}
	}

private:
	const T lowest_;
	const T highest_;
};

/*********************************************************************************/

}

