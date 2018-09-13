
/*
    ::combination_generator
        Intention/Description
            Generate all possible combinations of range [first,last) where the size of the combinations are 'n' and order does not matter.

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
        #if 0   // Assert error or exception ?
        if (size > bitmask.size())
            throw std::out_of_range("Can not select more elements than exist for combination!");
        #endif
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
combination_generator<typename Container::iterator> make_combination_generator(Container& c, size_t size)
{
    return make_combination_generator<typename Container::iterator>(c.begin(), c.end(), size);
}

/*********************************************************************************/

}