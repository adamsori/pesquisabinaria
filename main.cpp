// Programa de teste BinarySearch

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "BinarySearch.h" // definição da classe BinarySearch

int main()
{
    int searchInt; // chave de pesquisa
    int position; // localização da chave de pesquisa no vetor

    // cria vetor e gera sua saída
    BinarySearch searchVector( 15 );
    searchVector.displayElements();

    // obtém a entrada do usuário
    cout << "\nEntre com um valor inteiro (-1 para finalizar): ";
    cin >> searchInt; // lê um int do usuário
    cout << endl;

    // insere repetidamente um inteiro; -1 termina o programa
    while( searchInt != -1)
    {

        //utiliza a pesquisa binária para tentar localizar o inteiro
        position = searchVector.binarySearch( searchInt );

        //valor de retorno -1 indica que o inteiro não foi localizado
        if( position == -1)
            cout << "O inteiro " << searchInt << " não foi encontrado.\n";
        else
            cout << "O inteiro " << searchInt << " foi encontrado na posição " << position << ".\n";

        // obtém a entrada do usuário
        cout << "\n\nEntre com um valor inteiro (-1 para finalizar): ";
        cin >> searchInt; // lê um int do usuário
        cout << endl;
    } // fim do while

    return 0;
} // fim do main