#include <iostream>
#include <cstring>
#include <chrono>

#include "s7c_benchmark.hpp"

#define N_TIMES 100000000

void usage(char * call);

int main(int argc, char * argv[])
{
    if (argc != 3 && argc != 4) usage(argv[0]);
    unsigned int n_times = N_TIMES;
    if (argc == 4) n_times = atoi(argv[3]);
    std::string test_str_a = argv[1];
    std::string test_str_b = argv[2];
    
    Timer directT("direct == string comp", false);
    Timer stringT("string.compare", false);
    Timer strcmpT("strcmp", false);
    Timer memcmpT("memcmp", false);
    Timer lmemcmpT("length_and_memory_argcmp", false);
    
    bool res_direct = false;
    bool res_string = false;
    bool res_strcmp = false;
    bool res_memcpy = false;
    bool res_lmemcpy = false;
    
    for (unsigned int i = 0; i < n_times; ++i)
    {
        directT.start();
        if (test_str_a == test_str_b) res_direct = true;
        directT.stop();
        
        stringT.start();
        if (!test_str_a.compare(test_str_b)) res_string = true;
        stringT.stop();
        
        strcmpT.start();
        if (!strcmp(argv[1], argv[2])) res_strcmp = true;
        strcmpT.stop();
        
        int arglen = strlen(argv[2]);
        memcmpT.start();
        if (!memcmp(argv[1], argv[2], arglen)) res_memcpy = true;
        memcmpT.stop();
        
        lmemcmpT.start();
        if (*(argv[1] + arglen) == '\0' && !memcmp(argv[1], argv[2], arglen)) res_lmemcpy = true;
        lmemcmpT.stop();
    }
    std::cout << std::fixed << std::boolalpha;
    std::cout << "direct == comp: " << res_direct  << " in " << directT.get_sum() / n_times << " nanosec" << std::endl;
    std::cout << "string.compare: " << res_string  << " in " << stringT.get_sum() / n_times << " nanosec" << std::endl;
    std::cout << "strcmp: " << res_strcmp  << " in " << strcmpT.get_sum() / n_times << " nanosec" << std::endl;
    std::cout << "memcmp: " << res_memcpy  << " in " << memcmpT.get_sum() / n_times << " nanosec" << std::endl;
    std::cout << "length_and_memory_argcmp: " << res_lmemcpy  << " in " << lmemcmpT.get_sum() / n_times << " nanosec" << std::endl;
    
    return 0;
}

void usage(char * call)
{
    std::cout << "USAGE:" << "\t" << call << " <string_a> <string_b> [n_iterations]" << std::endl;
    exit(0);
}
