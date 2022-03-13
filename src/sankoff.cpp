#include "sankoff.hpp"

std::vector<int> join(std::vector<int> v1, std::vector<int> v2, std::vector<std::vector<int>> cost){
    int inf = 10000;
    int cost_size = cost.size();
    
    // Init a thi list
    std::vector<int> thi;
    for (int i=0; i<cost_size; i++) thi.push_back(0);
    tbb::parallel_for(tbb::blocked_range<size_t>(0, cost_size), [&](tbb::blocked_range<size_t> r) {
        for (auto i=r.begin(); i<r.end(); i++) {
            int min_left = inf;
            int min_right = inf;
            for (int j=0; j<cost_size; j++) {
                int this_cost = cost[i][j] + v1[j];
                int this_cost1 = cost[i][j] + v2[j];
                min_left = std::min(min_left, this_cost);
                min_right = std::min(min_right, this_cost1);
            }
            thi[i] = min_left + min_right;
        }
    });
    return thi;
}