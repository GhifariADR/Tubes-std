#include "parent.h"

void createListgames(listgames &L){
    first(L)=NULL;
}

g_address creategames(infotypeG info){
    g_address P;
    P=new games;
    info(P)=info;
    info(P).users=0;
    next(P)=NULL;
    return P;
}

void insertgames(g_address &P, listgames &L){
    g_address G;
    G=searchgames((info(P)).id,L);
    if(G==NULL){
        if(first(L)==NULL){
            first(L)=P;
        }else{
            next(P)=first(L);
            first(L)=P;
        }
    }else{
        cout << "Duplication ID Detected" << endl;
        cout << "Deallocate Game" << endl;
        delete P;
        P=NULL;
    }
}
