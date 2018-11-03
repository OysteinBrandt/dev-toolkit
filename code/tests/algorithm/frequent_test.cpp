#include "catch.hpp"

#include "algorithm/frequent.hpp"

#include <vector>
#include <algorithm>
#include <array>
#include <string>

/*****************************************************************************/

namespace details
{
  template <typename Iterator>
  struct is_const_iterator
  {
    using pointer = typename std::iterator_traits<Iterator>::pointer;
    static const bool value = std::is_const_v<typename std::remove_pointer<pointer>::type>;
  };

  template<class Iterator>
  constexpr bool is_const_iterator_v = is_const_iterator<Iterator>::value;
}

/*****************************************************************************/

template <typename Iterator>
bool is_const_iterator(Iterator)
{
  return details::is_const_iterator_v<Iterator>;
}

/*****************************************************************************/

TEST_CASE("most_frequent outputs the element that appears most", "[frequent]")
{
  std::vector<int> numbers { 1, 2, 3, 3, 4};
  std::sort(begin(numbers), end(numbers));

  // TODO: Replace REQUIRE with a custom matcher that checks for both directions
  REQUIRE(std::is_sorted(numbers.begin(), numbers.end()));  //  Can also be sorted from largest to smallest

  auto result = alg::most_frequent(numbers);
  REQUIRE(result != numbers.end());
  CHECK(*result == 3);
}

TEST_CASE("most_frequent outputs expected value", "[frequent]")
{
  SECTION("when input is empty")
  {
    const std::vector<int> empty;
    auto result = alg::most_frequent(empty);
    CHECK(result == empty.end());
    CHECK(result == empty.begin());
  }

  SECTION("with only one element")
  {
    const std::vector<int> one_elem { 3 };
    auto result = alg::most_frequent(one_elem);
    CHECK(*result == 3);
  }

  SECTION("when all elements appear once")
  {
    SECTION("in descending order")
    {
      std::vector<int> numbers{ 5, 4, 3, 2, 1 };

      // TODO: Replace REQUIRE with a custom matcher that checks for both directions
      REQUIRE(std::is_sorted(numbers.begin(), numbers.end(), std::greater<int>()));  //  Can also be sorted from smallest to largest

      auto result = alg::most_frequent(numbers);
      REQUIRE(result != numbers.end());
      CHECK(result == numbers.begin());
      CHECK(*result == 5);
    }

    SECTION("in ascending order")
    {
      std::vector<int> numbers{ 1, 2, 3, 4, 5 };

      // TODO: Replace REQUIRE with a custom matcher that checks for both directions
      REQUIRE(std::is_sorted(numbers.begin(), numbers.end()));  //  Can also be sorted from smallest to largest

      auto result = alg::most_frequent(numbers);
      REQUIRE(result != numbers.end());
      CHECK(result == numbers.begin());
      CHECK(*result == 1);
    }
  }

  SECTION("when all elements appear twice")
  {
    std::vector<int> numbers{ 1, 1, 2, 2, 3, 3, 4, 4 };

    // TODO: Replace REQUIRE with a custom matcher that checks for both directions
    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()));

    auto result = alg::most_frequent(numbers);
    REQUIRE(result != numbers.end());

    // Expect last element of "equal numbers" range to be returned
    CHECK(result == numbers.begin() + 1);
    CHECK(*result == 1);
    CHECK(std::distance(numbers.begin(), result) == 1);
  }
}

TEST_CASE("output can be used", "[frequent]")
{
  SECTION("in combination with STL algorithms")
  {
    std::vector<int> numbers{ 1, 3, 3, 5, 7, 7, 7 };
    std::sort(begin(numbers), end(numbers));

    // TODO: Replace REQUIRE with a custom matcher that checks for both directions
    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()));  //  Can also be sorted from largest to smallest

    auto most_frequent_number = alg::most_frequent(numbers);
    auto[begin, end] = std::equal_range(numbers.begin(), numbers.end(), *most_frequent_number);
    numbers.erase(begin, end);

    CHECK(numbers == std::vector<int>{1, 3, 3, 5});
  }

  SECTION("as const")
  {
    const std::vector<int> numbers{ 1, 3, 3, 5, 7, 7, 7 };

    // TODO: Replace REQUIRE with a custom matcher that checks for both directions
    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()));  //  Can also be sorted from largest to smallest

    auto most_frequent_number = alg::most_frequent(numbers);

    CHECK(is_const_iterator(most_frequent_number));
  }

  SECTION("as non-const")
  {
    std::vector<int> numbers{ 1, 2, 3, 3, 3, 4, 5 };

    // TODO: Replace REQUIRE with a custom matcher that checks for both directions
    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()));  //  Can also be sorted from largest to smallest

    auto most_frequent_number = alg::most_frequent(numbers);

    CHECK(!is_const_iterator(most_frequent_number));
  }
}

TEST_CASE("example on strings")
{
  SECTION("with sorting original collection")
  {
    std::array<std::string, 8> names{ "Bjarne", "Alexander", "Bjarne", "Herb", "Scott", "Bjarne", "Matt", "Fred" };
    std::sort(names.begin(), names.end());

    // TODO: Replace REQUIRE with a custom matcher that checks for both directions
    REQUIRE(std::is_sorted(names.begin(), names.end()));  //  Can also be sorted from largest to smallest

    auto most_frequent_name = alg::most_frequent(names);
    CHECK(std::string("Bjarne") == *most_frequent_name);
    CHECK(3 == std::distance(names.begin(), most_frequent_name)); // after sort; "Alexander", "Bjarne", "Bjarne", "Bjarne", ...
  }

#if 0 // TODO: see most_frequent => "Add parameter for using a predicate to compare elements"
  SECTION("without sort or copy of original collection")
  {
    std::array<std::string, 8> names{ "Bjarne", "Alexander", "Bjarne", "Herb", "Scott", "Bjarne", "Matt", "Fred" };

    std::vector<std::reference_wrapper<std::string>> ref_names(names.begin(), names.end()); // must be fixed size

    std::sort(ref_names.begin(), ref_names.end(),
      [](const std::string& s1, const std::string& s2) { return std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end()); });

    auto most_frequent_name = alg::most_frequent(ref_names/*, comp*/);
    CHECK(std::string("Bjarne") == (*most_frequent_name).get());

  }
#endif

}