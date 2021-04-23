#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>

using namespace std;

vector<string> answer;
vector<string> result;
int len;
bool used[10000] = {false, };
bool stopFlog = false;

void printVector(vector<string> a){
    cout << "===========================" << endl;
    for(int i=0;i<a.size();i++){
        cout << a[i] << "->";
    }
    cout << endl;
}

void recursiveBFS(vector<vector<string>> &tickets, string start)
{
    // base condition
    if(stopFlog) return;
    if(answer.size() == len){
        answer.push_back(start);
        result = answer;
        stopFlog = true;
        return;
    }
    
    for(int i=0;i<len;i++){
        if(tickets[i][0] == start && used[i] == false){
            used[i] = true;
            answer.push_back(tickets[i][0]);
            recursiveBFS(tickets, tickets[i][1]);
            answer.pop_back();
            used[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    string start = "ICN";
    len = tickets.size();
    sort(tickets.begin(), tickets.end());

    recursiveBFS(tickets, start);
    
    
    return result;

}

int main(int argc, char* argv[]){

    vector<string> a;
    vector<vector<string>> input_data;




    a.push_back("ICN");
    a.push_back("JFK");

    input_data.push_back(a);
    a.clear();

    a.push_back("HND");
    a.push_back("IAD");

    input_data.push_back(a);
    a.clear();

    a.push_back("JFK");
    a.push_back("HND");

    input_data.push_back(a);
    a.clear();

    a = solution(input_data);

    vector<string>::iterator iter;

    for (iter = a.begin(); iter != a.end(); iter++) {
        cout << *iter << " -> ";
    }
    
    return 0;
}
