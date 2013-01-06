CHK_DIR_EXISTS= test -d
MKDIR= mkdir -p
DIR= $(dir $(lastword $(MAKEFILE_LIST)))

all: StarSimulator tests

Debug: all
Release: all

StarSimulator:
	@$(CHK_DIR_EXISTS) bin || $(MKDIR) bin
	@$(CHK_DIR_EXISTS) obj || $(MKDIR) obj
	cd src && make

tests:
	@$(CHK_DIR_EXISTS) obj/tests || $(MKDIR) obj/tests
	cd tests && make
	
clean:
	rm -rf obj
	
mrproper: clean
	rm -rf bin
	rm -rf obj

