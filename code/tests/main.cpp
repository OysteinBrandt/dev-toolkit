#define CATCH_CONFIG_MAIN
#include "test-api/catch.hpp"

# if 0  // All test cases reside in other .cpp files
#include "algorithm/remove_leading.hpp"
#include <string>

TEST_CASE("leading characters are removed", "[remove]")
{
    std::string text{"   had leading whitespace"};
    alg::remove_leading(text, ' ');
    REQUIRE(text == "had leading whitespace");

    text = "aaabbb";
    alg::remove_leading(text, 'a');
    REQUIRE(text == "bbb");

    // TODO: wstring, unicode ?
}

TEST_CASE("leading numbers are removed", "[remove]")
{
    std::vector<int> numbers {3, 3, 3, 4, 5, 6};
    alg::remove_leading(numbers, 3);

    REQUIRE(numbers == std::vector<int>{4, 5, 6});
}

TEST_CASE("remove_leading_if", "[remove]")
{
    // struct FlaggedForRemoval
    // {
    //     bool operator()(int /*key*/, bool flagged) const { return flagged; }
    // };

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

    //alg::remove_leading_if(data, [](int key, bool value) { return value; });
    auto flaggedForRemoval = [](int key, bool flagged) -> bool { return flagged; };
    alg::remove_leading_if(data, flaggedForRemoval);

    REQUIRE(data.size() == 2);
    REQUIRE(std::equal(data.begin(), data.end(), expected.begin(), expected.end()));

    for (const auto& e : data)
        REQUIRE_FALSE(e.second);
}
#endif