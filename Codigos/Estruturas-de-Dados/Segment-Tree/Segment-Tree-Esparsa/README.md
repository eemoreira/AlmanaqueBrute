# [Segment Tree Esparsa](seg_tree_sparse.cpp)

Segment Tree Esparsa, ou seja, não armazena todos os nodos da árvore, apenas os necessários, dessa forma ela suporta operações em intervalos arbitrários. A construção é $\mathcal{O}(1)$ e as operações de consulta e update são $\mathcal{O}(\log L)$, onde $L$ é o tamanho do intervalo. A implementação suporta operações de consulta em intervalo e update pontual. Está implementada para soma, mas pode ser facilmente modificada para outras operações. 

Para usar, declarar `SegTree<L, R> st` para suportar updates e queries em posições de `L` a `R`. `L` e `R` podem inclusive ser negativos.

**Dica**: No construtor da Seg Tree, fazer `t.reserve(MAX); Lc.reserve(MAX); Rc.reserve(MAX);` pode ajudar bastante no runtime, pois aloca espaço para os vetores e evita muitas realocações durante a execução. Nesse caso, `MAX` é geralmente $\mathcal{O}(Q \cdot \log L)$, onde $Q$ é o número de queries e $L$ é o tamanho do intervalo.