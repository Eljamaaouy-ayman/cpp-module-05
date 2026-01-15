pro = Bureaucrat
com = c++
flages = -Wall -Wextra -Werror -std=c++98

src = main.cpp Bureaucrat.cpp form.cpp
obj = $(src:.cpp=.o)

all: $(pro)

$(pro): $(obj)
	$(com) $(flages) $(obj) -o $(pro)

%.o: %.cpp
	$(com) $(flages) -c $< -o $@

clean:
	rm -rf $(obj)

fclean: clean
	rm -rf $(pro)

re: fclean all