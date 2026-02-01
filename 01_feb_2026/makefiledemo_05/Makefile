CC = gcc

app: main.o helper.o
	$(CC) main.o helper.o -o app

main.o:
	$(CC) -c main.c

helpr.o:
	$(CC) -c helper.c

clean:
	rm -f app *.o

run:
	./app