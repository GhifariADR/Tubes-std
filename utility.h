#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include "relation.h"

using namespace std;

void menu(listgames &Lg,listrelation &Lr,listuser &Lu);

void mostPlayedGames(listgames L,listrelation Lr);

void inputUser(listuser &L);

void inputGame(listgames &L);

void isiSaldo(listuser L);

void buyGames(listrelation &L,listgames Lg,listuser Lu);

void sellGames(listrelation &L,listgames Lg,listuser Lu);

void cariUser(listuser Lu,listrelation Lr);

void cariGame(listgames Lg,listrelation Lr);

void deletinggames(listgames &L);

void deletinguser(listuser &L);

#endif // UTILITY_H_INCLUDED
