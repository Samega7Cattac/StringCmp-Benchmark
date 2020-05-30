#ifndef S7C_BECNHMARK_H
#define S7C_BECNHMARK_H

#include <string>
#include <vector>
#include <chrono>

class Timer
{
    std::string name;
    double sumT = 0.0;
    std::chrono::_V2::system_clock::time_point startT;
    bool running = false;
    
public:
    Timer(const std::string& name = "TIMER", bool enable = true);
    void start(bool do_reset = false);
    double tick();
    void stop();
    void reset();
    double get_sum();
    void print();
    void print_tick();
#ifdef TIMER_DEBUG
    void debug(std::string msg);
#endif
    ~Timer();
};

#endif
