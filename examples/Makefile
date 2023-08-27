PROJECT ?= Sandbox

CC := g++
CFLAGS := -std=c++11 -Wall -Wextra

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
INCLUDES := ../src
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
	$(CC) -I $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning..."
	$(RM) -r $(ROOTBUILDDIR) $(ROOTDISTDIR)
	@echo "Clean complete!"

.PHONY: clean
