all:
	gcc -o Principal Principal.c Arboles.c Arboles.h Cuadros.c Cuadros.h `pkg-config --cflags --libs gtk+-2.0`
