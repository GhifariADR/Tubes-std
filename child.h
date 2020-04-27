#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>

#define info(P) P->info
#define next(P) P->next

#define first(L) L.first
#define games(U) U.games
#define saldo(U) U.saldo
/*
    Hazim Ismai
    IF-43-05
    1301194149

*/

using namespace std;

typedef struct user *u_address;

struct infotypeU{
    string nama,id;
    int games,saldo;
};

struct user {
    infotypeU info;
    u_address next;
};

struct listuser {
    u_address first;
};

void createListuser(listuser &L);

u_address createuser(infotypeU info);

void insertuser(u_address &P, listuser &L);

void deleteuser(u_address &P,listuser &L);

u_address searchuser (string kode,listuser L);

void showUser(u_address P);

void showAllUser(listuser L);

#endif // CHILD_H_INCLUDED
