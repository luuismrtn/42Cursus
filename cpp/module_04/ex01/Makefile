C++ = c++
C++_FLAGS = -Wall -Wextra -Werror #-std=c++98
INFILES = 	main.cpp \
			src/Animal.cpp \
			src/Cat.cpp \
			src/Dog.cpp \
			src/WrongAnimal.cpp \
			src/WrongCat.cpp \
			src/Brain.cpp \

OBJFILES = $(INFILES:.cpp=.o)

NAME = animal

all: $(NAME)

$(NAME):$(OBJFILES)
	$(C++) $(C++_FLAGS) $(OBJFILES) -o $(NAME) 

%.o: %.cpp
	$(C++) $(C++_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re