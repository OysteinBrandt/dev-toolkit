#include "catch.hpp"

#include "algorithm/gather.hpp"

/*****************************************************************************/

struct TestElement
{
  unsigned id{ 0 };
  bool selected{ false };
};

TestElement unselected()
{
  static TestElement e{};
  ++e.id;
  return e;
}

/*****************************************************************************/

TEST_CASE("gather", "[gather]")
{
  std::vector<TestElement> collection(6);
  std::generate(collection.begin(), collection.end(), unselected);

  const auto is_selected = [] (const auto& e) { return e.selected; };
  const auto is_not_selected = std::not_fn(is_selected);

  collection[1].selected = true;
  collection[4].selected = true;

  const auto gatherPoint = collection.begin() + 3;
  const auto group = alg::gather(collection.begin(), collection.end(), gatherPoint, is_selected);

  CHECK(std::all_of(collection.begin(), group.first,      is_not_selected));
  CHECK(std::all_of(group.first,        group.second,     is_selected));
  CHECK(std::all_of(group.second,       collection.end(), is_not_selected));

  CHECK(2 == group.first->id);
  CHECK(5 == std::next(group.first)->id);
  CHECK(4 == group.second->id); // .end of selected range
}
