// Classe que contém um vetor de inteiros aleatórios e uma função
// que utiliza a pesquisa binária para localizar um inteiro.
#include <vector>
using std::vector;

class BinarySearch
{
  public:
    BinarySearch(int); // construtor inicializa vetor
    int binarySearch(int) const; // realiza uma pesquisa binária no vetor
    void displayElements() const; // exibe elementos do vetor
  private:
    int size; // tamanho do vetor
    vector<int> data; //vetor de ints
    void displaySubElements(int,int) const; // exibe intervalo de valores
}; 
