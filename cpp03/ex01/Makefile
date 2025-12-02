C++ = c++
C++_FLAGS = -Wall -Wextra -Werror 

INFILES = 	main.cpp src/ClapTrap.cpp src/ScavTrap.cpp

OBJFILES = $(INFILES:.cpp=.o)

NAME = ClapTrap

all: $(NAME)


$(NAME):$(OBJFILES)
	$(C++) $(C++_FLAGS) $(OBJFILES) -o $(NAME) 

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

