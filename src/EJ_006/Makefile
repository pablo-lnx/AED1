a.out: Producto.o DiccionarioProductos.o Interprete.o main.o
	g++ Producto.o DiccionarioProductos.o Interprete.o main.o

Producto.o: Producto.cpp Producto.h
	g++ -c Producto.cpp

DiccionarioProductos.o: DiccionarioProductos.cpp DiccionarioProductos.h Producto.h
	g++ -c DiccionarioProductos.cpp

Interprete.o: Interprete.cpp Interprete.h DiccionarioProductos.h Producto.h
	g++ -c Interprete.cpp

main.o: main.cpp Interprete.h DiccionarioProductos.h Producto.h
	g++ -c main.cpp