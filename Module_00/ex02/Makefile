NAME        = Account
SRCS        = Account.cpp tests.cpp
OBJDIR      = .obj
OBJS        = $(SRCS:%.cpp=$(OBJDIR)/%.o)

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
