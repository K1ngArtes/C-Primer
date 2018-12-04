# HIL: No spaces or comments after otherwise it captures them!
# Determine the platform
UNAME_S := $(shell uname -s)

# CC
ifeq ($(UNAME_S),Darwin)
    CC := clang++ -arch x86_64
else
    CC := g++
endif

# Folders
SRCDIR := src
BUILDDIR := build
TARGETDIR := bin

# Targets
EXECUTABLE := PrintBookItems
TARGET := $(TARGETDIR)/$(EXECUTABLE)

# Final paths
INSTALLBINDIR := /usr/local/bin

# Code Lists
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
# $(patsubst pattern,replacement,text)
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

# Folder Lists
INCDIRS := $(shell find include/** -name '*.h' -exec dirname {} \; | sort | uniq)
INCLIST := $(patsubst include/%,-I include/%,$(INCDIRS))
# BUILDLIST := $(patsubst include/%,$(BUILDDIR)/%,$(INCDIRS))
BUILDLIST := build/include

#  Flags
CFLAGS := -c -std=c++11
INC := -I include include -I /usr/local/include

$(TARGET): $(OBJECTS)
	@echo "$(INCDIRS)"
	@mkdir -p $(TARGETDIR)
	@echo "Linking..."
	@echo "Linking $(TARGET)"; $(CC) $^ -o $(TARGET)
	@echo "$(CC) $^ -o $(TARGET)"

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDLIST)
	@echo "$(CC) $(CFLAGS) -c -o $@ $<"
	@echo "Compiling $<..."; $(CC) $(CFLAGS) -c -o $@ $< -I $(INCLIST)

clean:
	@echo "Cleaning $(TARGET)..."; $(RM) -r $(BUILDDIR) $(TARGET)

install:
	@echo "Installing $(EXECUTABLE)..."; cp $(TARGET) $(INSTALLBINDIR)
  
distclean:
	@echo "Removing $(EXECUTABLE)"; rm $(INSTALLBINDIR)/$(EXECUTABLE)

.PHONY: clean