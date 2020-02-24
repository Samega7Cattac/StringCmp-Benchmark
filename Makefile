OUTPUT=benchmark

all:
	$(CXX) main.cpp -o ./$(OUTPUT) $(CXXFLASGS)

debug: CXXFLAGS += -g
debug: all

clean:
	rm ./$(OUTPUT)
