C++ = c++
C++_FLAGS = -Wall -Wextra -Werror -std=c++98

INFILES = 	main.cpp src/HumanB.cpp src/Weapon.cpp src/HumanA.cpp

OBJFILES = $(INFILES:.cpp=.o)

NAME = unnecessary_violence

all: $(NAME)


$(NAME):$(OBJFILES)
	$(C++) $(C++_FLAGS) $(OBJFILES) -o $(NAME) 

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re