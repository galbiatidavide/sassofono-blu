CXX      ?= g++
CXXFLAGS ?= -std=c++20
CPPFLAGS ?= -O3 -Wall -I. -Wno-conversion-null -Wno-deprecated-declarations

OBJECTS = main.o
SOURCES = main.c
EXEC     = main
LDFLAGS ?= 
LDLIBS  ?=

SRCS=main.cpp other.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS=$(wildcard *.hpp)

exe_sources = $(filter main%.cpp, $(SRCS))
EXEC = main

# Flags for the muParser example.
CPPFLAG_MUPARSER ?= -I../../../../Examples/include
EXEC_MUPARSER     = main_getpot_muparser
LDFLAGS_MUPARSER ?= -L../../../../Examples/lib -Wl,-rpath=../../../../Examples/lib
LIB_MUPARSER     ?= -lmuparser
.DEFAULT_GOAL = all

all: $(EXEC) $(EXEC_MUPARSER)

$(EXEC): $(OBJS)

$(EXEC_MUPARSER).o: %.o: %.cpp compute_ODE.hpp Data.hpp
	$(CXX) -c $(CPPFLAGS) $(CPPFLAG_MUPARSER) $(CXXFLAGS) $<

$(EXEC_MUPARSER): %: %.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LDFLAGS_MUPARSER) $< $(LIBS) $(LIB_MUPARSER) -o $@

$(OBJS): $(SRCS) $(HEADERS)

clean:
	$(RM) *.o

distclean: clean
	$(RM) $(EXEC) $(EXEC_MUPARSER)
	$(RM) *~
