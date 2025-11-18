outfile: main.o delete_record.o display.o display_from_file.o func_exit.o insert.o load_file.o modifiy.o reverse.o save.o sorti.o
	cc -o student main.o delete_record.o display.o display_from_file.o func_exit.o insert.o load_file.o modifiy.o reverse.o save.o sorti.o
main.o: main.c header.h
	cc -c main.c

delete_record.o: delete_record.c header.h
	cc -c delete_record.c

display.o: display.c header.h
	cc -c display.c

display_from_file.o: display_from_file.c header.h
	cc -c display_from_file.c

func_exit.o: func_exit.c header.h
	cc -c func_exit.c

insert.o: insert.c header.h
	cc -c insert.c

load_file.o: load_file.c header.h
	cc -c load_file.c

modifiy.o: modifiy.c header.h
	cc -c modifiy.c

reverse.o: reverse.c header.h
	cc -c reverse.c

save.o: save.c header.h
	cc -c save.c

sorti.o: sorti.c header.h
	cc -c sorti.c

# Clean build files
clean:
	rm -f *.o outfile

