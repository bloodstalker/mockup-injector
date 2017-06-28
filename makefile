
CXX?=clang++
CXX_FLAGS=-std=c++11
LD_FLAGS=

TARGET=syscallinjecter

.PHONY: all,clean,TARGET,help

.DEFAULT: all

all:$(TARGET)

.cpp.o:
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(TARGET): $(TARGET).o
	$(CXX) $^ $(LD_FLAGS) -o $@

clean:
	rm -f *.o *~ $(TARGET)
	rm ./strace-log

help:
	@echo 'all builds the executable. its also the default target.'
	@echo 'press tab for a list of options if you have zsh.'

