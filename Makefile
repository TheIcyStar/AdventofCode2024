CXX = g++
CXXFLAGS = -g -pedantic -std=c++23
SOURCEDIR = src
BUILDDIR = build
# BUILDDIR = $(CURDIR)/build

SOURCES = $(shell find $(SOURCEDIR) -name '*.cpp')
TARGETS = $(patsubst $(SOURCEDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
DIRS = $(patsubst %/,%,$(dir $(TARGETS)))


all: $(TARGETS) | buildDir
	$(CXX) $(CXXFLAGS) -o $(BUILDDIR)/app.out $(TARGETS)


$(BUILDDIR)/%.o: $(SOURCEDIR)/%.cpp | buildDir
	$(CXX) $(CXXFLAGS) -c $< -o $@

buildDir:
	mkdir -p $(DIRS)

clean:
	rm -rf build
