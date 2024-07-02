CXX=clang++
CXXFLAGS=-std=c++20 -Werror -Wall
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
VALGRIND_FLAGS=--leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --error-exitcode=99

DEMO_SOURCES=Demo.cpp Complex.cpp
TESTSOURCES=TestCounter.cpp Test.cpp Complex.cpp 
DEMO_OBJECTS=$(DEMO_SOURCES:.cpp=.o)
TESTOBJECTS=$(TESTSOURCES:.cpp=.o)

HEADERS= Node.hpp Tree.hpp TreeIterator.hpp Complex.hpp
TEMPLATES= Node.tpp Tree.tpp TreeIterator.tpp

# demo: $(DEMO_OBJECTS) 
# 	$(CXX) $(CXXFLAGS) $(DEMO_OBJECTS)-o demo $(LDFLAGS)

# test: $(TESTOBJECTS) $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) $(TESTOBJECTS) $(OBJECTS) -o test $(LDFLAGS)

demo: $(DEMO_OBJECTS)
	$(CXX) $(CXXFLAGS) -o demo $(DEMO_OBJECTS) $(LDFLAGS) 

test: $(TESTOBJECTS) 
	$(CXX) $(CXXFLAGS) -o test $(TESTOBJECTS) 

rundemo: demo
	./demo

runtests: test
	./test

tidy:
	clang-tidy $(DEMO_SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

demovalgrind: demo
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo | { egrep "==" || true; }

testvalgrind: test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "==" || true; }

clean:
	rm -f *.o demo test
