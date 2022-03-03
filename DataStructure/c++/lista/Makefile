##########################################################################################
# Ejemplo de un archivo Makefile que puede compilar todos los archivos fuente			 #
# y crear una aplicación con el nombre que fue asignado a la variable TARGET			 #
# archivos C -> .c std=[c99|c11|c18], compilador: gcc									 #
# archivos C++-> .cpp, .c++, .cc, .cxx std=[c++11|c++14|c++17|c++latest], compilador:g++ #
# LDFLAGS=-lm																			 #
##########################################################################################

TARGET=list
SOURCE=$(wildcard *.cpp)
OBJECT:=$(SOURCE:.cpp=.o)
DESTDIR=/usr/local/bin

CC = g++
CFLAGS = -g -Wall -Weffc++ -Wextra -Wsign-conversion -Werror -pedantic-errors -std=c++17
LDFLAGS=

all: $(TARGET)

$(TARGET): $(OBJECT)
		@echo "Linking..."
		$(CC) -o $@ $^ $(LDFLAGS)
		@echo "Finished!"

%.o: %.cpp
		@echo "Compiling..."
		$(CC) $(CFLAGS) -c $< -o $@ 

.PHONY: help clean run

run: all
		./$(TARGET)

install: all
		@if [ ! -d $(DESTDIR) ] ; then \
			sudo mkdir $(DESTDIR) ; \
		fi ; \
		sudo cp $(TARGET) $(DESTDIR)

uninstall:
		sudo rm $(DESTDIR)/$(TARGET)

clean:
		rm -f $(TARGET) $(OBJECT)

help:
		@echo "target: $(TARGET)"
		@echo "source: $(SOURCE)"
		@echo "object: $(OBJECT)"
