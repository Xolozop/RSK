#include "classical.h"

std::pair<Tableau, Tableau> classicalRSK(const Permutation& perm) {
    Tableau P, Q;
    P.emplace_back(std::vector<size_t>{perm[0]});
    Q.emplace_back(std::vector<size_t>{1}); /* ставим первый элемент в начало таблицы */

    for (size_t i = 1; i < perm.size(); i++) {
        size_t k = 0;
        size_t x = P[k].size()-1;
        size_t a = perm[i];
        while (k < P.size()) {
            if (a > P[k][P[k].size()-1]) {
                P[k].emplace_back(a); 
                Q[k].emplace_back(i+1); /* если A - наибольший в строке элемент, добавляем A в конец */
                break;
            } else {
                if ((x < 1) || (x > P[k].size() - 1))
                    x = P[k].size() - 1;
                /* если длина строки не превышает x рассматриваем элемент, стоящей выше предыдущего */
                /* иначе ищем с конца */
                while (x > 0) {
                    if ((a < P[k][x]) && (a > P[k][x-1]))
                        break;
                    x--;
                }  /* находим индекс первого элемента, превосхдодящего A */
                std::swap(P[k][x], a);
                k++; /* выталкиваем "максимум", ставим на его место А */
            }
        }
        if (k >= P.size()) {
            P.emplace_back(std::vector<size_t>{a});
            Q.emplace_back(std::vector<size_t>{i+1});
        }
    }
    return std::pair<Tableau, Tableau>{P, Q};
}