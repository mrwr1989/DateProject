CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = date_utility
OBJS = Date.o main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

Date.o: Date.cpp Date.h
	$(CXX) $(CXXFLAGS) -c Date.cpp

main.o: main.cpp Date.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
