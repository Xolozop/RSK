#include "geometrical.h"
#include <map>

std::pair<Tableau, Tableau> geometricalRSK(const Permutation& perm) {
    Tableau P, Q;
    std::map<size_t, size_t> skeleton; 
    std::map<size_t, size_t> permutation;
    for (size_t i = 0; i < perm.size(); i++)
        permutation.emplace(i+1, perm[i]);

    size_t i = 0;
    while (not permutation.empty()) {
        size_t mem = 0;
        while (not permutation.empty()) {
            P.resize(i+1);
            Q.resize(i+1);

            Q[i].push_back(permutation.begin()->first);
            
            size_t prev = permutation.begin()->second;
            permutation.erase(permutation.begin());

            for (auto next = permutation.begin(); next != permutation.end();) {
                    
                if (next->second < prev) {
                    skeleton.emplace(next->first, prev);
                    prev = next->second;
                    auto mem_prev = next;
                    next++;
                    permutation.erase(mem_prev);
                }

                if (next->second > prev) {
                    if (next->second == mem+1) /* ниже границы последней тени нет смысла смотреть */
                        break;
                    next++;
                }
            }
            mem = prev; 
            P[i].push_back(prev);
        }
        std::swap(permutation, skeleton);
        i++;
    }
    return std::pair<Tableau, Tableau>{P, Q};
}