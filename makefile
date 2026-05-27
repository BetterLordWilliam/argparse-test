CC=gcc

windows:
	$(CC) ./src/main.c ./src/argparse.h ./src/argparse.c -o ./build/main.exe

