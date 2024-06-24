CXX=clang++
CXXFLAGS=-std=c++20 -Werror -Wall
VALGRIND_FLAGS=--leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --error-exitcode=99
#LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

SOURCES=
DEMO_SOURCES=Demo.cpp
TESTSOURCES=TestCounter.cpp Test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
DEMO_OBJECTS=$(DEMO_SOURCES:.cpp=.o)
TESTOBJECTS=$(TESTSOURCES:.cpp=.o)

HEADERS= Node.hpp Tree.hpp TreeIterator.hpp 
TEMPLATES= Node.tpp Tree.tpp TreeIterator.tpp

demo: $(DEMO_OBJECTS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(DEMO_OBJECTS) $(OBJECTS) -o demo 

test: $(TESTOBJECTS) 
	$(CXX) $(CXXFLAGS) TestCounter.o -o test 

rundemo: demo
	 ./demo

runtests: test
	./test

tidy:
	clang-tidy $(SOURCES) $(DEMO_SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

demovalgrind: demo
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo | { egrep "==" || true; }


testvalgrind: test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "==" || true; }

clean:
	rm -f *.o demo test