#include <iostream>
#include <cstring>
#include <chrono>

void usage(char * call);

int main(int argc, char * argv[])
{
    if (argc != 3) usage(argv[0]);
    std::string test_str_a = argv[1];
    std::string test_str_b = argv[2];
    std::chrono::_V2::system_clock::time_point start;
    int time = 0;
    bool test = false;

    start = std::chrono::high_resolution_clock::now();
    if (test_str_a == test_str_b) test = true;
    time = std::chrono::duration<int, std::nano>(std::chrono::high_resolution_clock::now() - start).count();
    std::cout << "direct == string comp: " << std::boolalpha << test  << " in " << std::fixed << time << " nanosec" << std::endl;
    
    test = false;
    start = std::chrono::high_resolution_clock::now();
    if (!test_str_a.compare(test_str_b)) test = true;
    time = std::chrono::duration<int, std::nano>(std::chrono::high_resolution_clock::now() - start).count();
    std::cout << "string comp method: " << std::boolalpha << test  << " in " << std::fixed << time << " nanosec" << std::endl;
    
    test = false;
    start = std::chrono::high_resolution_clock::now();
    if (!strcmp(argv[1], argv[2])) test = true;
    time = std::chrono::duration<int, std::nano>(std::chrono::high_resolution_clock::now() - start).count();
    std::cout << "strcmp method: " << std::boolalpha << test  << " in " << std::fixed << time << " nanosec" << std::endl;
    
    test = false;
    int arglen = strlen(argv[2]);
    start = std::chrono::high_resolution_clock::now();
    if (!memcmp(argv[1], argv[2], arglen)) test = true;
    time = std::chrono::duration<int, std::nano>(std::chrono::high_resolution_clock::now() - start).count();
    std::cout << "memcmp method: " << std::boolalpha << test  << " in " << std::fixed << time << " nanosec" << std::endl;
    
    test = false;
    start = std::chrono::high_resolution_clock::now();
    if (*(argv[1] + arglen) == '\0' && !memcmp(argv[1], argv[2], arglen)) test = true;
    time = std::chrono::duration<int, std::nano>(std::chrono::high_resolution_clock::now() - start).count();
    std::cout << "length_and_memory_argcmp: " << std::boolalpha << test  << " in " << std::fixed << time << " nanosec" << std::endl;
    
    return 0;
}

void usage(char * call)
{
    std::cout << "USAGE:" << "\t" << call << " <string_a> <string_b>" << std::endl;
    exit(0);
}
