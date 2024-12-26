CXX = g++
CXXFLAGS = -g -pedantic -std=c++23
SOURCEDIR = src
BUILDDIR = build
# BUILDDIR = $(CURDIR)/build

SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
TARGETS = $(patsubst $(SOURCEDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))


all: $(TARGETS) | buildDir
	$(CXX) $(CXXFLAGS) -o $(BUILDDIR)/app.out $(TARGETS)


$(BUILDDIR)/%.o: $(SOURCEDIR)/%.cpp | buildDir
	$(CXX) $(CXXFLAGS) -c $< -o $@

buildDir:
	mkdir -p $(BUILDDIR)

clean:
	rm -rf build
