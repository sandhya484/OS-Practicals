#include<iostream>
using namespace std;

int main() {

    int n, at[10], bt[10], ct[10], tat[10], wt[10];

    cout<<"Enter number of processes: ";
    cin>>n;

    for(int i=0;i<n;i++) {
        cout<<"Enter AT and BT: ";
        cin>>at[i]>>bt[i];
    }

    ct[0] = at[0] + bt[0];

    for(int i=1;i<n;i++) {
        ct[i] = ct[i-1] + bt[i];
    }

    for(int i=0;i<n;i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    cout<<"\nAT\tBT\tCT\tTAT\tWT\n";

    for(int i=0;i<n;i++) {
        cout<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]
        <<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
    }

    return 0;
}
