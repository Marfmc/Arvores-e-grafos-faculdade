# Arvores-e-grafos-faculdade
esse repositório serve para subir exercícios da aula

## Métodos de Ordenação
Bubble Sort: Percorre o array repetidamente, comparando elementos adjacentes e trocando-os caso estejam na ordem errada. O maior elemento "flutua" para a posição final a cada iteração.

Selection Sort: Baseia-se em selecionar o menor elemento restante no array e trocá-lo com a posição atual. É eficiente em termos de movimentação de memória, pois realiza o número mínimo de trocas.

Insertion Sort: Insere cada elemento na sua posição correta em relação aos elementos já processados. É eficiente para pequenos volumes de dados ou arrays que já se encontram parcialmente ordenados.

Quick Sort: Utiliza a estratégia de "dividir para conquistar". Escolhe um elemento como pivô e particiona o array em dois sub-arrays (elementos menores e maiores que o pivô), ordenando-os recursivamente.

Merge Sort: Divide o array recursivamente em metades até que cada parte tenha apenas um elemento. Em seguida, as partes são intercaladas (mescladas) de forma ordenada.

Shell Sort: É uma extensão do Insertion Sort que permite a troca de elementos distantes. O algoritmo reduz gradualmente a distância entre os elementos comparados até realizar uma ordenação simples no final.

# Aspectos Técnicos da Implementação
Medição de Tempo: A biblioteca <time.h> é utilizada para capturar o tempo de execução. O cálculo é feito subtraindo o tempo inicial do tempo final da chamada da função.

Função Auxiliar printArray: Responsável por exibir o estado do vetor no console antes e depois de cada processamento, facilitando a validação visual dos resultados.

Menu Interativo: Implementado para permitir que o usuário escolha o método de ordenação e o tamanho do conjunto de dados dinamicamente durante a execução.

Comparação de Desempenho: Para garantir a integridade dos testes, todos os algoritmos são testados com cópias idênticas do mesmo array desordenado, evitando que um método se beneficie do estado deixado pelo anterior.
