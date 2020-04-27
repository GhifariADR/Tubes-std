 /* Muhammad Ghifari Adrian
    1301194034
    IF-43-05
 */
 

#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED

#include <iostream>
#include "parent.h"
#include "child.h"

#define game(P) P->game
#define user(P) P->user
#define next(P) P->next

#define first(L) L.first

using namespace std;

typedef struct relation *r_address;

struct relation {
    u_address user;
    g_address game;
    r_address next;
};

struct listrelation {
    r_address first;
};

void createListrelation(listrelation &L);

r_address createrelation(g_address G,u_address U);

void insertrelation(r_address &P, listrelation &L);

r_address searchrelation(u_address U,g_address G,listrelation L);

void deleterelationsearch(u_address &U,g_address &G,listrelation &L);

void deleterelation(r_address &P,listrelation &L);

void usersGames(u_address P,listrelation L);

void gamesUser(g_address P,listrelation L);

void allUsersGame(listuser L,listrelation Lr);

void allGamesUser(listgames L,listrelation Lr);

#endif // RELATION_H_INCLUDED
