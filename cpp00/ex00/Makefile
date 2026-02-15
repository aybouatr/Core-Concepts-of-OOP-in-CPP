Name = megaphone
CC = c++
Flags = -Wall -Wextra -Werror -std=c++98

SRC_FILE = megaphone.cpp
OBJ_FILE = $(SRC_FILE:.cpp=.o)

all: $(Name)

$(Name): $(OBJ_FILE)
	$(CC) $(Flags) -o $(Name) $(OBJ_FILE)

%.o: %.cpp
	$(CC) $(Flags) -c $< -o $@

clean:
	rm -f $(OBJ_FILE)

fclean: clean
	rm -f $(Name)

re: fclean all

.PHONY: all clean fclean re
