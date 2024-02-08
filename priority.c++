#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct process{
    string process_id;
    int prior,bt,ct,tat,wt;
};

class compare{
    public:
    bool operator() (process a, process b){
        if(a.prior == b.prior){
            return a.process_id[1] > b.process_id[1];
        }
        return a.prior > b.prior;
    }
};

int main(){
    int n;
    priority_queue <process, vector<process> , compare> heap;
    cout<<"Enter the number of processes"<<endl;
    cin >> n;

    vector <process> ans;
    for (int i=0; i<n; i++){
        process temp;
        cin >> temp.process_id >> temp.bt >> temp.prior;
        heap.push(temp);
    }

    float sum_tat = 0;
    float sum_wt = 0;
    int time = 0;
    for(int i=0; i<n; i++){
        process top = heap.top();
        heap.pop();
        time += top.bt;
        top.tat = time;
        top.wt = top.tat - top.bt;

        sum_tat += top.tat;
        sum_wt += top.wt;
        ans.push_back(top);
    }

    cout<<"Process_id\tburst time\tpriority\tturn around time\twaiting time\n";
    cout<<"----------\t----------\t--------\t----------------\t------------\n";

    for(auto item : ans){
        cout<<item.process_id<<"\t\t"<<item.bt<<"\t\t"<<item.prior<<"\t\t"<<item.tat<<"\t\t\t"<<item.wt<<endl;
    }
    cout<<"Average tat:"<<(sum_tat/float(n))<<endl;
    cout<<"Average wt:"<<(sum_wt/float(n))<<endl;
}