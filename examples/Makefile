PROJECT ?= Sandbox

# List of include directories
INCLUDE_DIRS := \
    ../vendor/spdlog/include \
    ../src

# Convert the list of include directories to -I flags
INCLUDE_FLAGS := $(addprefix -I, $(INCLUDE_DIRS))

# Combine include flags with other compiler flags
CC := g++
CFLAGS := -std=c++11 -Wall -Wextra $(INCLUDE_FLAGS)

# Architecture specific settings
ifeq ($(shell uname), Linux)
    OS := Linux
else ifeq ($(shell uname), Darwin)
    OS := Mac
else ifeq ($(shell uname), Windows_NT)
    OS := Windows
else
    $(error Unsupported operating system: $(shell uname))
endif

SRCDIR := $(PROJECT)/src
ROOTBUILDDIR := $(PROJECT)/build
ROOTDISTDIR := $(PROJECT)/dist
BUILDDIR := $(ROOTBUILDDIR)/$(OS)
DISTDIR := $(ROOTDISTDIR)/$(OS)
TARGET := $(DISTDIR)/$(PROJECT)
LIBRARYS := ../build/$(OS)/**/*.o

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

$(TARGET): $(OBJECTS)
	@echo "Linking..."
	@mkdir -p $(DISTDIR)
	$(CC) $(LIBRARYS) $^ -o $(TARGET)
	@echo "Build complete!"

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning..."
	$(RM) -r $(ROOTBUILDDIR) $(ROOTDISTDIR)
	@echo "Clean complete!"

.PHONY: clean
