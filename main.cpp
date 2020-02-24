#include <iostream>
#include <cstring>
// #include <random>
#include <chrono>

/*#define N_TIMES 1000000
#define GEN_STRING_LEGHT 1024*/


void usage(char * call);

void lenght_and_memory_argcmp(char * a, const char * b, int arglen);

int main(int argc, char * argv[])
{
    if (argc != 3) usage(argv[0]);
    std::string test_str_a = argv[1];
    std::string test_str_b = argv[2];
    std::chrono::_V2::system_clock::time_point start;
    int time = 0;
    
    start = std::chrono::high_resolution_clock::now();
    if (argv[1] == argv[2])
        ;
    time = std::chrono::duration<int, std::nano>(std::chrono::high_resolution_clock::now() - start).count();
    std::cout << "direct == comp: " << std::fixed << time << " nanosec" << std::endl;
    
    start = std::chrono::high_resolution_clock::now();
    if (test_str_a == test_str_b)
        ;
    time = std::chrono::duration<int, std::nano>(std::chrono::high_resolution_clock::now() - start).count();
    std::cout << "direct == string comp: " << std::fixed << time << " nanosec" << std::endl;
    
    start = std::chrono::high_resolution_clock::now();
    test_str_a.compare(test_str_b);
    time = std::chrono::duration<int, std::nano>(std::chrono::high_resolution_clock::now() - start).count();
    std::cout << "string comp methood: " << std::fixed << time << " nanosec" << std::endl;
    
    start = std::chrono::high_resolution_clock::now();
    if (!strcmp(argv[1], argv[2]))
        ;
    time = std::chrono::duration<int, std::nano>(std::chrono::high_resolution_clock::now() - start).count();
    std::cout << "strcmp method: " << std::fixed << time << " nanosec" << std::endl;
    
    int arglen = strlen(argv[2]);
    start = std::chrono::high_resolution_clock::now();
    if (!memcmp(argv[1], argv[2], arglen))
        ;
    time = std::chrono::duration<int, std::nano>(std::chrono::high_resolution_clock::now() - start).count();
    std::cout << "memcmp method: " << std::fixed << time << " nanosec" << std::endl;
    
    start = std::chrono::high_resolution_clock::now();
    if (*(argv[1] + arglen) == '\0' && !memcmp(argv[1], argv[2], arglen))
        ;
    time = std::chrono::duration<int, std::nano>(std::chrono::high_resolution_clock::now() - start).count();
    std::cout << "lenght_and_memory_argcmp: " << std::fixed << time << " nanosec" << std::endl;
    
    return 0;
}



void usage(char * call)
{
    std::cout << "USAGE:" << "\t" << call << " <string_a> <string_b>" << std::endl;
    exit(0);
}
