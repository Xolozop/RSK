#include <vector>

#include "classical.h"

std::pair<Tableau, Tableau> classicalRSK(const Permutation& perm) {
    Tableau P, Q;
    P.emplace_back(std::vector<size_t>{perm[0]});
    Q.emplace_back(std::vector<size_t>{1});       /* ставим первый элемент в начало таблицы */

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
                if (a < P[k][0]) {
                    x = 0;
                    /* если первый элемент строки больше числа рассматривать с конца не имеет смысла*/
                } else {
                    x = (x < P[k].size()-1) ? x-1 : P[k].size()-1;
                    /* если длина строки не превышает x рассматриваем элемент слева сверху от предыдущего */
                    /* иначе ищем с конца */
                    while (a < P[k][x] && x > 0)
                        x--;
                    x++; /* находим индекс первого элемента, превосхдодящего A */
                }
                size_t n = P[k][x];
                P[k][x] = a; 
                a = n; 
                k++;    /* выталкиваем "максимум", ставим на его место А */
            }
        }
        if (k >= P.size()) {
            P.emplace_back(std::vector<size_t>{a});
            Q.emplace_back(std::vector<size_t>{i+1});
        }
    }
    return std::pair<Tableau, Tableau>{P, Q};
}