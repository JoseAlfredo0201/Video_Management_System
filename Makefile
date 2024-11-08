main.o: main.cpp
	g++ -o main.o main.cpp Includes/*.cpp 
clean:
	rm -f *.o main

test:
	# Aquí puedes agregar comandos para ejecutar pruebas
	@echo "No tests defined"
