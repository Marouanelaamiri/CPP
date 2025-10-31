NAME = violence

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

INC = Weapon.hpp HumanA.hpp HumanB.hpp

OBJ = $(SRC:.cpp=.o)

C++FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(C++FLAGS) $(OBJ) -o $@

%.o: %.cpp $(INC)
	c++ $(C++FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all