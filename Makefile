# `?=` means assigning the value to the variable if it is not already defined
ARMADILLO_INCLUDE ?= /home/yangjunjie/packages/armadillo-11.4.1/include
# EIGEN_INCLUDE     ?= /Users/yangjunjie/work/eigen-3.4.0/

# Set compiler
CXX      ?= g++
# Set c++ compiler flags
SO_FLAGS  ?= -shared -fPIC
OBJ_FLAGS ?= -fPIC
CXXFLAGS  ?= -Wall -Werror -Wno-sign-compare -Wno-comment -std=c++11 -O3 -I $(ARMADILLO_INCLUDE)

# Run the tests
test: ./bin/rhf.o ./bin/utils.o
	python ./test/test-h2o.py

./bin/rhf.o: ./src/rhf.cc ./bin/utils.o
	$(CXX) $(CXXFLAGS) $(OBJ_FLAGS) $^  -o ./bin/rhf.o  
	$(CXX) $(CXXFLAGS) $(SO_FLAGS)  $^  -o ./lib/rhf.so 

./bin/utils.o: ./src/utils.cc
	$(CXX) $(CXXFLAGS) $(OBJ_FLAGS) $^  -o ./bin/utils.o 
	$(CXX) $(CXXFLAGS) $(SO_FLAGS)  $^  -o ./lib/utils.so

# Remove automatically generated files
clean :
	rm -rf ./bin/* ./lib/*
