
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
                if (m_bitmask[i])

                VS
                if (!m_bitmask[i])

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
    iterator_type m_first;
    std::vector<bool> m_bitmask;

public:
    explicit combination_generator(iterator_type first, iterator_type last, size_t combination_size)
        : m_first(first)
    {
        m_bitmask.resize(std::distance(first, last), false);
        if (combination_size > m_bitmask.size())
            throw std::out_of_range("Combination size is too large!");
        std::fill(m_bitmask.begin(), m_bitmask.begin() + combination_size, true);
    }

    template<class output_iterator>
    bool operator()(output_iterator output) 
    {
        iterator_type element = m_first;
        for (auto bit : m_bitmask)
        {
          if (bit)
            *output++ = *element;
          ++element;
        }
        return std::prev_permutation(m_bitmask.begin(), m_bitmask.end());
    }
};

/*********************************************************************************/

template<class iterator_type>
combination_generator<iterator_type> make_combination_generator(iterator_type first, iterator_type last, size_t combination_size)
{
    return combination_generator<iterator_type>(first, last, combination_size);
}

/*********************************************************************************/

template<typename Container>
combination_generator<typename Container::const_iterator> make_combination_generator(const Container& c, size_t combination_size)
{
    return make_combination_generator<typename Container::const_iterator>(c.cbegin(), c.cend(), combination_size);
}

/*********************************************************************************/

}