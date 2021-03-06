#include <bits/stdc++.h>

using namespace std;

vector<double> runningMedian(vector<int> arr) {
    priority_queue<double> s;
    priority_queue<double, vector<double>, greater<double>> g;
    vector<double> all_medians;
    double med = arr[0];
    all_medians.push_back(arr[0]);
    s.push(arr[0]);
    for(int i=1; i<arr.size(); i++){
        double x = arr[i];
        if(s.size() > g.size()){
            if(x < med){
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);
            med = (s.top() + g.top())/2.0;
        }
        else if(s.size() == g.size()){
            if(x < med){
                s.push(x);
                med = (double)(s.top());
            }
            else{
                g.push(x);
                med = (double)(g.top());
            }
        }
        else{
            if(x < med){
                s.push(x);
            }
            else{
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            med = (s.top() + g.top())/2.0;
        }
        all_medians.push_back(med);
    }
    return all_medians;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a[a_itr] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

