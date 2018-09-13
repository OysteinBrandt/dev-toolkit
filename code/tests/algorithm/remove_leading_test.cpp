#include "tests/test-api/catch.hpp"

#include "algorithm/remove_leading.hpp"

#include <string>
#include <map>

TEST_CASE("leading characters are removed", "[remove_leading]")
{
    std::string text{"   had leading whitespace"};
    alg::remove_leading(text, ' ');
    REQUIRE(text == "had leading whitespace");

    text = "aaabbb";
    alg::remove_leading(text, 'a');
    REQUIRE(text == "bbb");

    // TODO: consider wstring, unicode ?
}

TEST_CASE("leading integers are removed", "[remove_leading]")
{
    std::vector<int> numbers {3, 3, 3, 4, 5, 6};
    alg::remove_leading(numbers, 3);

    REQUIRE(numbers == std::vector<int>{4, 5, 6});
}

#if 0
TEST_CASE("remove_leading_if", "[remove_leading]")
{
    std::map<int, bool> data {
        {0, true},
        {1, true},
        {2, true},
        {3, false},
        {4, false}
    };

    const std::map<int, bool> expected {
        {3, false},
        {4, false}
    };

    auto flaggedForRemoval = [](int /*key*/, bool remove) -> bool { return remove; };
    alg::remove_leading_if(data, flaggedForRemoval);

    REQUIRE(data.size() == 2);
    REQUIRE(std::equal(data.begin(), data.end(), expected.begin(), expected.end()));

    for (const auto& e : data)
        REQUIRE_FALSE(e.second);
}
#endif
