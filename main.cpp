#include <iostream>
#include <cstring>
#include <chrono>

#include "s7c_benchmark.hpp"

void usage(char * call);

int main(int argc, char * argv[])
{
    if (argc != 3) usage(argv[0]);
    std::string test_str_a = argv[1];
    std::string test_str_b = argv[2];
    bool test = false;
    
    Timer timer;
    if (test_str_a == test_str_b) test = true;
    timer.stop();
    std::cout << "direct == string comp: " << std::boolalpha << test  << " in " << std::fixed << timer.get_sum() << " nanosec" << std::endl;
    
    test = false;
    timer.start(true);
    if (!test_str_a.compare(test_str_b)) test = true;
    timer.stop();
    std::cout << "string comp method: " << std::boolalpha << test  << " in " << std::fixed << timer.get_sum() << " nanosec" << std::endl;
    
    test = false;
    timer.start(true);
    if (!strcmp(argv[1], argv[2])) test = true;
    timer.stop();
    std::cout << "strcmp method: " << std::boolalpha << test  << " in " << std::fixed << timer.get_sum() << " nanosec" << std::endl;
    
    test = false;
    int arglen = strlen(argv[2]);
    timer.start(true);
    if (!memcmp(argv[1], argv[2], arglen)) test = true;
    timer.stop();
    std::cout << "memcmp method: " << std::boolalpha << test  << " in " << std::fixed << timer.get_sum() << " nanosec" << std::endl;
    
    test = false;
    timer.start(true);
    if (*(argv[1] + arglen) == '\0' && !memcmp(argv[1], argv[2], arglen)) test = true;
    timer.stop();
    std::cout << "length_and_memory_argcmp: " << std::boolalpha << test  << " in " << std::fixed << timer.get_sum() << " nanosec" << std::endl;
    
    return 0;
}

void usage(char * call)
{
    std::cout << "USAGE:" << "\t" << call << " <string_a> <string_b>" << std::endl;
    exit(0);
}
