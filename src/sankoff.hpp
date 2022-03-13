#include <iostream>
#include <vector>
#include <algorithm>
#include <tbb/parallel_for.h>
#include <string>

std::vector<int> join(std::vector<int> v1, std::vector<int> v2, std::vector<std::vector<int>> cost);
