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

#include <cctype>
#include <string>
#include <algorithm>

namespace alg
{

/*********************************************************************************/

std::string to_upper(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::toupper(c); });
    return s;
}

/*********************************************************************************/

std::string& transform_to_upper(std::string& s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::toupper(c); });
    return s;
}

/*********************************************************************************/

std::string to_lower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); });
    return s;
}

/*********************************************************************************/

unsigned count_upper(const std::string& s)
{
    return std::count_if(s.begin(), s.end(), [](unsigned char c){ return std::isupper(c); });
}

/*********************************************************************************/

unsigned count_lower(const std::string& s)
{
    return std::count_if(s.begin(), s.end(), [](unsigned char c){ return std::islower(c); });
}

/*********************************************************************************/

//TODO(obr): Check if one of the strings is a prefix of the other one.(Unordered)
//           What the strings are used for should be explicit so that the caller can check for a certain prefix.
//           Consider using std::mismatch
bool is_prefix_of(const std::string& lhs, const std::string& rhs)
{
	return std::equal(
		lhs.begin(), 
		lhs.begin() + std::min(lhs.size(), rhs.size()),
		rhs.begin() );
}

/*********************************************************************************/

namespace details
{
	template <typename InputIt>
	std::string itr_to_str(InputIt itr)
	{
		if constexpr(std::is_same_v(
			typename std::iterator_traits<Collection::iterator>::value_type,
			std::string) )
		{
			return *itr;
		}
		else
		{
			std::ostringstream oss;
			oss << *itr;
			return oss.str();
		}
	}
}

/*********************************************************************************/

// Expects that the elements in Collection can be outputtet with << operator
template <typename Collection>
std::string join(const Collection &c, const std::string& delimiter = " ")
{
	if (c.empty()) return {};

	// If collection::type != std::string, call to_string ??
	// or just rely on << operator ?? (is this bad for performance?)
	// can we rely on classes having implemented a to_string free function?
	// See: https://www.fluentcpp.com/2017/06/06/using-tostring-custom-types-cpp/

	template <typename InputIt>
	//auto merger = [&delimiter](std::string result, const typename std::iterator_traits<InputIt>::reference element)
	auto merger = [&delimiter](std::string result, InputIt itr)
	{
		return std::move(result) + delimiter + details::itr_to_str(itr); // std::to_string(element);
	};

	return std::accumulate(
			std::next(c.cbegin()), c.cend(),
			//std::to_string(c[0]),
			details::itr_to_str(c.cbegin()),
			merger );
}

/*********************************************************************************/
}
