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
void Prinit(){
long PR=10000001;
vector<long> P(PR,0);
for(long i=2;i*i<PR;i++){
    if(P.at(i)==0){
        long j=i;
      j+=i;
        while(j<PR){
            P.at(j)=1;
             j+=i;         
        }
    }
}
 
for(long i=2;i*i<PR;i++){//Primelist.size()=446
    if(P.at(i)==0){
        Primelist.push_back(i);
    }
}
}
 
void Cominit(){
  fac.at(0)=fac.at(1)=1;
  finv.at(0)=finv.at(1)=1;
  inv.at(1)=1;
  for(long i=2;i<MAX;i++){
      fac.at(i)=(fac.at(i-1)*i)%MOD;
      inv.at(i)=MOD-inv.at(MOD%i)*(MOD/i)%MOD;
      finv.at(i)=finv.at(i-1)*inv.at(i)%MOD;
  }
}
 
long facComb(long N,long M){// nCm%
if(N<M) return 0;
if(N<0||M<0) return 0;
return fac.at(N)*(finv.at(M)*finv.at(N-M)%MOD)%MOD;
}
 
long Comb(long N,long M){// nCm
long ans=1;
for(long i=N;i>N-M;i--){
    ans=ans*i;
}
for(long i=M;i>0;i--){
    ans=ans/i;
}
return ans;
}
 
long Perm(long N,long M){// nPm
long ans=1;
for(long i=N;i>N-M;i--){
    ans=ans*i;
}
return ans;
}
 
 
 
 
 
 
 
long GCM(long A,long B){
            long W,r;
    if(A<B){
 
        W=B;
        B=A;
        A=W;
    }
    while(A%B!=0){
        r=A%B;
        A=B;
        B=r;
    }
    return B;
}
long LCM(long A,long B){
    return (A*B)/GCM(A,B);
}
 
long upDiv(long a,long b){
  return (a+b-1)/b;
}
 
long strtolong(string str){
istringstream ss;
ss=istringstream(str);
long num;
ss>>num;
return num;
}
 
long chartolong(char ch){
long num;
num=ch-'0';
return num;
}
 
long Max2(long a,long b){
if(a>b){
    return a;
}else{
    return b;
}
}
 
long Max3(long a,long b,long c){
if((a<=b&&b<=c)||(b<=a&&a<=c)){
    return c;
}else if((b<c&&c<a)||(c<b&&b<a)){
    return a;
}else{
    return b;
}
}
 
 
 
 
long Min2(long a,long b){
if(a>b){
    return b;
}else{
    return a;
}
}
 
long Min3(long a,long b,long c){
if((a>b&&b>c)||(b>a&&a>c)){
    return c;
}else if((b>c&&c>a)||(c>b&&b>a)){
    return a;
}else{
    return b;
}
}
 
 
string longtostr(long N){
    string str;
    str=to_string(N);
    return str;
}
 
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}



/////////////////////////


//Answer


int main() {
long N;
cin>>N;
vector<long> a(N);
vector<long> sum(N+1,0);//sum.at(i)=a.at(i-1)までの和
vector<vector<long>> dp(N,vector<long>(N));
for(long i=0;i<N;i++){
cin>>a.at(i);
sum.at(i+1)=a.at(i)+sum.at(i);
}

for(long i=1;i<N;i++){
    for(long j=0;j+i<N;j++){
        long s=j;
        long e=j+i;
        long min=dp.at(s).at(s)+dp.at(s+1).at(e);
        for(long k=0;k<i;k++){
            if(min>dp.at(s).at(s+k)+dp.at(s+k+1).at(e)){
                min=dp.at(s).at(s+k)+dp.at(s+k+1).at(e)
            }
        }
        dp.at(j).at(j+i)=min+(sum.at(j+i+1)-sum.at(j));
    }
}
for(long i=1;i<N;i++){
    for(long j=0;j+i<N;j++){
        cout<<i<<","<<j<<":"<<dp.at(j).at(j+i)<<endl;;
    }
}
cout<<dp.at(0).at(N-1)<<endl;

}





