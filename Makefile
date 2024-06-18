Genea: population.o queue.o export.o menu.o main.c
	gcc $^ -o $@

population.o: code/population.c code/population.h
	gcc -c $< -o $@

queue.o: code/queue.c code/queue.h
	gcc -c $< -o $@

export.o: code/export.c code/export.h
	gcc -c $< -o $@

menu.o: code/menu.c code/menu.h
	gcc -c $< -o $@

clean:
	rm -rf Genea *.o