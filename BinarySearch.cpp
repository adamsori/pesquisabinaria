#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib> // protótipos para as funções srand e rand
using std::rand;
using std::srand;

#include <ctime> // protótipo para a função time
using std::time;

#include <algorithm> // protótipo para a função sort
#include "BinarySearch.h" // definição da classe BinarySearch

// construtor inicializa vetor com ints aleatórios e classifica o vetor
BinarySearch::BinarySearch(int vectorSize){
    size = ( vectorSize > 0 ? vectorSize : 10); // valida vectorSize
    srand( time(0) ); // semeia utilizando a hora atual

    // preenche o vetor com ints aleatórios no intervalo de 10-99
    for( int i = 0; i < size; i++)
        data.push_back( 10 + rand() % 90); // 10-99

    std::sort( data.begin(), data.end()); // classifica os dados
    
} // fim do construtor BinarySearch

// Realiza a pesquisa linear nos dados
int BinarySearch::binarySearch( int searchElement) const
{
    int low = 0; // extremidade baixa da área de pesquisa
    int high = size - 1; // extremidade alta da área de pesquisa
    int middle = ( low + high + 1) / 2; // elemento intermediário
    int location = -1;  // valor de retorno; -1 se não localizado

    do // faz um loop para procurar o elemento
    {
        //imprime elementos restantes de vetor a ser pesquisado
        displaySubElements( low, high);

        //gera espaços para alinhamento
        for(int i = 0; i < middle; i++)
            cout << "   ";
        
        cout << " * "; // indica o meio atual

        // se o elemento for localizado no meio
        if( searchElement == data[ middle ])
            location = middle; // a localização é o meio atual
        else if( searchElement < data[ middle ]) // o meio é muito alto
            high = middle - 1; // elimina a metade mais alta
        else // elemento do meio é muito baixo
            low = middle + 1; // elimina a metade mais baixa
        
        middle = ( low + high + 1) / 2; // recalcula o meio
    } while (( low <= high) && ( location == -1));

    return location; // retorna a localização da chave de pesquisa
} // fim da função BinarySearch

// exibe valores no vetor
void BinarySearch::displayElements() const
{
    displaySubElements( 0, size-1);
}

// exibe certos valores no vetor
void BinarySearch::displaySubElements( int low, int high) const
{
    for( int i = 0; i < low; i++) // gera espaços para alinhamento
        cout << "   ";
    for( int i = 0; i <= high; i++) // gera saída dos elementos deixados no vetor
        cout << data[i] << " ";
    cout << endl;
} // fim da função displaySubElements