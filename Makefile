# `?=` means assigning the value to the variable if it is not already defined
ARMADILLO_INCLUDE ?= /home/yangjunjie/packages/armadillo-11.4.1/include
# EIGEN_INCLUDE     ?= /Users/yangjunjie/work/eigen-3.4.0/

# Set compiler
CXX      ?= g++
# Set c++ compiler flags
SO_FLAGS  ?= -shared -fPIC
OBJ_FLAGS ?= -c      -fPIC
CXXFLAGS  ?= -Wall -Werror -Wno-sign-compare -Wno-comment -std=c++11 -O3 -I $(ARMADILLO_INCLUDE)

# Run the tests
test: ./bin/utils.o ./bin/rhf.o 
	python ./test/test-h2o.py

./bin/rhf.o: ./src/rhf.cc
	$(CXX) $(CXXFLAGS) -o ./bin/rhf.o    $(OBJ_FLAGS) $^  
	$(CXX) $(CXXFLAGS) -o ./lib/rhf.so   $(SO_FLAGS)  $^  

./bin/utils.o: ./src/utils.cc
	$(CXX) $(CXXFLAGS) -o ./bin/utils.o  $(OBJ_FLAGS) $^
	$(CXX) $(CXXFLAGS) -o ./lib/utils.so $(SO_FLAGS)  $^

# Remove automatically generated files
clean :
	rm -rf ./bin/* ./lib/*
