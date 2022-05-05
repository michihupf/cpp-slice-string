CXX = g++ -std=c++17 -o slice_string
OBJ = slice_string.o

compile: $(OBJ)
	$(CXX) $(OBJ)

%.o: %.cpp
	$(CXX) -c $< -o $@
