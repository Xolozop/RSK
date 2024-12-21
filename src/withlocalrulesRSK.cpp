#include "withlocalrulesRSK.h"
#include <vector>
#include <iostream>

struct Cell {
    size_t right=0, left=0, up=0, down=0;
    bool point = false;
};

std::pair<Tableau, Tableau> withLocalRulesRSK(const Permutation& perm) {
    Tableau P, Q;
    size_t n = perm.size();
    std::vector<Cell> current(n), next(n);

    // Инициализация структуры Cell
    for (size_t y = 0; y < n; y++) {
        for (size_t x = 0; x < n; x++) {
            // Установка точки на поле и изменение правого и верхнего ребра на 1(так же изменение левого ребра для х+1 и нижнего для у+1)
            if (y == perm[x] - 1) {
                current[x].point = true;
                current[x].up = 1;
                current[x].right = 1;
            } // применение правила 
            else if ((current[x].down != 0) && (current[x].left != 0) && (current[x].down == current[x].left)) {
                current[x].right = current[x].left+1;
                current[x].up = current[x].down+1;
            } else {
                current[x].right = current[x].left;
                current[x].up = current[x].down;
            }

            if (x != n-1)
                current[x+1].left = current[x].right;
            if (y != n-1)
                next[x].down = current[x].up;
            // обнова Q если y == n-1
            if (y == n-1) {
                size_t a = current[x].up;
                if (a > Q.size())
                    Q.resize(a);
                Q[a-1].push_back(x+1);
            }
        }
        // тут обнова P
        size_t a = current[n-1].right;
        if (a > P.size())
            P.resize(a);
        P[a-1].push_back(y+1);

        std::swap(current, next);

    }

    return std::pair<Tableau, Tableau>{P, Q};
}