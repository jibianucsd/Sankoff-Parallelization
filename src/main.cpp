#include <iostream>
#include <vector>
#include <boost/program_options.hpp>
#include <tbb/task_scheduler_init.h>
#include "timer.hpp"
#include "sankoff.hpp"
// #include "kseq.h"
#include "zlib.h"
#include <ctime>
#include <cstdlib>

int main(int argc, char** argv) {
    Timer timer;
    fprintf(stdout, "Sankoff\n");

    int inf = 10000;

    fprintf(stdout, "Start making 2D array\n");
    
    std::vector<std::vector<int>> cost
    {
        {0,4,2,4},
        {4,0,4,2},
        {2,4,0,4},
        {4,2,4,0}
    };
    
    std::vector<int> a = {0, inf, inf, inf};
    std::vector<int> c = {inf, 0, inf, inf};
    std::vector<int> g = {inf, inf, 0, inf};
    std::vector<int> t = {inf, inf, inf, 0};

    timer.Start();
    std::vector<int> n1 = join(a,c,cost);

    for(int i = 0; i < n1.size(); i++)
        std::cout << n1[i] << ' ';
    fprintf(stdout, "\nCompleted Sankoff in %ld msec \n\n", timer.Stop());    
    return 0;
}