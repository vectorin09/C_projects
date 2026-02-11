
outfile: main.o schedular.o task.o timer.o
	cc -o outfile main.o schedular.o task.o timer.o 
timer.o: timer.c   schedular.h task.h timer.h
	cc -c timer.c
main.o: main.c schedular.h task.h timer.h
	cc -c main.c

task.o: task.c schedular.h task.h timer.h
	cc -c task.c

schedular.o: schedular.c schedular.h task.h timer.h 
	cc -c schedular.c
run: outfile
	./outfile

clean:
	rm -f *.o outfile

