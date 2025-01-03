#include <iostream>
#include <fstream>
#include <ctime>

#include "types.h"
#include "classical.h"
#include "geometrical.h"
#include "withlocalrulesRSK.h"

Permutation getRandomPermutation(const Permutation& perm, const size_t n) {
    Permutation newPerm = perm;
    srand(time(0));
    for (size_t i = n-1; i > 0; i--) {
        size_t j = std::rand()%i;
        std::swap(newPerm[j], newPerm[i]);
    }
    return newPerm;
}

void writeToFile(Permutation permutation, std::pair<Tableau, Tableau> ans, std::string filename) {
    std::ofstream out;
    out.open(filename);
    if (!out.is_open()) {
        out.close();
        return;
    }
    out << "Permutation:" << std::endl << '\t';
    for (size_t i = 0; i < permutation.size(); i++)
        out << i+1 << ' ';
    out << std::endl << '\t';
    for (size_t i = 0; i < permutation.size(); i++)
        out << permutation[i] << ' ';
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
}

bool isEqual(std::pair<Tableau, Tableau> ans1, std::pair<Tableau, Tableau> ans2) {
    for (int x = ans1.first.size()-1; x >= 0; x--) {
        for (int y = 0; y < ans1.first[x].size(); y++) {
            try {
                if (ans1.second[x][y] != ans2.second[x][y])
                    return false;
            } catch (std::exception& e) {
                return false;
            }
        }
    }

    for (int x = ans1.second.size()-1; x >= 0; x--) {
        for (int y = 0; y < ans1.second[x].size(); y++) {
            try {
                if (ans1.second[x][y] != ans2.second[x][y])
                    return false;
            } catch (std::exception& e) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    /* создаём случайную перестановку */
    size_t n = 10000;
    Permutation base;
    for (size_t i = 0; i < n; i++) {
        base.push_back(i+1);
    }
    Permutation permutation = getRandomPermutation(base, n);
    //Permutation permutation = {3, 1, 6, 10, 2, 5, 8, 4, 9, 7}; // для примера Вьенно
    //Permutation permutation = {6, 1, 7, 2, 5, 8, 3, 9, 4};     // для геометрического примера Вьенно
    //Permutation permutation = {5, 8, 1, 9, 6, 4, 10, 3, 7, 2}; // для примера
    //Permutation permutation = {7, 5, 1, 2, 6, 4, 3};
    //Permutation permutation = {4, 2, 1, 5, 3};

    /* классичесский RSK + вычисление времени */
    time_t start, end;
    start = clock();
    std::pair<Tableau, Tableau> classicalAns = classicalRSK(permutation);
    end = clock();
    double classicalSeconds = (double)(end - start)/CLOCKS_PER_SEC;

    /* геометрическая конструкция Вьенно + вычисление времени */
    start = clock();
    std::pair<Tableau, Tableau> geometricalAns = geometricalRSK(permutation);
    end = clock();
    double geometricalSeconds = (double)(end - start)/CLOCKS_PER_SEC;

    /* с локальными правилами */
    start = clock();
    std::pair<Tableau, Tableau> withLocalRulesAns = withLocalRulesRSK(permutation);
    end = clock();
    double withLocalRulesSeconds = (double)(end - start)/CLOCKS_PER_SEC;

    std::cout << "Затрачено времени на классический ускоренный RSK: " << std::fixed << classicalSeconds << " секунд" << std::endl;
    std::cout << "Затрачено времени на геометрический RSK: " << std::fixed << geometricalSeconds << " секунд" << std::endl;
    std::cout << "Затрачено времени на RSK с локальными правилами на рёбрах: " << std::fixed << withLocalRulesSeconds << " секунд" << std::endl;
    
    /* запись в файл результата */
    if (n < 1000) {
        writeToFile(permutation, classicalAns, "results/classical.txt");
        writeToFile(permutation, geometricalAns, "results/geometrical.txt");
        writeToFile(permutation, withLocalRulesAns, "results/local_rules.txt");
    }

    bool equivalence = isEqual(classicalAns, geometricalAns);
    equivalence *= isEqual(classicalAns, withLocalRulesAns);

    std::cout << "\t~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "Полученные разными способами таблицы Юнга ";
    std::cout << (equivalence ? "эквивалентны!" : "не эквивалентны...") << std::endl;
    return 0;
}