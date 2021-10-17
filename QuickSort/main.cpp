#include <iostream>
#include <vector>
#include <time.h>
#include <string>

using namespace std;


void showArr (int arr[], int noe) {
    for (int i = 0; i < noe; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void quickSort(int arr[], int izq, int der, int noe) {
    //cout << "Final: " << der << endl;

    int pivote = arr[izq];
    int i = izq;
    int j = der;
    int aux;

    while ( i < j ) {
        while ( arr[i] <= pivote && i < j ) {
            i++;
        }
        while ( arr[j] >pivote ) {
            j--;
        }
        if ( i < j ) {
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }
    }

    arr[izq] = arr[j];
    arr[j] = pivote;

    if ( izq < j-1 ) {
        quickSort(arr, izq, j-1, noe);
    }
    if ( j+1 < der ) {
        quickSort(arr, j+1, der, noe);
    }
}

int main()
{
    setlocale(LC_CTYPE, "Spanish");
    srand(time(NULL));

    cout << "Quick Sort" << endl;
    cout << "García Martínez Braulio Israel 220331615" << endl;

    /** Definición de la longitud del vector */
    int noe;
    do{
        cout << "Ingrese la cantidad de datos que desea ordenar: ";
        cin >> noe;

        if( (noe < 2) || (noe >100) ){
            cout << "La cantidad mínima de elementos son 2 y la cantidad máxima son 100" << endl;
        }
    }while( (noe < 2) || (noe > 100) );

    /** Ingreso de datos al vector */
    int items[noe];
    int value;
    for( int i = 0; i < (sizeof items/sizeof items[0]); i++ ){
        items[i] = rand() % 10 + 1;
        // cout << items[i] << endl;
    }

    cout << " tamanio 2: " << sizeof items/sizeof items[0] << endl;

    showArr(items, noe);
    quickSort(items, 0, (sizeof items/sizeof items[0]), noe);
    showArr(items, noe);
    return 0;
}
