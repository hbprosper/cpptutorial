#-----------------------------------------------------------------------
# File:	Makefile for C++ tutorial
#
# Description: This file contains the instructions to compile and link
#  programs
#           make
#
# Created: 24-Jul-2008	Harrison B. Prosper
#-----------------------------------------------------------------------
# Sub-directories
srcdir	:= src
appdir	:= examples
bindir	:= bin
libdir	:= lib
incdir	:= include

# make sure bin and lib directories exist
$(shell mkdir -p $(libdir) $(bindir))

# Set AT equal to the @ symbol to suppress display of instructions
# while make executes
ifdef verbose
AT 	:=
else
AT	:= @ 
endif

# -- SOURCES

# list of sources to be compiled into shared library 
ccsrcs	:= $(wildcard $(srcdir)/*.cc)

# list of sources to be compoled into its own shared library
cxxsrcs	:= $(wildcard $(srcdir)/*.cxx)

appsrcs	:= $(wildcard $(appdir)/*.cc)

#say	:= $(shell echo "app sources: $(appsrcs)" >& 2)
#$(error bye!)

# -- OBJECTS

# list of object modules from list of sources
ccobjs	:= $(ccsrcs:.cc=.o)

cxxobjs	:= $(cxxsrcs:.cxx=.o)

appobjs	:= $(appsrcs:.cc=.o)

# -- EXECUTABLE BINARIES

# list of applications
applications := $(subst $(appdir)/,$(bindir)/,$(appsrcs:.cc=))

#say	:= $(shell echo "app: $(applications)" >& 2)
#$(error bye!)

sources	:= $(ccsrcs) $(appsrcs)
objects	:= $(ccobjs) $(appobjs)

# Libraries
libname	:= cpptutorial
libs 	:= -L$(libdir) -l$(libname) -lpoem
#say	:= $(shell echo "sources: $(sources)" >& 2)
#$(error bye!) 

# all ".cc" src objects go into a single shared library
sharedlib := $(libdir)/lib$(libname).so

# each ".cxx" src into its own shared library
slibs := $(subst $(srcdir)/,$(libdir)/lib,$(cxxsrcs:.cxx=.so))

#say	:= $(shell echo "shared libs: $(slibs)" >& 2)
#$(error bye!)

#-----------------------------------------------------------------------

# 	Define which compilers and linkers to use

# 	C++ Compiler
CXX	:= g++

#	C++ Linker
LD	:= g++
LDSHARED:= g++ -shared

# 	Define paths to be searched for C++ header files (#include ....)

CPPFLAGS:= -I. -Iinclude #$(shell root-config --cflags)

# 	Define compiler flags to be used
#	-c		perform compilation step only 
#	-g		include debug information in the executable file
#	-O2		use 2nd level of optimization
#	-Wall		warn if source uses any non-standard C++
#	-pipe		communicate between different stages of compilation
#			using pipes rather than temporary files

CXXFLAGS:= -c -g -O2 -Wall -pipe -fPIC

#	Linker flags

LDFLAGS := -g #-L/usr/lib 

# 	Libraries
#	System libraries reside in /usr/lib and /lib. They are usually 
#	shared libraries, identified by the file extension ".so".

LIBS	:= -lm $(libs) #$(shell root-config --libs)

#	Rules
#	The structure of a rule is
#	target : source
#		command
#	The command makes a target from the source. 
#	$@ refers to the target
#	$< refers to the source

bin:	$(sharedlib) $(slibs) $(applications) 

lib:	$(sharedlib) $(slibs)

# Syntax:
# list of targets : target pattern : source pattern

$(slibs)	: $(libdir)/lib%.so	: $(srcdir)/%.o
	@echo "---> Linking $@"
	$(AT)$(LDSHARED) $(LDFLAGS) -fPIC $+ -o $@
	@echo ""

$(sharedlib)	: $(ccobjs)
	@echo "---> Linking $@"
	$(AT)$(LDSHARED) $(LDFLAGS) -fPIC $+ -o $@
	@echo ""

$(applications)	: $(bindir)/%	: $(appdir)/%.o
	@echo "---> Linking $@"
	$(AT)$(LD) $(LDFLAGS) $< $(LIBS) -o $@
	@echo ""

$(objects)	: %.o	: %.cc
	@echo "---> Compiling `basename $<`" 
	$(AT)$(CXX) $(CXXFLAGS) $(CPPFLAGS)  $< -o $@ #>& $*.FAILED
	$(AT)rm -rf $*.FAILED
	@echo ""

$(cxxobjs)	: %.o	: %.cxx
	@echo "---> Compiling `basename $<`" 
	$(AT)$(CXX) $(CXXFLAGS) $(CPPFLAGS)  $< -o $@ #>& $*.FAILED
	$(AT)rm -rf $*.FAILED
	@echo ""

# 	Define clean up rules
clean   :
	rm -rf $(srcdir)/*.o $(appdir)/*.o $(bindir)/* $(libdir)/*.so
