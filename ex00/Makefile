NAME		=	Bureaucrat
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++17 -Wno-shadow
INCLUDE		=	-I include
RM			=	rm -f

_HEADER		=	Bureaucrat.hpp
HEADER		=	$(patsubst %, include/%, $(_HEADER))
_SRC		=	main.cpp\
				Bureaucrat.cpp\
				BureaucratExceptions.cpp
SRC			=	$(patsubst %, src/%, $(_SRC))
OBJ			=	$(SRC:src/%.cpp=bin/%.o)

all: $(NAME)

bin:
	mkdir -p bin

bin/%.o: src/%.cpp $(HEADER) | bin
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re