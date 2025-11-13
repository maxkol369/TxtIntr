CXX = g++

DEBUG_FLAGS = -g -O0
RELEASE_FLAGS = -O2
WARNING_FLAGS = -Wall -Wextra


TARGET = calculator
DEBUG_TARGET = calculator-dbg


all: $(TARGET)


$(DEBUG_TARGET): calculator.cpp
	$(CXX) $(DEBUG_FLAGS) calculator.cpp -o $(DEBUG_TARGET) $(WARNING_FLAGS)


$(TARGET): calculator.cpp
	$(CXX) $(RELEASE_FLAGS) calculator.cpp -o $(TARGET) -DNDEBUG $(WARNING_FLAGS)


clean:
	rm -f $(TARGET) $(DEBUG_TARGET)


test: $(TARGET)
	./$(TARGET) -o summa 5 3 2
	./$(TARGET) -operation subtract 10 3 2
	./$(TARGET) -o summa 1 2 3 4
	./$(TARGET) -operation subtract 20 5 3

.PHONY: all clean test
