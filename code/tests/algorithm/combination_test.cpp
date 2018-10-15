#include "catch.hpp"

#include "algorithm/combination.hpp"

#include <vector>
#include <sstream>
#include <iterator>

/*****************************************************************************/

void test_combination(
  size_t combine_size, 
  const std::vector<std::string>& input, 
  const std::vector<std::string>& expected_result
)
{
  auto generator = obr::make_combination_generator(input, combine_size);
  std::stringstream ss;
  std::ostream_iterator<std::string> output(ss, "");

  while (generator(output))
    ss << "|";

  REQUIRE(ss.good());

  std::string combination;
  for (const auto& expected : expected_result)
  {
    std::getline(ss, combination, '|');
    CHECK(combination == expected);
  }

  CHECK_FALSE((ss >> combination));
}

/*****************************************************************************/

TEST_CASE("Combination generator outputs expected combinations", "[combination]")
{
  const std::vector<std::string> letters{ "A", "B", "C" };

  SECTION("when combination size is 0")
  {
    const std::vector<std::string> expected{ "" };
    test_combination(0, letters, expected);
  }

  SECTION("when combination size is 1")
  {
    const std::vector<std::string> expected{ "A", "B", "C" };
    test_combination(1, letters, expected);
  }

  SECTION("when combination size is between limits")
  {
    const std::vector<std::string> expected{ "AB", "AC", "BC" };
    const size_t combination_size{ 2 };

    // TODO: Replace REQUIRE with a custom matcher
    // see: https://github.com/catchorg/Catch2/blob/master/docs/matchers.md#top
    REQUIRE(combination_size > 0);
    REQUIRE(combination_size < letters.size());
    test_combination(combination_size, letters, expected);
  }

  SECTION("when combination size is equal container size")
  {
    const std::vector<std::string> expected{ "ABC" };
    test_combination(letters.size(), letters, expected);
  }

  SECTION("on larger input")
  {
    const std::vector<std::string> large_data{"A", "B", "C", "D", "E", "F"};
    const std::vector<std::string> expected
    {
      "ABCD", "ABCE", "ABCF", "ABDE", "ABDF", "ABEF", "ACDE", "ACDF", 
      "ACEF", "ADEF", "BCDE", "BCDF", "BCEF", "BDEF", "CDEF"
    };

    test_combination(4, large_data, expected);
  }

  SECTION("when input is empty")
  {
    const std::vector<std::string> expected{ "" };
    test_combination(0, {}, expected);
  }
}

/*****************************************************************************/

TEST_CASE("Combination generator reacts as expected on invalid input", "[combination]")
{
  SECTION("when combination size is larger than elements in provided container")
  {
    const std::vector<std::string> letters{ "A", "B", "C" };
    const size_t combination_size{ 5 };

    REQUIRE(combination_size > letters.size());
    REQUIRE_THROWS_AS(test_combination(combination_size, letters, {}), std::out_of_range);
  }
}

/*****************************************************************************/
