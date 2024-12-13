#include <map>

#include "geometrical.h"

std::pair<Tableau, Tableau> geometricalRSK(const Permutation& perm) {
    Tableau P, Q;
    std::map<size_t, size_t> permutation;
    std::map<size_t, size_t> skeleton; 
    for (size_t i = 0; i < perm.size(); i++)
        permutation.emplace(i+1, perm[i]); /* расставление "точек" в соответствии с координатами (j; σ(j)) */

    size_t i = 0; /* порядок скелета */
    while (not permutation.empty()) { /* скелет нового порядка строится до тех пор, пока это возможно */
        size_t mem = permutation.begin()->second;
        while (not permutation.empty()) { /* построение теней для текущей квази-перестановки (порядка i) */
            P.resize(i+1);
            Q.resize(i+1);

            Q[i].push_back(permutation.begin()->first); 
            /* порядок и индекс крайней левой точки тени соответствует положению и значению в таблице Q */
            
            size_t prev = permutation.begin()->second;
            permutation.erase(permutation.begin());
            /* извлекаем значение σ(j) и строим от него непрерывную тень,
               для этого перебираем значения точек, лежащих правее текущей;
               точки с меньшим значением -- подходящие */

            bool calculate = true;
            for (auto next = permutation.begin(); next != permutation.end();) {
                if (next->second == mem+1) { /* ниже границы последней тени нет смысла смотреть */
                    mem = next->second;
                    calculate = false;
                }

                if (next->second < prev) { /* подходящая точка для построения тени */
                    skeleton.emplace(next->first, prev); /* инициализация новой точки скелета */
                    prev = next->second;
                    auto mem_prev = next;
                    next++;
                    permutation.erase(mem_prev);
                } else {
                    next++;
                }
            }
            P[i].push_back(prev); /* порядок и индекс крайней нижней точки тени соответствует положению и значению в таблице Q */
        }
        std::swap(permutation, skeleton); /*  повторяем цикл до тех пор, пока у скелета есть скелет */
        i++;
    }
    return std::pair<Tableau, Tableau>{P, Q};
}