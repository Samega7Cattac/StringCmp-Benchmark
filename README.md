# StringCmp-Benchmark
Time comparation of several ways to compare strings

## How to test
```
git clone https://github.com/Samega7Cattac/StringCmp-Benchmark.git
cd StringCmp-Benchmark
make
./benchmark
```

## Result Examples (default 100000000 iterations)

If the strings are equal: `./benchmark "This is a test String" "This is a test String"`
```
direct == comp: true in 40.808111 nanosec
string.compare: true in 34.426106 nanosec
strcmp: true in 34.294204 nanosec
memcmp: true in 31.675042 nanosec
length_and_memory_argcmp: true in 31.885689 nanosec
```

Strings are diff: `./benchmark "This is a test String1" "This is a test String2"`
```
direct == comp: false in 43.381544 nanosec
string.compare: false in 37.089940 nanosec
strcmp: false in 34.211088 nanosec
memcmp: false in 35.235334 nanosec
length_and_memory_argcmp: false in 35.579679 nanosec
```

Strings are diff and with diff lengths: `./benchmark "This is a test String1" "This is a test String22"`
```
direct == comp: false in 30.119650 nanosec
string.compare: false in 36.627149 nanosec
strcmp: false in 34.298820 nanosec
memcmp: false in 35.436222 nanosec
length_and_memory_argcmp: false in 27.794495 nanosec
```

`memcmp` and `lenght_and_memory_argcmp` have almost the same timings, but `lenght_and_memory_argcmp` is faster when the lengths are diff.
