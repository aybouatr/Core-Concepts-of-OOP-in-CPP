NAME		=	phonebook
CC			=	c++
CFLAGS		=	 -Wall -Wextra -Werror -std=c++98

SRC_FILES	=	main.cpp src/PhoneBook.cpp src/Contact.cpp
OBJ_FILES	=	$(SRC_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "Build complete ✅"

%.o: %.cpp
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJ_FILES)

fclean: clean
	@echo "Removing executable..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
