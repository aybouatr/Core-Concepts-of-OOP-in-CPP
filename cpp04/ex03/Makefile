NAME	= materia
SRC_DIR	= src/
INC_DIR = include/

SRC		= main.cpp \
			$(SRC_DIR)AMateria.cpp \
			$(SRC_DIR)Character.cpp \
			$(SRC_DIR)Cure.cpp \
			$(SRC_DIR)Ice.cpp \
			$(SRC_DIR)MateriaSource.cpp

OBJ		= $(SRC:.cpp=.o)
CXX		= c++
CFL		=  -I $(INC_DIR)
RM		= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFL) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CFL) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
