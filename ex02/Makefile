# ************************************************************************** #
#                                                                            #
#                                                        ::::::::            #
#   Makefile                                           :+:    :+:            #
#                                                     +:+                    #
#   By: tblaudez <tblaudez@student.codam.nl>         +#+                     #
#                                                   +#+                      #
#   Created: 2020/09/17 14:41:30 by tblaudez      #+#    #+#                 #
#   Updated: 2020/10/09 12:39:06 by tblaudez      ########   odam.nl         #
#                                                                            #
# ************************************************************************** #

NAME=moreforms

SRC= Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp \
ShrubberyCreationForm.cpp main.cpp
OBJ= $(SRC:%.cpp=%.o)

CC= /usr/bin/clang++
CFLAGS= -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run
