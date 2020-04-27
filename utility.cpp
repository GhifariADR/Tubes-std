#include "utility.h"
#include <cstdlib>

void menu(listgames &Lg,listrelation &Lr,listuser &Lu){
    int pilih;

    do{
        system("cls");
        cout << "|=======================|" << endl;
        cout << "|WELCOME TO 05-GAMESTORE|" << endl;
        cout << "|=======================|" << endl;
        cout << "|(0) Exit               |" << endl;
        cout << "|(1) User baru          |" << endl;
        cout << "|(2) Game baru          |" << endl;
        cout << "|(3) Isi saldo user     |" << endl;
        cout << "|(4) Beli game          |" << endl;
        cout << "|(5) Jual game          |" << endl;
        cout << "|(6) Hapus user         |" << endl;
        cout << "|(7) Hapus game         |" << endl;
        cout << "|(8) Lihat info user    |" << endl;
        cout << "|(9) Lihat info game    |" << endl;
        cout << "|(10)Lihat semua users  |" << endl;
        cout << "|(11)Lihat semua games  |" << endl;
        cout << "|(12)Semua user & games |" << endl;
        cout << "|=======================|" << endl;
        cout << "====Pilih -> ";
        cin >> pilih;
        switch(pilih){
        case 1:
            inputUser(Lu);
            break;
        case 2:
            inputGame(Lg);
            break;
        case 3:
            isiSaldo(Lu);
            break;
        case 4:
            buyGames(Lr,Lg,Lu);
            break;
        case 5:
            sellGames(Lr,Lg,Lu);
            break;
        case 6:
            deletinguser(Lu);
            break;
        case 7:
            deletinggames(Lg);
            break;
        case 8:
            cariUser(Lu,Lr);
            break;
        case 9:
            cariGame(Lg,Lr);
            break;
        case 10:
            showAllUser(Lu);
            break;
        case 11:
            showAllGames(Lg);
            break;
        case 12:
            allUsersGame(Lu,Lr);
            break;
        }
        system("pause");
    }while(pilih!=0);
}

void mostPlayedGames(listgames L,listrelation Lr){
    g_address G=first(L);
    int Max=users(info(G));

    while(G!=NULL){
        if(users(info(G))>Max){
            Max=users(info(G));
        }
        G=next(G);
    }

    G=first(L);
    while(G!=NULL){
        if(users(info(G))==Max){
            gamesUser(G,Lr);
        }
        G=next(G);
    }

}

void inputUser(listuser &L){
    u_address U;
    infotypeU info;
    cout << "Nama User\t: ";
    cin >> info.nama;
    cout << "ID User\t: ";
    cin >> info.id;
    info.saldo=0;
    U=createuser(info);
    insertuser(U,L);
}

void inputGame(listgames &L){
    g_address G;
    infotypeG info;
    cout << "Nama Game\t: ";
    cin >> info.nama;
    cout << "ID Game\t: ";
    cin >> info.id;
    cout << "Harga Game\t: ";
    cin >> info.harga;
    G=creategames(info);
    insertgames(G,L);
}

void isiSaldo(listuser L){
    string kode;
    int saldo;
    u_address U;

    cout << "ID/nama user\t: ";
    cin >> kode;
    U=searchuser(kode,L);
    if(U!=NULL){
        cout << "Tambah saldo\t: ";
        cin >> saldo;
        if(saldo>0){
            saldo(info(U))=saldo(info(U))+saldo;
        }else{
            cout << "Ada yang salah..." <<endl;
        }
    }else{
        cout << "Nama/ID tidak terdaftar" << endl;
    }
}

void buyGames(listrelation &L,listgames Lg,listuser Lu){
    u_address U;
    g_address G;
    r_address R;
    int pilihan=0;
    string kode;

    cout << "ID/nama user\t: ";
    cin >> kode;
    U=searchuser(kode,Lu);
    if(U!=NULL){
        showUser(U);
        cout << "ID/nama game\t: ";
        cin >> kode;
        G=searchgames(kode,Lg);
        if(G!=NULL){
            showGames(G);
            if(harga(info(G))<=saldo(info(U))){
                while(pilihan!=1&&pilihan!=2){
                    cout << "(1) Beli game" << endl;
                    cout << "(2) Tidak beli" << endl;
                }
                if(pilihan==1){
                    saldo(info(U))=saldo(info(U))-harga(info(G));
                    R=createrelation(G,U);
                    insertrelation(R,L);
                }
            }else{
                cout << "Saldo tidak cukup untuk membeli" << endl;
            }
        }else{
            cout << "Games tidak terdaftar" << endl;
        }
    }else{
        cout << "User tidak terdaftar" << endl;
    }
}

void sellGames(listrelation &L,listgames Lg,listuser Lu){
    u_address U;
    g_address G;
    r_address R;
    int pilihan=0;
    string kode;

    cout << "ID/nama user\t: ";
    cin >> kode;
    U=searchuser(kode,Lu);
    if(U!=NULL){
        showUser(U);
        cout << "ID/nama game\t: ";
        cin >> kode;
        G=searchgames(kode,Lg);
        if(G!=NULL){
            R=searchrelation(U,G,L);
            if(R!=NULL){
                showGames(G);
                while(pilihan!=1&&pilihan!=2){
                    cout << "(1) Jual game" << endl;
                    cout << "(2) Tidak jadi" << endl;
                }
                if(pilihan==1){
                    saldo(info(U))=saldo(info(U))+harga(info(G));
                    deleterelationsearch(U,G,L);
                }
            }else{
                cout << "Game tidak dibeli user" << endl;
            }
        }else{
            cout << "Games tidak terdaftar" << endl;
        }
    }else{
        cout << "User tidak terdaftar" << endl;
    }
}

void cariUser(listuser Lu,listrelation Lr){
    u_address U;
    string kode;
    cout << "Cari nama/id user : ";
    cin >> kode;
    U=searchuser(kode,Lu);

    if(U!=NULL){
        usersGames(U,Lr);
    }

}

void cariGame(listgames Lg,listrelation Lr){
    g_address G;
    string kode;
    cout << "Cari nama/id user : ";
    cin >> kode;
    G=searchgames(kode,Lg);

    if(G!=NULL){
        gamesUser(G,Lr);
    }
}

void deletinggames(listgames &L){
    g_address P;
    string kode;

    cout << "ID/Nama games : ";
    cin >> kode;
    P=searchgames(kode,L);
    deletegames(P,L);
}

void deletinguser(listuser &L){
    u_address P;
    string kode;

    cout << "ID/Nama user : ";
    cin >> kode;
    P=searchuser(kode,L);
    deleteuser(P,L);
}
