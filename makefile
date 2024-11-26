fork.o: fork.c
	@gcc -c fork.c
compile fork: fork.o
	@gcc -o fork fork.o
run: fork
	@./fork
clean:
	@rm -f *.o
	@rm -f arrays
