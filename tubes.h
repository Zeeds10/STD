#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) (P)->next
#define info(P) (P)->info

#define RCA(P) (P)->RCA
#define NOC(P) (P)->NOC

#define nextR(P) (P)->nextR
#define infoR(P) (P)->infoR

#define nextN(P) (P)->nextN
#define infoN(P) (P)->infoN

#define first(L) ((L).first)
#define firstR(L) ((L).firstR)
#define firstN(L) ((L).firstN)

struct RCA {
    int RCA_ID;
    string RCA_Category;
};

struct NOC {
    int NOC_ID;
    string NOC_Name;
    string Area;
    string Type;
};

typedef NOC infoNOC;
typedef RCA infoRCA;

typedef struct elmNOC *adrNOC;
typedef struct elmRCA *adrRCA;

struct elmNOC {
    infoNOC infoN;
    adrNOC nextN;
};

struct elmRCA {
    infoRCA infoR;
    adrRCA nextR;
};

struct Relasi {
    string Ticket_NO;
    int RCA_ID;
    int NOC_ID;
    string Status;
    string Downtime;
};

typedef struct elmRelasi *adrRelasi;
typedef Relasi infoRelasi;

struct elmRelasi {
    infoRelasi info;
    adrRelasi next;
    adrNOC NOC;
    adrRCA RCA;
};

struct ListRELATION {
    adrRelasi first;
};

struct ListNOC {
    adrNOC firstN;
};

struct ListRCA {
    adrRCA firstR;
};

void createListRelasi(ListRELATION &L);
void createListNOC(ListNOC &LN);
void createListRCA(ListRCA &LR);
adrNOC createNOC(NOC N);
adrRCA createRCA(RCA R);
void insertLastNOC(ListNOC &LN, adrNOC N);
void insertLastRCA(ListRCA &LR, adrRCA R);
void ShowAllIRCA(ListRCA LR);
void ShowAllNOC(ListNOC LN);
void AddTicket(ListNOC LN, ListRCA LR, NOC N, RCA R, ListRELATION &L);
void insertLastRelasi(ListRELATION &L, adrRelasi P);
void ShowTicketNOC(ListRELATION L, NOC N);
void ShowNOCbySTATUS(ListRELATION L, string status);
void ShowStat(ListRELATION L);


#endif // TUBES_H_INCLUDED
