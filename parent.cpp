#include "parent.h"

void createListgames(listgames &L){
    first(L)=NULL;
/* Muhammad Ghifari Adrian
    1301194034
    IF-43-05
*/
}

g_address creategames(infotypeG info){
    g_address P;
    P=new games;
    info(P)=info;
    info(P).users=0;
    next(P)=NULL;
    return P;
    /* Muhammad Ghifari Adrian
    1301194034
    IF-43-05
*/
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
    /* Muhammad Ghifari Adrian
    1301194034
    IF-43-05
*/
}
void deletegames(g_address &P,listgames &L){
    g_address Q=first(L);

    if(P!=NULL){
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
        cout << "Game telah dihapus" << endl;
        delete P;
        P=NULL;
    }else{
        cout << "Game tidak ditemukan" << endl;
    }
    /* Muhammad Ghifari Adrian
    1301194034
    IF-43-05
*/
}

g_address searchgames (string kode,listgames &L){
    g_address P=first(L);
    while(P!=NULL&&info(P).nama!=kode&&info(P).id!=kode){
        P=next(P);
    }
    return P;
    /* Muhammad Ghifari Adrian
    1301194034
    IF-43-05
*/
}

void showGames(g_address P){
    cout << "Nama Games\t: " << info(P).nama <<endl;
    cout << "ID Games\t: " << info(P).id <<endl;
    cout << "Jumlah pemain\t: " << info(P).users <<endl;
    cout << "Harga Games\t: " << info(P).harga << endl;
    /* Muhammad Ghifari Adrian
    1301194034
    IF-43-05
*/
}

void showAllGames(listgames L){
    int i=1;
    g_address P=first(L);

    while(P!=NULL){
        cout << i <<endl;
        showGames(P);
        i++;
        P=next(P);
    }
    /* Muhammad Ghifari Adrian
    1301194034
    IF-43-05
*/

}
