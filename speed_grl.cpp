#include <bits/stdc++.h>
using namespace std;

class DataSet{
    public:
    float distance;
    float t;
};

class UserInput{
    public:
    pair<int,int> distanceAndTime(int n){
        cout<<"Enter user "<< (n+1) << " Distance: ";
        float distance;
        cin>>distance;
        cout<<"Enter user " << (n+1) << " Time: ";
        float t;
        cin>>t;
        cout<<("======================================")<<endl;
        return make_pair(distance, t);
    }
};

class Measure{
    public:
    float MeasureSpeed(float distance, float t){
        return distance/t;
    }
};

class ShowResults{
    public:
    void display(float distance, float t, float speed){
        fstream f;
        f.open("speed.csv", ios::out | ios::app);
        f<<distance<<","<<t<<","<<speed<<"\n";
    }
};

int main()
{

    DataSet a[10];
    UserInput u;
    Measure m;
    ShowResults s;
    int n;
    cout<<"Enter the number of cars: ";
    cin>>n;
    for(int i=0;i<n;i++){
        pair<int,int> p;
        p=u.distanceAndTime(i);
        a[i].distance = p.first;
        a[i].t = p.second;
    }
    for(int i=0;i<n;i++){
        s.display(a[i].distance,a[i].t,(m.MeasureSpeed(a[i].distance,a[i].t)));
    }

    return 0;
}
