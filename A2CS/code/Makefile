NAME = IOT

SRC = *.c

INCLUDES = . 
OBJECTS = *.o

all: $(NAME)

$(NAME):
	@ gcc -c $(SRC) -I $(INCLUDES)
	@ gcc -o $(NAME) $(OBJECTS)
	@ echo "IOT compiled"

clean:
	@ rm -f $(OBJECTS)
	@ echo "Fichiers objets supprimés"

fclean: clean
	@ rm -f $(NAME)
	@ echo "IOT supprimé"

re: fclean all
