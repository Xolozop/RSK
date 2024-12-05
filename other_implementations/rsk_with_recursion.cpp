#include <vector>
#include <algorithm>

#include "classical.h"

size_t push(Tableau& P, size_t a, size_t k) {
    if (k >= P.size()) {
        P.emplace_back(std::vector<size_t>{a}); /* если была достигнута "вершина" таблицы, A вставляется в её конец */
        return k;
    }

    if (a > P[k][P[k].size()-1]) {
        P[k].emplace_back(a);   /* если A - наибольший в строке элемент, добавляем A в конец */
    } else {
        size_t x = 0;
        while(a > P[k][x]) x++; /* находим индекс первого превосхдодящего A элемента */
        size_t n = P[k][x];     
        P[k][x] = a;            /* выталкиваем "максимум" */
        k = push(P, n, k+1);    /* пытаемся вставить "максимум" в k+1 строку */
    }
    return k;
}

std::pair<Tableau, Tableau> classicalRSK(const Permutation& perm) {
    Tableau P, Q;
    P.emplace_back(std::vector<size_t>{perm[0]});
    Q.emplace_back(std::vector<size_t>{1});       /* ставим первый элемент в начало таблицы */
    for (size_t i = 1; i < perm.size(); i++) {
        size_t k = push(P, perm[i], 0);
        if (k >= Q.size()) {
            Q.emplace_back(std::vector<size_t>{i+1});
        } else {
            Q[k].emplace_back(i+1);
        }   /* обновляем таблицу записей Q */
    }
    return std::pair<Tableau, Tableau>{P, Q};
}
