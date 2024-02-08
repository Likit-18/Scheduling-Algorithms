#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct process{
    string process_id;
    int bt,ct,tat,wt;
    int exe_time;
};

int main(){
    int n;
    queue<process> queue;
    cout<<"Enter the number of processes"<<endl;
    cin >> n;

    int tq;
    cout<<"Enter the time quantum : ";
    cin>>tq;

    vector <process> ans;
    for (int i=0; i<n; i++){
        process temp;
        cin >> temp.process_id >> temp.bt;
        temp.exe_time = temp.bt;
        queue.push(temp);
    }

    float sum_tat = 0;
    float sum_wt = 0;
    int time = 0;
    
    while(!queue.empty()){  
        process top = queue.front();
        queue.pop();
        if(top.exe_time > tq){
            top.exe_time -= tq;
            time += tq;
            queue.push(top);
        }else{
            time += top.exe_time;
            top.exe_time = 0;
            top.ct = time;
            top.tat = top.ct;
            sum_tat += top.tat;
            top.wt = top.tat - top.bt;
            sum_wt += top.wt;
            ans.push_back(top);
        }
    }

    cout<<"Process_id\tburst time\tturn around time\twaiting time\n";
    cout<<"----------\t----------\t----------------\t------------\n";

    for(auto item : ans){
        cout<<item.process_id<<"\t\t"<<item.bt<<"\t\t"<<item.tat<<"\t\t\t"<<item.wt<<endl;
    }
    cout<<"Average tat: "<<float(sum_tat/n)<<endl;
    cout<<"Average wt: "<<float(sum_wt/n)<<endl;
}