C++ = c++
C++_FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

OBJDIR = obj

INFILES = 	main.cpp \
			src/RPN.cpp

OBJFILES = $(addprefix $(OBJDIR)/, $(notdir $(INFILES:.cpp=.o)))

NAME = RPN

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJFILES)
	$(C++) $(C++_FLAGS) $(OBJFILES) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp
	$(C++) $(C++_FLAGS) -c $< -o $@

$(OBJDIR)/%.o: src/%.cpp
	$(C++) $(C++_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re