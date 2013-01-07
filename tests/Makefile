#dirs
DIR_SRC=../src
DIR_OBJ=../obj
DIR_TESTS=tests
DIR_BIN=../bin

CC=g++
CFLAGS_TEST= -std=gnu++0x -Wall -I include -ID:\prog\cppunit-1.12.1\include
LDFLAGS_TEST= -LD:\prog\cppunit-1.12.1\lib -lcppunit
EXEC=tests

all: $(DIR_BIN)/$(EXEC)

Debug: all
Release: all

	
clean:
	rm $(DIR_OBJ)/$(DIR_TESTS)/*.o

#cppunits

$(DIR_BIN)/$(EXEC): $(DIR_OBJ)/$(DIR_TESTS)/main.o $(DIR_OBJ)/$(DIR_TESTS)/matrix_ut.o 
	$(CC) -o $(DIR_BIN)/$(EXEC) $(LDFLAGS_TEST) $(DIR_OBJ)/$(DIR_TESTS)/main.o $(DIR_OBJ)/$(DIR_TESTS)/matrix_ut.o 

$(DIR_OBJ)/$(DIR_TESTS)/main.o: main.cpp matrix_ut.hpp
	$(CC) -c main.cpp -o $(DIR_OBJ)/$(DIR_TESTS)/main.o $(CFLAGS_TEST)
	
$(DIR_OBJ)/$(DIR_TESTS)/matrix_ut.o : matrix_ut.cpp matrix_ut.hpp $(DIR_SRC)/utils/matrix.hpp $(DIR_SRC)/utils/plainstorage.hpp
	$(CC) -c matrix_ut.cpp -o $(DIR_OBJ)/$(DIR_TESTS)/matrix_ut.o $(CFLAGS_TEST)
