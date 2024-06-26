# [LiChao Tree](lichao_tree.cpp)

Uma árvore de funções. Retorna o $f(x)$ máximo em um ponto $x$.

Para retornar o minimo deve-se inserir o negativo da função ($g(x) = -ax - b$) e pegar o negativo do resultado. Ou, alterar a função de comparação da árvore se souber mexer.

Funciona para funções com a seguinte propriedade, sejam duas funções $f(x)$ e $g(x)$, uma vez que $f(x)$ passa a ganhar/perder pra $g(x)$, $f(x)$ nunca mais passa a perder/ganhar pra $g(x)$. Em outras palavras, $f(x)$ e $g(x)$ se intersectam no máximo uma vez.

Essa implementação está pronta para usar função linear do tipo $f(x) = ax + b$.

Sendo $L$ o tamanho do intervalo, a complexidade de consulta e inserção de funções é $\mathcal{O}(\log L)$.

**Dica**: No construtor da LiChao Tree, fazer `tree.reserve(MAX); L.reserve(MAX); R.reserve(MAX);` pode ajudar bastante no runtime, pois aloca espaço para os vetores e evita muitas realocações durante a execução. Nesse caso, `MAX` é geralmente $\mathcal{O}(Q \cdot \log L)$, onde $Q$ é o número de queries e $L$ é o tamanho do intervalo.