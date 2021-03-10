all: files

files: UI.o tokenizer.o history.o
	gcc UI.o tokenizer.o history.o -o program

tokenizer.o: tokenizer.c
	gcc -c tokenizer.c

history.o: history.c
	gcc -c history.c
UI.o: UI.c
	gcc -c UI.c

clean:
	-rm *o program
