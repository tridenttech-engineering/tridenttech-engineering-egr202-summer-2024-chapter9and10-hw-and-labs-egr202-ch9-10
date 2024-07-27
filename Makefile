all: lab9-2 hw9-19 lab10-2 hw10-13 test_lab9-2 test_hw9-19 test_lab10-2 test_hw10-13

CXX = clang++
CXXFLAGS = -std=c++14 -Wall -Werror


lab9-2: lab9-2.cpp
	$(CXX) $(CXXFLAGS) lab9-2.cpp -o lab9-2

hw9-19: hw9-19.cpp
	$(CXX) $(CXXFLAGS) hw9-19.cpp -o hw9-19

lab10-2: lab10-2.cpp
	$(CXX) $(CXXFLAGS) lab10-2.cpp -o lab10-2

hw10-13: hw10-13.cpp
	$(CXX) $(CXXFLAGS) hw10-13.cpp -o hw10-13

test_lab9-2: ./test_files/test_lab9-2.cpp
	$(CXX) $(CXXFLAGS) ./test_files/test_lab9-2.cpp -o ./test_files/test_lab9-2

test_hw9-19: ./test_files/test_hw9-19.cpp
	$(CXX) $(CXXFLAGS) ./test_files/test_hw9-19.cpp -o ./test_files/test_hw9-19

test_lab10-2: ./test_files/test_lab10-2.cpp
	$(CXX) $(CXXFLAGS) ./test_files/test_lab10-2.cpp -o ./test_files/test_lab10-2

test_hw10-13: ./test_files/test_hw10-13.cpp
	$(CXX) $(CXXFLAGS) ./test_files/test_hw10-13.cpp -o ./test_files/test_hw10-13

clean:
	rm -f lab9-2 hw9-19 lab10-2 hw10-13 ./test_files/test_lab9-2 ./test_files/test_hw9-19 ./test_files/test_lab10-2 ./test_files/test_hw10-13