#include "tubes.h"

void createListRelasi(ListRELATION &L) {
    first(L) = NULL;
}
void createListNOC(ListNOC &LN) {
    firstN(LN) = NULL;
}
void createListRCA(ListRCA &LR) {
    firstR(LR) = NULL;
}

adrNOC createNOC(NOC N) {
    adrNOC n = new elmNOC;
    infoN(n) = N;
    nextN(n) = NULL;
    return n;
}
adrRCA createRCA(RCA R) {
    adrRCA r = new elmRCA;
    infoR(r) = R;
    nextR(r) = NULL;
    return r;
}
void insertLastNOC(ListNOC &LN, adrNOC N) {
    if (firstN(LN) == NULL) {
        firstN(LN) = N;
    } else {
        adrNOC p = firstN(LN);
        while (nextN(p) != NULL) {
            p = nextN(p);
        }
        nextN(p) = N;
    }
}

void insertLastRCA(ListRCA &LR, adrRCA R) {
    if (firstR(LR) == NULL) {
        firstR(LR) = R;
    } else {
        adrRCA p = firstR(LR);
        while (nextR(p) != NULL) {
            p = nextR(p);
        }
        nextR(p) = R;
    }
}

void ShowAllIRCA(ListRCA LR){
    if (firstR(LR) == NULL){
        cout << "List Kosong" << endl;
    }else {
        adrRCA R = firstR(LR);
        while (R != NULL) {
            cout << "RCA_ID : " << infoR(R).RCA_ID << " || ";
            cout << "RCA_Category : " << infoR(R).RCA_Category << endl;
            R = nextR(R);
        }
        cout << endl;
    }
}

void ShowAllNOC(ListNOC LN){
    if (firstN(LN) == NULL){
        cout << "List Kosong" << endl;
    }else {
        adrNOC N = firstN(LN);
        while (N != NULL) {
            cout << "NOC_ID : " << infoN(N).NOC_ID << " || ";
            cout << "NOC_Name : " << infoN(N).NOC_Name << " || ";
            cout << "Area : " << infoN(N).Area << " || ";
            cout << "Type : " << infoN(N).Type << endl;
            N = nextN(N);
        }
        cout << endl;
    }
}

void insertLastRelasi(ListRELATION &L, adrRelasi P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        adrRelasi p = first(L);
        while (next(p) != NULL) {
            p = next(p);
        }
        next(p) = P;
    }
}
void AddTicket(ListNOC LN, ListRCA LR, NOC N, RCA R, ListRELATION &L){
    adrRelasi P = new elmRelasi;
    string Tiket;
    string status;
    string downtime;

    info(P).RCA_ID = R.RCA_ID;
    info(P).NOC_ID = N.NOC_ID;

    cout << "Masukkan No Tiket : ";
    cin >> Tiket;
    info(P).Ticket_NO = Tiket;

    cout << "Masukkan Status : ";
    cin >> status;
    info(P).Status = status;

    cout << "Masukkan Downtime : ";
    cin >> downtime;
    info(P).Downtime = downtime;
    next(P) = NULL;

    adrRCA r = firstR(LR);
    while (infoR(r).RCA_ID != info(P).RCA_ID) {
        r = nextR(r);
    }
    RCA(P) = r;

    adrNOC n = firstN(LN);
    while (infoN(n).NOC_ID != info(P).NOC_ID) {
        n = nextN(n);
    }
    NOC(P) = n;
    insertLastRelasi(L, P);
}

void ShowTicketNOC(ListRELATION L, NOC N){
    adrRelasi p = first(L);
    int jum = 0;
    while (p != NULL) {
        if (info(p).NOC_ID == N.NOC_ID) {
            cout << "No Tiket : " << info(p).Ticket_NO << " || ";
            cout << "RCA Category : " << p->RCA->infoR.RCA_Category << " || ";
            cout << "Status : " << info(p).Status<< endl;
            jum++;
        }
        p = next(p);
    }
    cout << "Jumlah : " << jum << endl;
}

void ShowNOCbySTATUS(ListRELATION L, string status){
    adrRelasi p = first(L);
    int jum = 0;
    while (p != NULL){
        if (info(p).Status == status) {
            cout << "No Tiket : " << info(p).Ticket_NO << " || ";
            cout << "ID NOC : " << info(p).NOC_ID << " || ";
            cout << "Status : " << info(p).Status<< endl;
            jum++;
        }
        p = next(p);
    }
    cout << "Jumlah : " << jum << endl;
    cout << endl;

}

void ShowStat(ListRELATION L){
    adrRelasi p;
    int i = 1;
    int jum;
    int close;
    int open;
    while (i <= 10) {
        p = first(L);
        jum = 0;
        close = 0;
        open = 0;
        cout << "ID RCA : " << i << endl;
        while (p != NULL) {
            if (info(p).RCA_ID == i){
                cout << "No Tiket : " << info(p).Ticket_NO << endl;
                jum++;
                if (info(p).Status == "CLOSED") {
                    close++;
                } else if (info(p).Status == "OPEN") {
                    open++;
                }
            }
            p = next(p);
        }
        cout << "Jumlah NOC : " << jum << endl;
        cout << "Jumlah Close : " << close << endl;
        cout << "Jumlah Open : " << open << endl;
        i++;
        cout << endl;
    }
}
