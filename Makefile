LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
CXX := g++
CFLAGS = -Wall

SOURCEDIR := src
OBJECTDIR := obj
BUILDDIR := build

# Get all .cpp files
SRC := $(shell find $(SOURCEDIR) -name '*.cpp')

# Get all the .o files
OBJECTS := $(addprefix $(OBJECTDIR)/,$(notdir $(SRC:%.cpp=%.o)))

# Name of application
NAME = MyGame

all: $(NAME)

$(OBJECTDIR)/%.o: $(SOURCEDIR)/%.cpp
	$(CXX) -c $< -o $@

$(NAME): $(OBJECTS)
	@echo "** Building the game"
	$(CXX) -o $(NAME) $(OBJECTS) $(LIBS)

clean:
	@echo "** Removing object files and executable..."
	rm -f $(NAME) *.o

install:
	@echo "** Installing..."
	cp $(NAME) /usr/bin/

uninstall:
	@echo "** Uninstalling..."
	$(RM) /usr/bin/$(NAME)
