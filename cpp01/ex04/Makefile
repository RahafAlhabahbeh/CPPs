NAME	= replace

CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

OBJ_DIR	= objs

SRC		= main.cpp
OBJ		= $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
 
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re