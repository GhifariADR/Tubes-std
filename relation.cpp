#include "relation.h"


void createListrelation(listrelation &L){
    first(L)=NULL;
    /* Muhammad Ghifari Adrian
        1301194034
        IF-43-05
     */
}

r_address createrelation(g_address G,u_address U){
    r_address P;
    P=new relation;
    game(P)=G;
    user(P)=U;
    next(P)=NULL;
    return P;
    /* Muhammad Ghifari Adrian
        1301194034
        IF-43-05
     */
}

void insertrelation(r_address &P, listrelation &L){
    if(first(L)==NULL){
        first(L)=P;
    }else{
        next(P)=first(L);
        first(L)=P;
    }
    users(info(game(P)))++;
    games(info(user(P)))++;
    /* Muhammad Ghifari Adrian
        1301194034
        IF-43-05
     */
}

r_address searchrelation(u_address U,g_address G,listrelation L){
    r_address P=first(L);
    while(P!=NULL&&(user(P)!=U||game(P)!=G)){
        P=next(P);
    }
    return P;
    /* Muhammad Ghifari Adrian
        1301194034
        IF-43-05
     */
}

void deleterelationsearch(u_address &U,g_address &G,listrelation &L){
    r_address R;
    R=searchrelation(U,G,L);
    if(R!=NULL){
        deleterelation(R,L);
    }else{
        cout << "Relation has not found" << endl;
    }
    /* Muhammad Ghifari Adrian
        1301194034
        IF-43-05
     */
}

void deleterelation(r_address &P,listrelation &L){
    r_address Q=first(L);
    if(P==first(L)&&next(P)==NULL){
       first(L)=NULL;
       cout << "List menjadi kosong!" << endl;
    }else if(P==first(L)){
        first(L)=next(P);
        next(P)=NULL;
    }else{
        while(Q!=NULL&&next(Q)!=P){
            Q=next(Q);
        }
        if(Q!=NULL){
            next(Q)=next(P);
            next(P)=NULL;
        }
    }
    users(info(game(P)))--;
    games(info(user(P)))--;
    delete P;
    P=NULL;
    /* Muhammad Ghifari Adrian
        1301194034
        IF-43-05
     */
}

void usersGames(u_address P,listrelation L){
    r_address R=first(L);
    showUser(P);
    while(R!=NULL){
        if(user(R)==P){
            showGames(game(R));
        }
        R=next(R);
    }
    /* Muhammad Ghifari Adrian
        1301194034
        IF-43-05
     */
}

void gamesUser(g_address P,listrelation L){
     r_address R=first(L);
    showGames(P);
    while(R!=NULL){
        if(game(R)==P){
            showUser(user(R));
        }
        R=next(R);
    }
    /* Muhammad Ghifari Adrian
        1301194034
        IF-43-05
     */
}

void allUsersGame(listuser L,listrelation Lr){
    u_address U=first(L);
    while(U!=NULL){
        usersGames(U,Lr);
        U=next(U);
    }
    /* Muhammad Ghifari Adrian
        1301194034
        IF-43-05
     */
}

void allGamesUser(listgames L,listrelation Lr){
    g_address G=first(L);
    while(G!=NULL){
        gamesUser(G,Lr);
        G=next(G);
    }
    /* Muhammad Ghifari Adrian
        1301194034
        IF-43-05
     */
}
