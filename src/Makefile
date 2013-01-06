SRC=.
BIN=../bin
OBJ=../obj
EXEC=StarSimulator

CXX=g++
CXX_FLAGS=-Wall -std=c++11 -I ../include -I . -fPIC
#LD_FLAGS=-lboost_filesystem -lboost_date_time -lboost_system -ldl

define cc-command
$(CC) -c $(CFLAGS) $< -o $@
endef

all: $(BIN)/$(EXEC)

Debug: all
Release: all

$(BIN)/$(EXEC): $(OBJ)/engine.o $(OBJ)/ship.o
	$(CXX) -shared -Wl,-soname,$(EXEC).so.1 -o $(BIN)/$(EXEC).so.1.0.1 $^
	ln -f -s $(BIN)/$(EXEC).so.1.0.1 $(BIN)/$(EXEC).so.1.0
	ln -f -s $(BIN)/$(EXEC).so.1.0.1 $(BIN)/$(EXEC).so.1
	ln -f -s $(BIN)/$(EXEC).so.1.0.1 $(BIN)/$(EXEC).so

$(OBJ)/engine.o : $(SRC)/engine.cpp $(SRC)/engine.hpp $(SRC)/utils/matrix.hpp $(SRC)/utils/plainstorage.hpp
	$(CXX) $(CXX_FLAGS) -c $(SRC)/engine.cpp -o $(OBJ)/engine.o

$(OBJ)/ship.o : $(SRC)/ship.cpp $(SRC)/ship.hpp $(SRC)/utils/matrix.hpp $(SRC)/utils/plainstorage.hpp
	$(CXX) $(CXX_FLAGS) -c $(SRC)/ship.cpp -o $(OBJ)/ship.o

