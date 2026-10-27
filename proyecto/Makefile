a.out: Producto.o TablaHash.o DiccionarioProductos.o Interprete.o main.o
	g++ Producto.o TablaHash.o DiccionarioProductos.o Interprete.o main.o

Producto.o: Producto.cpp Producto.h
	g++ -c Producto.cpp

TablaHash.o: TablaHash.cpp TablaHash.h Producto.h
	g++ -c TablaHash.cpp

DiccionarioProductos.o: DiccionarioProductos.cpp DiccionarioProductos.h Producto.h TablaHash.h
	g++ -c DiccionarioProductos.cpp

Interprete.o: Interprete.cpp Interprete.h DiccionarioProductos.h TablaHash.h Producto.h
	g++ -c Interprete.cpp

main.o: main.cpp Interprete.h DiccionarioProductos.h TablaHash.h Producto.h
	g++ -c main.cpp