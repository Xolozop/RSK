#include <vector>

#include "classical.h"

std::pair<Tableau, Tableau> slowClassicalRSK(const Permutation& perm) {
    Tableau P, Q;
    P.emplace_back(std::vector<size_t>{perm[0]});
    Q.emplace_back(std::vector<size_t>{1});       /* ставим первый элемент в начало таблицы */

    for (size_t i = 1; i < perm.size(); i++) {
        size_t k = 0;
        size_t a = perm[i];
        while (k < P.size()) {
            if (a > P[k][P[k].size()-1]) {
                P[k].emplace_back(a);   /* если A - наибольший в строке элемент, добавляем A в конец */
                Q[k].emplace_back(i+1);
                break;
            } else { 
                size_t x = 0;
                while(a > P[k][x]) 
                    x++; /* находим индекс первого превосхдодящего A элемента */
                size_t n = P[k][x];
                P[k][x] = a; 
                a = n;                  /* выталкиваем "максимум" */
                k++;
            }
        }

        if (k >= P.size()) {
            P.emplace_back(std::vector<size_t>{a});
            Q.emplace_back(std::vector<size_t>{i+1});
        }
    }

    return std::pair<Tableau, Tableau>{P, Q};
}
