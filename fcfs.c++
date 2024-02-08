#include<iostream>
#include<string>
using namespace std;

// Without arrival time
int main(){
    int n;
    cin >> n;
    int bt[n] , ct[n] , tat[n] , rt[n] , wt[n];
    string process[n];
    for(int i=0; i<n; i++){
        cin >> process[i] >> bt[i];
    }

    float sum_tat = 0;
    float sum_wt = 0;

    int time = 0;
    for(int i=0; i<n; i++){
        time += bt[i];
        ct[i] = time;
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
        sum_tat += tat[i];
        sum_wt += wt[i];
    }
    cout<<"Process_id\tburst time\tturn around time\twaiting time\n";
    cout<<"----------\t----------\t----------------\t------------\n";

    for(int i=0; i<n; i++){
        cout<<process[i]<<"\t\t"<<bt[i]<<"\t\t"<<tat[i]<<"\t\t\t"<<wt[i]<<endl;
    }
    cout<<"Average tat:"<<sum_tat/n<<endl;
    cout<<"Average wt:"<<sum_wt/n<<endl;
}