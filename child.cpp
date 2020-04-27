#include "child.h"
/*
    Hazim Ismai
    IF-43-05
    1301194149

*/

void createListuser(listuser &L){
    /*
    Hazim Ismai
    IF-43-05
    1301194149

*/
    first(L)=NULL;
}

u_address createuser(infotypeU info){
    /*
    Hazim Ismai
    IF-43-05
    1301194149

*/
    u_address P;
    P=new user;
    info(P)=info;
    info(P).games=0;
    next(P)=NULL;
    return P;
}

void insertuser(u_address &P, listuser &L){
    /*
    Hazim Ismai
    IF-43-05
    1301194149

*/
    u_address U;
    U=searchuser((info(P)).id,L);
    if(U==NULL){
        if(first(L)==NULL){
            first(L)=P;
        }else{
            next(P)=first(L);
            first(L)=P;
        }
    }else{
        cout << "Duplication ID Detected" << endl;
        cout << "Deallocate User" << endl;
        delete P;
        P=NULL;
    }
}

void deleteuser(u_address &P,listuser &L){
    /*
    Hazim Ismai
    IF-43-05
    1301194149

*/
    u_address Q=first(L);

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
        cout << "User telah dihapus" << endl;
        delete P;
        P=NULL;
    }else{
        cout << "User tidak ditemukan" << endl;
    }
}

u_address searchuser (string kode,listuser L){
    /*
    Hazim Ismai
    IF-43-05
    1301194149

*/
    u_address P=first(L);
    while(P!=NULL&&info(P).nama!=kode&&info(P).id!=kode){
        P=next(P);
    }
    return P;
}

void showUser(u_address P){
    /*
    Hazim Ismai
    IF-43-05
    1301194149

*/
    cout << "Nama User\t: " << info(P).nama <<endl;
    cout << "ID User\t: " << info(P).id <<endl;
    cout << "Jumlah games\t: " << info(P).games <<endl;
    cout << "Saldo\t\t: "<<info(P).saldo << endl;
}

void showAllUser(listuser L){
    /*
    Hazim Ismai
    IF-43-05
    1301194149

*/
    int i=1;
    u_address P=first(L);

    while(P!=NULL){
        cout << i <<endl;
        showUser(P);
        i++;
        P=next(P);
    }

}
