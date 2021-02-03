#include <bits/stdc++.h>
#include <boost/foreach.hpp>
using namespace std;
#define pi 2*asin(1.0)
#define MAX 10000000
#define MOD 1000000007
#define _GLIBCXX_DEBUG
 
vector<long> fac(MAX);
vector<long> finv(MAX);
vector<long> inv(MAX);
vector<long> Primelist;
//template functions
/////////////////////////



struct Myheap {

    vector<long> data;
    vector<long> ans;

    void Getvec(vector<long>& vec,long N){
      
        for(long i=0;i<N;i++){
            data.push_back(vec.at(i));
        }

    }


    void Heapify(long i){//1始まりの値で指定
    //cout<<2*i<<N<<endl;
      	long N=data.size();
        while(2*i<=N){
            if(2*i==N&&data.at(i-1)<data.at(2*i-1)){
                long bx=data.at(2*i-1);
                data.at(2*i-1)=data.at(i-1);
                data.at(i-1)=bx;
                i=2*i;
            }else if(2*i<N&&data.at(2*i-1)<data.at(2*i)&&data.at(i-1)<data.at(2*i)){
                long bx=data.at(2*i);
                data.at(2*i)=data.at(i-1);
                data.at(i-1)=bx;
                i=2*i+1;
            }else if(2*i<N&&data.at(i-1)<data.at(2*i-1)){
                long bx=data.at(2*i-1);
                data.at(2*i-1)=data.at(i-1);
                data.at(i-1)=bx;
                i=2*i;
            }else{
              	break;
            }
        }

    }

    void Build_Heap(){
      long N=data.size();
        for(long i=N/2;i>=1;i--){
          //cout<<"a"<<endl;
            Heapify(i);
        }
    }

    void Heap_Insert(long x){
        data.push_back(x);
        long n=data.size();
        while(data.at(n-1)>data.at(n/2-1)){
            long bx=data.at(n-1);
            data.at(n-1)=data.at(n/2-1);
            data.at(n/2-1)=bx;
            n=n/2;
        }

    }

    vector<long> Heap_Sort(){
        long n=data.size();
        Build_Heap();
            
        while(n>0){
        ans.push_back(data.at(0));
        data.at(0)=data.at(n-1);
        data.pop_back();
        n--;
        Heapify(1);
        }
        return ans;
    }

    long Re_ans(long i){
        return ans.at(i);
    }
  
      long Re_data(long i){
        return data.at(i);
    }

};



//Answer

double length(vector<double> L,long N){
    double ans=0;
    for(long i=0;i<N;i++){
        ans+=pow(L.at(i),2);
    }
    return pow(ans,0.5);
}

double naiseki(vector<double> L,vector<double> M,long N){
    double ans=0;
    for(long i=0;i<N;i++){
        ans+=L.at(i)*M.at(i);
    }
    return ans;
}


int main() {
long N;
cin>>N;
vector<vector<double>> x(N,vector<double>(N));
vector<vector<double>> y(N,vector<double>(N));
vector<vector<double>> a(N,vector<double>(N));
for(long i=0;i<N;i++){
    for(long j=0;j<N;j++){
        cin>>x.at(i).at(j);
    }
}
for(long k=0;k<N;k++){
    for(long i=0;i<N;i++){
        y.at(k).at(i)=x.at(k).x.at(i);
    }
    for(long j=0;j<k;j++){
        double xkai=naiseki(x.at(k),a.at(j),N)
        for(long i=0;i<N;i++){
            y.at(k).at(i)-=xkai*a.at(j).at(i);
        }
    }
    long nagasa=length(y.at(k),N);
    for(long i=0;i<N;i++){
        a.at(k).at(i)=y.at(k).at(i)/nagasa;
    }
}



}






