#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

#include "types.h"
#include "classical.h"

Permutation getRandomPermutation(const Permutation& perm, const size_t n) {
    Permutation newPerm = perm;
    srand(time(0));
    for (size_t i = n-1; i > 0; i--) {
        size_t j = std::rand()%i;
        size_t c = newPerm[j];
        newPerm[j] = newPerm[i];    /* swap(p[i], p[j])*/
        newPerm[i] = c;
    }
    return newPerm;
}

int main() {
    /* создаём случайную пеерстановку */
    Permutation permutation;
    size_t n = 100000;
    for (size_t i = 0; i < n; i++)
        permutation.emplace_back(i+1);
    Permutation permutation2 = getRandomPermutation(permutation, n);
    //Permutation permutation2 = {3, 1, 6, 10, 2, 5, 8, 4, 9, 7}; // для примера Вьенно
    //Permutation permutation2 = {5, 8, 1, 9, 6, 4, 10, 3, 7, 2}; // для примера

    /* классичесский RSK + вычисление времени */
    clock_t start = clock();
    std::pair<Tableau, Tableau> ans = classicalRSK(permutation2);
    clock_t end = clock();
    double classical_seconds = (double)(end - start)/CLOCKS_PER_SEC;

    std::cout << "Затрачено времени на классический RSK: " << std::fixed << classical_seconds << " секунд" << std::endl;

    /* запись в файл результата */
    if (n > 1000)
        return 0;
    std::ofstream out;
    out.open("result.txt");
    if (!out.is_open()) {
        out.close();
        return 0;
    }
    out << "Permutation:" << std::endl << '\t';
    for (size_t i = 0; i < n; i++)
        out << permutation[i] << ' ';
    out << std::endl << '\t';
    for (size_t i = 0; i < n; i++)
        out << permutation2[i] << ' ';
    out << std::endl;

    Tableau P = ans.first;
    Tableau Q = ans.second;
    out << "P:" << std::endl;
    for (int x = P.size()-1; x >= 0; x--) {
        out << '\t';
        for (int y = 0; y < P[x].size(); y++) {
            out << P[x][y] << ' ';
        }
        out << std::endl;
    }
    out << "Q:" << std::endl;
    for (int x = Q.size()-1; x >= 0; x--) {
        out << '\t';
        for (int y = 0; y < Q[x].size(); y++) {
            out << Q[x][y] << ' ';
        }
        out << std::endl;
    }
    out.close();
    return 0;
}