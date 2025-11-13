ITOG=maim
OBJ=main.o
ISH=main.cpp
FLAGS= -Wall -g

$(ITOG): $(OBJ)
    g++ $(FLAGS) $(OBJ) -o $(ITOG)

$(OBJ): $(ISH)
    g++ $(FLAGS) -c $(ISH) -o $(OBJ)

clean:
    rm -f *.o $(ITOG)
