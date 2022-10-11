# `?=` means assigning the value to the variable if it is not already defined
ARMADILLO_INCLUDE ?= /home/yangjunjie/packages/armadillo-11.4.1/include
# EIGEN_INCLUDE     ?= /Users/yangjunjie/work/eigen-3.4.0/

# Set compiler
CXX      ?= g++
# Set c++ compiler flags
CXXFLAGS ?= -Wall -Werror -Wno-sign-compare -Wno-comment -std=c++11 -O3 -I $(ARMADILLO_INCLUDE)

# Run the tests
test: test
	python ./test/test-h2o.py

# Compile the main executable
main: ./src/rhf.cc
	$(CXX) $(CXXFLAGS) ./bin/rhf.dylib    

# Remove automatically generated files
clean :
	rm -rf ./bin/*
