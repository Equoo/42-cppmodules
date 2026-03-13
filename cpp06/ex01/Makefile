NAME = bin
CXX = c++

DIR_OBJ = obj/
SRC_DIR = ./
INC_DIR = ./
SRC_EXT = cpp

COMPILE_FLAGS = -Wall -Wextra -Werror -MMD -std=c++98
INCLUDES =
LIBS = 
SRCS = main.cpp \
       Serializer.cpp \

OBJS = ${patsubst %.cpp,$(DIR_OBJ)%.o, $(SRCS)}

DEPS = ${patsubst %.cpp,$(DIR_OBJ)%.d, $(SRCS)}
-include $(DEPS)

.SILENT:

.PHONY: all
all: export CXXFLAGS := $(CXXFLAGS) $(COMPILE_FLAGS)
all:
	$(MAKE) -j $(nproc) --no-print-directory SRCS="$(SRCS)" $(NAME)

.PHONY: debug
debug: export CXXFLAGS := $(CXXFLAGS) $(COMPILE_FLAGS) -O0 -g3 -D DEBUG=1
debug:
	$(MAKE) -j $(nproc) --no-print-directory SRCS="$(SRCS)" $(NAME)

%/:
	mkdir -p $@

$(DIR_OBJ)%.o: $(SRC_DIR)%.$(SRC_EXT)
	echo "Compiling $*.$(SRC_EXT)"
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MP -MMD -c $< -o $@

$(NAME): $(DIR_OBJ) $(OBJS) Makefile
	$(CXX) $(OBJS) -o $@ ${LIBS}

.PHONY: clean
clean:
	rm -Rf $(DIR_OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re:
	$(MAKE) -j $(nproc) --no-print-directory fclean
	$(MAKE) --no-print-directory all

.DEFAULT_GOAL = all
