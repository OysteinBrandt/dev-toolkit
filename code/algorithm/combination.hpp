
/*
    ::combination_generator
        Intention/Description
            Generate all possible combinations of range [first,last) where the size of the combinations are 'n' and order does not matter.

        Prerequisite
        
        Parameters
            first -
            last -
            size - 

            Type requirements

        Return value

        Notes

        Complexity

        Exceptions
        
        Example

    TODO:
        - Add parameter for deciding direction of combined elements
            Invert bool check in if statement
                Ie.
                if (bitmask[i])

                VS
                if (!bitmask[i])

            Another possibility
                Ie.
                std::fill(v.end() - r, v.end(), true);
                while (std::next_permutation(v.begin(), v.end()));

                VS

                std::fill(v.begin(), v.begin() + r, true);
                while (std::prev_permutation(v.begin(), v.end()));
        - Find alternative name for combinations size variable
        - Hide implementation of combination_generator
        - Extend to support combinations AND permutations ?
          * see https://stattrek.com/online-calculator/combinations-permutations.aspx

        - need for ?
            //typedef typename std::iterator_traits<iterator_type>::value_type element_type;
        
    ALTERNATIVE NAMES:
        - combinate
        - combinations
        - make_combinator

*/

#include <vector>
#include <algorithm>

namespace obr
{

/*********************************************************************************/

template<class iterator_type>
class combination_generator
{
    iterator_type first, last;
    std::vector<bool> bitmask;
    size_t size;

public:
    explicit combination_generator(iterator_type first, iterator_type last, size_t size) 
        : first(first), last(last) , size(size)
    {
        bitmask.resize(std::distance(first, last), false);
        if (size > bitmask.size())
            throw std::out_of_range("Combination size is too large!");
        std::fill(bitmask.begin(), bitmask.begin() + size, true);
    }

    template<class output_iterator>
    bool operator()(output_iterator output) 
    {
        iterator_type element = first;
        for (size_t i = 0; i < bitmask.size(); ++i, ++element) 
        {
            if (bitmask[i])
                *output++ = *element;
        }
        return std::prev_permutation(bitmask.begin(), bitmask.end());
    }
};

/*********************************************************************************/

template<class iterator_type>
combination_generator<iterator_type> make_combination_generator(iterator_type first, iterator_type last, size_t size)
{
    return combination_generator<iterator_type>(first, last, size);
}

/*********************************************************************************/

template<typename Container>
combination_generator<typename Container::const_iterator> make_combination_generator(const Container& c, size_t size)
{
    return make_combination_generator<typename Container::const_iterator>(c.cbegin(), c.cend(), size);
}

/*********************************************************************************/

}