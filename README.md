# StringCmp-Benchmark
Time comparation of several ways to compare strings

## How to test
```
git clone https://github.com/Samega7Cattac/StringCmp-Benchmark.git
cd StringCmp-Benchmark
make
./benchmark
```

## Result Examples

If the strings are equal: `./benchmark "This is a test String" "This is a test String"`
```
direct == string comp: true in 3732 nanosec
string comp methood: true in 1497 nanosec
strcmp method: true in 1540 nanosec
memcmp method: true in 304 nanosec
length_and_memory_argcmp: true in 224 nanosec
```

Strings are diff: `./benchmark "This is a test String1" "This is a test String2"`
```
direct == string comp: false in 3427 nanosec
string comp methood: false in 1450 nanosec
strcmp method: false in 956 nanosec
memcmp method: false in 186 nanosec
length_and_memory_argcmp: false in 169 nanosec
```

Strings are diff and with diff lengths: `./benchmark "This is a test String1" "This is a test String22"`
```
direct == string comp: false in 1684 nanosec
string comp methood: false in 1762 nanosec
strcmp method: false in 1558 nanosec
memcmp method: false in 1117 nanosec
length_and_memory_argcmp: false in 185 nanosec
```

`memcmp` and `lenght_and_memory_argcmp` have almost always the same timings, but `lenght_and_memory_argcmp` doesn't slow down when the lengths are diff.