/*高精度要求→しつこくlong doubleでcast　出力はprintf("20.20Lf")とかで

labs(-2)//long型の絶対値

出力の精度を上げるには、cout<< fixed << setprecision(10) << answer<<endl;

//printf("%a.bLf")のとき、a-b-1が整数部分の桁数。
配列系の書き方
long N;
cin>>N;
vector<long> p(N);
for(long i=0;i<N;i++){
cin>>p.at(i);
}

vector<int> d(102,1);

sort(A.begin(),A.end());
reverse(A.begin(),A.end());

ソート後のvec探索
binary_search(A.begin(),A.end(),K);//K=探す値　戻り値はbool

//場所を含めた探索
sort(v.begin(),v.end());
auto itr1=lower_bound(ALL(v),N);
cout<<itr1-v.begin()//N以上の値が登場する最初の配列番号を返す
if(v.at(itr1)==N)//v内にNが存在したらtrue

//型宣言と二次元配列

typedef pair<long,long> P;
vector<P> p(N);
vector<vector<vector<long>>> dp(N+1,vector<vector<long>>(W+1,vector<long>(K+1)));
vector<vector<long>> A(N,vector<long>(M));


int a='A'+2;
cout<<a<<endl;　//a=67 文字は整数型に代入して文字コード化できる。

  char c=65;
cout<<c<<endl;  //c='A' 整数は文字型に代入してその整数が文字コードとしてあらわす整数にできる。


BOOST_FOREACHの使い方
const int ar[] = {3, 1, 4};
    BOOST_FOREACH (int x, ar) {
        std::cout << x << std::endl;
    }





/////////最頻値を求める///

long N;
cin>>N;
typedef pair<long,long> P;
vector<long> A(N);
map<long,long> mp;
priority_queue<P> que;
P pp;
long a;
for(long i=0;i<N;i++){
    cin>>a;
    mp[a]=mp[a]+1;
}
BOOST_FOREACH(pp,mp){
  P ps=make_pair(pp.second,pp.first);
    que.push(ps);
}
//P p=que.top();
//cout<<p.first<<" "<<p.second<<endl;

    P item = que.top();
    cout << item.second << " " << item.first <<endl;

////////////////////////////////

2値全パターン列挙法
int main() {
  // 3ビットのビット列をすべて列挙する
  for (int tmp = 0; tmp < (1 << 3); tmp++) {
    bitset<3> s(tmp);
    // ビット列を出力
    cout << s << endl;
  }
}

ヒープソート（詳細はアルゴリズム演習ー１）
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



vectorの操作

std::vector<int> v;       // 空の動的配列を生成
    v.push_back(123);     // 末尾に 123 を追加


//幅優先探索
struct Edge {
    long to;
};
using Graph = vector<vector<Edge>>

//
Graph H(N);
for(long i=0;i<N;i++){
    for(long j=0;j<N;j++){
        if(c.at(i).at(j)==1){
            H[i].push_back({j});
            H[j].push_back({i});
        }
    }
}
vector<bool> seen2;  // 探索したか記録
seen2.assign(N,false);
queue<long> Q2;
count=0;
vector<long long> e(N,0);
 
for(long i=0;i<N;i++){
    Q2.push(i);
    count=0;
    while(Q2.size()){
        long j=Q2.front();
        Q2.pop();
        if(!seen2[j]){
            seen2[j] = true;
            count++;
            for (auto e : H[j]) {
                Q2.push(e.to);
            }
        }
    }
    e.at(i)=count;
}
long long ans2=1;
    for(long i=0;i<N;i++){
        ans2=(ans2*fac.at(e.at(i)))%MOD;
    }
long long ans=(ans1*ans2)%MOD;
 
cout<<ans<<endl;
 
 
}



*/
