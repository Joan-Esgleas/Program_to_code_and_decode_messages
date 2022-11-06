OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
#
G++ = g++-10
#
OBJETOS = $(PWD)/Objects/
#
IMPLEMENTACIONES = $(PWD)/Implementaciones/
#
all: c main.exe Doxy

d: doxy

c: clean

e: execute

et: c main.exe Doxy
ifneq ("$(wildcard $(PWD)/Input_Test.txt)","")
ifneq ("$(wildcard $(PWD)/Output_Test.txt)","")
	./main.exe < Input_Test.txt
	clear
else
	touch Output_Test.txt
	./main.exe < Input_Test.txt
endif
else
	touch Input_Test.txt
	echo "No existia un texto donde poner un input pon el Input_Test.txt que se acaba de crear"
	clear
endif

drive: c main.exe Doxy tar zip
	firefox https://drive.google.com/drive/my-drive
	clear

main.exe: main.o Alfabeto.o Conjunto_Alfabetos.o Mensaje.o Conjunto_Mensajes.o
	$(G++) -o main.exe $(OBJETOS)*.o

main.o: $(IMPLEMENTACIONES)main.cc
	$(G++) -c $(IMPLEMENTACIONES)main.cc $(OPCIONS) -o $(OBJETOS)main.o

Alfabeto.o: $(IMPLEMENTACIONES)Alfabeto.cc
	$(G++) -c $(IMPLEMENTACIONES)Alfabeto.cc $(OPCIONS) -o $(OBJETOS)Alfabeto.o

Conjunto_Alfabetos.o: $(IMPLEMENTACIONES)Conjunto_Alfabetos.cc
	$(G++) -c $(IMPLEMENTACIONES)Conjunto_Alfabetos.cc $(OPCIONS) -o $(OBJETOS)Conjunto_Alfabetos.o

Mensaje.o: $(IMPLEMENTACIONES)Mensaje.cc
	$(G++) -c $(IMPLEMENTACIONES)Mensaje.cc $(OPCIONS) -o $(OBJETOS)Mensaje.o

Conjunto_Mensajes.o: $(IMPLEMENTACIONES)Conjunto_Mensajes.cc
	$(G++) -c $(IMPLEMENTACIONES)Conjunto_Mensajes.cc $(OPCIONS) -o $(OBJETOS)Conjunto_Mensajes.o

execute: c main.exe Doxy
	./main.exe

doxy: c main.exe Doxy $(PWD)/DOC/html/index.html
	firefox $(PWD)/DOC/html/index.html
	clear

Doxy: Doxyfile
	doxygen Doxyfile
	clear

clean:
	rm -f *.o
	rm -f *.exe
	rm -f $(OBJETOS)*.o
	rm -f *.zip
	rm -f *.gz
	clear

zip: main.exe
	zip -r Practica.zip Cabeceras DOC Implementaciones Objects OmitirEnDoxygen main.exe Makefile enunQT2022.pdf Doxyfile Doxy_main_page.txt
	clear

tar: main.exe
	tar -cvzf Practica.tar.gz Cabeceras DOC Implementaciones Objects OmitirEnDoxygen main.exe Makefile enunQT2022.pdf Doxyfile Doxy_main_page.txt
	clear