CXX = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS =
OBJS = main.o stock.o transaction.o
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	@$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	@rm -f $(OBJS) $(TARGET)

test:
	@./$(TARGET)