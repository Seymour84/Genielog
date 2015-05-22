lib: Ope_Matrice.a

Ope_Matrice.a: OperationM.o
	ar rv Ope_Matrice.a OperationM.o

OperationM.o: OperationM.cpp operationM.h
	$(CXX) -W -Wall OperationM.cpp -c -o OperationM.o


clean:
	rm *.o