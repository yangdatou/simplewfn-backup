# `?=` means assigning the value to the variable if it is not already defined
ARMADILLO_INCLUDE ?= /home/yangjunjie/packages/armadillo-11.4.1/include
# EIGEN_INCLUDE     ?= /Users/yangjunjie/work/eigen-3.4.0/

# Set compiler
CXX      ?= g++
# Set c++ compiler flags
SO_FLAGS  ?= -shared -o
OBJ_FLAGS ?= -fPIC -o
CXXFLAGS  ?= -Wall -Werror -Wno-sign-compare -Wno-comment -std=c++11 -O3 -I $(ARMADILLO_INCLUDE)

# Run the tests
test: ./lib/rhf.so 
	python ./test/test-h2o.py

./bin/rhf.o: ./src/rhf.cc
	$(CXX) $(CXXFLAGS) $(OBJ_FLAGS) ./bin/rhf.o -c $^

./lib/rhf.so: ./bin/rhf.o
	$(CXX) $(CXXFLAGS) $(SO_FLAGS) ./lib/rhf.so    $^

./bin/utils.o: ./bin/utils.o
	$(CXX) $(CXXFLAGS) $(OBJ_FLAGS) ./bin/utils.o -c $^

./lib/utils.so: ./src/utils.cc
	$(CXX) $(CXXFLAGS) $(SO_FLAGS) ./lib/utils.so    $^

# Remove automatically generated files
clean :
	rm -rf ./bin/* ./lib/*
