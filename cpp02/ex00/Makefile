C++ = c++
C++_FLAGS = -Wall -Wextra -Werror -std=c++98

INFILES = 	main.cpp src/Fixed.cpp

OBJFILES = $(INFILES:.cpp=.o)

NAME = Fixed

all: $(NAME)


$(NAME):$(OBJFILES)
	$(C++) $(C++_FLAGS) $(OBJFILES) -o $(NAME) 

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

