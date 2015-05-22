lib: libOpe_Matrice.a
test: Ope_Matrice_Test

libOpe_Matrice.a: OperationM.o
	ar rv libOpe_Matrice.a OperationM.o

OperationM.o: OperationM.cpp OperationM.h
	$(CXX) -W -Wall OperationM.cpp -c -o OperationM.o

OperationC.o: OperationC.cpp OperationC.h
	$(CXX) -W -Wall OperationC.cpp -c -o OperationC.o

Ope_Matrice_Test: libOpe_Matrice.a
	$(CXX) main.cpp -lOpe_Matrice -L. -o Ope_Matrice_Test


clean:
	rm -f *.o

cleanall: clean
	rm -f libOpe_Matrice.a Ope_Matrice_Test