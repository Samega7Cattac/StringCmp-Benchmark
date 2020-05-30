OUTPUT = benchmark
OBJS = s7c_benchmark.o main.o

all: $(OBJS)
	$(CXX) $(OBJS) -o $(OUTPUT) $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

debug: CXXFLAGS += -g -fsanitize=address -Wall
debug: all

clean:
	rm -f *.o $(OUTPUT)
