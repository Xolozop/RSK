#include "geometrical.h"

typedef struct coords {
    size_t n;
    size_t x;
    size_t y;
} coords;

std::pair<Tableau, Tableau> geometricalRSK(const Permutation& perm) {
    std::vector<size_t> YamanuchiP;
    YamanuchiP.resize(perm.size(), 0);
    std::vector<size_t> YamanuchiQ;
    YamanuchiQ.resize(perm.size(), 0);
    std::vector<coords> skeleton; 
    for (size_t i = 0; i < perm.size(); i++) {
        skeleton.push_back(coords{1, i+1, perm[i]});
    }

    int max = 1;
    coords mem = {0,0,0};
    while (not skeleton.empty()) {
        coords c = skeleton.front();
        skeleton.erase(skeleton.begin());

        YamanuchiQ[c.x-1] = c.n;
        mem.x = c.x;

        size_t i = 0;
        while (not skeleton.empty()) {
            coords el = skeleton[i];
            if (el.n != c.n)
                break;

            if (el.y < c.y) { /* если скелетон находится правее и ниже предыдущего */
                size_t j = 1;
                while (j < skeleton.size() && skeleton[skeleton.size()-j].n == el.n+1) {
                    if (el.x > skeleton[skeleton.size()-j].x)
                        break;
                    j++;
                }
                skeleton.insert(skeleton.end()-j+1, coords{el.n+1, el.x, c.y});
                
                if (el.n+1 > max)
                    max = el.n+1;
                skeleton.erase(skeleton.begin() + i);
                c = el;
                i--;
            }
            if ((el.n == mem.n && el.y == mem.y+1) || el.x == perm.size())
                break;
            i++;
        }

        mem.y = c.y;
        mem.n = c.n;
        YamanuchiP[mem.y-1] = YamanuchiQ[mem.x-1];
    }

    /* Строим таблицы P и Q по получившимся словам Яманучи: */
    Tableau P, Q;
    P.resize(max, std::vector<size_t>(0));
    Q.resize(max, std::vector<size_t>(0));
    for (int i = 0; i < perm.size(); i++) {
        P[YamanuchiP[i]-1].push_back(i+1);
        Q[YamanuchiQ[i]-1].push_back(i+1);
    }
    
    return std::pair<Tableau, Tableau>{P, Q};
}
