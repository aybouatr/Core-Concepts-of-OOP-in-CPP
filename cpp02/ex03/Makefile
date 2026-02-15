CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98


INFILES = 	main.cpp src/Fixed.cpp src/Point.cpp src/bsp.cpp

OBJFILES = $(INFILES:.cpp=.o)

NAME = Point

all: $(NAME)


$(NAME):$(OBJFILES)
	$(CXX) $(CXXFLAGS) $(OBJFILES) -o $(NAME) 

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

