
NAME = djson

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
INCLUDE = -Isrc/parser -Isrc/lib -Isrc/lib/memory

LIB_SRC = src/lib/mapped_file.cc

PARSER_SRC = src/parser/djson_parser.cc src/parser/djson_lexer.cc

SRC = src/main.cc src/djson.cc src/djson_usage.cc src/logging.cc $(LIB_SRC) $(PARSER_SRC)

OBJ = $(SRC:%.cc=objs/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

objs/%.o: %.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf objs

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
