#ifndef WITHLOCALRULESRSK_H
#define WITHLOCALRULESRSK_H
#pragma comment(linker, "/STACK:64000000")

#include "types.h"

std::pair<Tableau, Tableau> withLocalRulesRSK(const Permutation& perm);

#endif