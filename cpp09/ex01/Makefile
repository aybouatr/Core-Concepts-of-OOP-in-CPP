NAME = RPN
CXX = c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -Iinclude
INFILES = main.cpp src/RPN.cpp

OBJFILES = $(INFILES:.cpp=.o)

all: $(NAME)
$(NAME):$(OBJFILES)
	$(CXX) $(CXX_FLAGS) $(INCLUDES) $(OBJFILES) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXX_FLAGS) $(INCLUDES) -c $< -o $@
clean:
	rm -f $(OBJFILES)
fclean: clean
	rm -f $(NAME)
re: fclean all	
.PHONY: all clean fclean re