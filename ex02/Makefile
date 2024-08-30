NAME		=	real_work
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++17 -Wno-shadow
_INCLUDE		=	include include/Forms
INCLUDE		=	$(addprefix -I, $(_INCLUDE))
RM			=	rm -f

_FORMS_HPP	=	AForm.hpp\
				ShrubberyCreationForm.hpp\
				RobotomyRequestForm.hpp\
				PresidentialPardonForm.hpp
FORMS_HPP	=	$(patsubst %, Forms/%, $(_FORMS_HPP))
_HEADER		=	AExceptions.hpp\
				Bureaucrat.hpp\
				$(FORMS_HPP)
HEADER		=	$(patsubst %, include/%, $(_HEADER))

_FORM_SRCS	=	AForm.cpp\
				ShrubberyCreationForm.cpp\
				RobotomyRequestForm.cpp\
				PresidentialPardonForm.cpp
FORM_SRCS	=	$(patsubst %, Forms/%, $(_FORM_SRCS))
_SRC		=	main.cpp\
				AExceptions.cpp\
				Bureaucrat.cpp\
				$(FORM_SRCS)
SRC			=	$(patsubst %, src/%, $(_SRC))
OBJ			=	$(SRC:src/%.cpp=bin/%.o)

YELLOW		=	\033[3;33m
GREEN		=	\033[1;32m
RED			=	\033[3;31m
RESET		=	\033[0m

GREEN_FORMAT	=	"\r$(GREEN)%-80s$(RESET)\n"
RED_FORMAT		=	"\r$(RED)%-80s$(RESET)"
YELLOW_FORMAT	=	"\r$(YELLOW)%-80s$(RESET)"

all: $(NAME)

bin:
	mkdir -p bin/forms

bin/%.o: src/%.cpp $(HEADER) | bin
	@printf $(YELLOW_FORMAT) "Compiling $(patsubst bin/%, %, $@)..."
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@
	@printf $(GREEN_FORMAT) "Linking complete!"

# @printf $(RED_FORMAT) "Removing binaries..."
clean:
	@for obj in $(OBJ); do \
		printf $(RED_FORMAT) "Removing $$obj...";\
		$(RM) $$obj; \
		sleep 0.1; \
	done
	@printf $(GREEN_FORMAT) "The cleaning process is complete!"

fclean: clean
	@printf $(RED_FORMAT) "Removing $(NAME)..."
	@$(RM) $(NAME)
	@sleep 0.2
	@printf $(GREEN_FORMAT) "The full cleaning process is complete!"

re: fclean all

.PHONY: all clean fclean re