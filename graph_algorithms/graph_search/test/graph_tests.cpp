#include "graph.h"
#include "graph_search.h"
#include <gtest/gtest.h>
#include <vector>

TEST(BFSTest, graph0)
{
  Graph<int> graph0;
  graph0.add_edge(0,1);
  graph0.add_edge(0,2);
  graph0.add_edge(1,10);
  graph0.add_edge(1,11);
  graph0.add_edge(2,20);
  graph0.add_edge(2,21);

  auto result = bfs(graph0,0, true);
  ASSERT_EQ(result.order_visited,std::vector<int>({0,1,2,10,11,20,21}));
}

TEST(DFSTest, graph0)
{
  Graph<int> graph0;
  graph0.add_edge(0,1);
  graph0.add_edge(0,2);
  graph0.add_edge(1,10);
  graph0.add_edge(1,11);
  graph0.add_edge(2,20);
  graph0.add_edge(2,21);

  auto result = dfs(graph0,0, true);
  ASSERT_EQ(result.order_visited,std::vector<int>({0,2,21,20,1,11,10}));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
