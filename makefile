proFile: src/helperA3.o src/sortEmployeesId.o src/fireAll.o src/lookOnFullName.o src/fireOne.o src/recruitEmployee.o src/countEmployees.o src/lookOnId.o src/printAll.o src/printOne.o src/mainA3.o
	gcc -Wall -std=c99 helperA3.o sortEmployeesId.o fireAll.o countEmployees.o fireOne.o lookOnFullName.o recruitEmployee.o printAll.o printOne.o lookOnId.o mainA3.o -o bin/proFile
src/mainA3.o:
	gcc -Wall -std=c99 -c src/mainA3.c
src/printAll.o:
	gcc -Wall -std=c99 -c src/printAll.c
src/sortEmployeesId.o:
	gcc -Wall -std=c99 -c src/sortEmployeesId.c
src/lookOnFullName.o:
	gcc -Wall -std=c99 -c src/lookOnFullName.c
src/fireOne.o:
	gcc -Wall -std=c99 -c src/fireOne.c
src/fireAll.o:
	gcc -Wall -std=c99 -c src/fireAll.c
src/countEmployees.o:
	gcc -Wall -std=c99 -c src/countEmployees.c
src/lookOnId.o:
	gcc -Wall -std=c99 -c src/lookOnId.c
src/printOne.o:
	gcc -Wall -std=c99 -c src/printOne.c
src/recruitEmployee.o:
	gcc -Wall -std=c99 -c src/recruitEmployee.c
src/helperA3.o:
	gcc -Wall -std=c99 -c src/helperA3.c
clean:
	rm ./bin/proFile  *.o






