#include <iostream>
#include "tubes.h"
using namespace std;

int main()
{
    ListNOC LN;
    createListNOC(LN);
    ListRCA LR;
    createListRCA(LR);
    ListRELATION L;
    createListRelasi(L);
    NOC N;
    RCA R;
    adrRCA pR;
    adrNOC pN;
    adrRelasi p;
    int i;
    for (i = 1; i <= 10; i++) {
        R.RCA_ID = i;
        cout << "Masukkan RCA Category : ";
        cin >> R.RCA_Category;
        pR = createRCA(R);
        cout << "RCA_ID : " << infoR(pR).RCA_ID << " || ";
        cout << "RCA_Category : " << infoR(pR).RCA_Category << endl;
        cout << endl;
        insertLastRCA(LR, pR);
    }
    cout << "============================================================================================== \n" << endl;
    cout << "Procedure ShowAllRCA\n" << endl;
    ShowAllIRCA(LR);
    cout << "==============================================================================================" << endl;
    for (i = 1; i <= 10; i++) {
        N.NOC_ID = i;
        cout << "\nMasukkan NOC Name : ";
        cin >> N.NOC_Name;
        cout << "Masukkan NOC Area : ";
        cin >> N.Area;
        cout << "Masukkan NOC Type : ";
        cin >> N.Type;
        pN = createNOC(N);
        insertLastNOC(LN, pN);
        cout << "NOC_ID : " << infoN(pN).NOC_ID << " || ";
        cout << "NOC_Name : " << infoN(pN).NOC_Name << " || ";
        cout << "Area : " << infoN(pN).Area << " || ";
        cout << "Type : " << infoN(pN).Type << endl;
        cout << endl;
    }
    cout << "==============================================================================================\n" << endl;
    cout << "Procedure ShowAllNOC\n" << endl;
    ShowAllNOC(LN);
    cout << "==============================================================================================" << endl;
    cout << "\nProcedure AddTicket" << endl;
    for (i = 1; i <= 26; i++) {
        cout << "\nMasukkan RCA ID : ";
        cin >> R.RCA_ID;
        cout << "Masukkan NOC ID : ";
        cin >> N.NOC_ID;
        AddTicket(LN, LR, N, R, L);
        p = first(L);
        while (next(p) != NULL) {
            p = next(p);
        }
        cout << "Ticket_NO : " << info(p).Ticket_NO << " || ";
        cout << "RCA_ID : " << info(p).RCA_ID << " || ";
        cout << "NOC_ID : " << info(p).NOC_ID << " || ";
        cout << "Status : " << info(p).Status << " || ";
        cout << "Downtime : " << info(p).Downtime << endl;
        cout << endl;
    }
    cout << "==============================================================================================" << endl;
    cout << "\nProcedure ShowTicketNOC\n" << endl;
    for (i = 1; i <= 10; i++) {
        N.NOC_ID = i;
        ShowTicketNOC(L, N);
        cout << endl;
    }
    cout << "==============================================================================================" << endl;
    cout << endl;
    string status;
    status = "OPEN";
    cout << "Procedure ShowNOCbySTATUS (Status OPEN)\n" << endl;
    ShowNOCbySTATUS(L, status);
    cout << endl;
    status = "CLOSED";
    cout << "Procedure ShowNOCbySTATUS (Status CLOSED)\n" << endl;
    ShowNOCbySTATUS(L, status);
    cout << "==============================================================================================" << endl;
    ShowStat(L);
    cout << "==============================================================================================" << endl;
    return 0;
}
