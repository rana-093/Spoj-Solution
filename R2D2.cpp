#include <bits/stdc++.h>

using namespace std;

#define maxn 20008
#define ll long long int
#define db(x) cout<<#x<<" -> "<<x<<" "<<endl
#define db2(x,y) cout<<#x<<"-> "<<x<<", "<<#y<<" -> "<<y<<endl
#define db3(x,y,z) cout<<#x<<" -> "<<x<<" , "<<#y<<" -> "<<y<<" , "<<#z<<" -> "<<z<<endl
#define prt(x) for(auto it = x.begin(); it!=x.end(); it++) { cout<<*it<<" "; } cout<<endl
#define IN freopen("input.txt","r",stdin)

const int N = (int)1e6+5;
int arr[ N ];
ll tree[ 4 * N ];
int n,k;
int lazy[ 4 * N ];

void Propagate(int node, int st, int en){
    tree[ node ] = 0;
    if(st!=en){
        lazy[ 2* node ] = 1;
        lazy[ 2 * node + 1 ] = 1 ;
    }
    lazy[ node ] = 0;
}

void build(int node, int st, int en){
    if(st==en){
        tree[ node ] = arr[ st ]; return ;
    }
    int mid = (st + en)>>1; int left = node<<1; int right =  left + 1;
    build(left,st,mid); build(right,mid+1,en);
    tree[ node ] = tree[ left ] + tree[ right ];
}

int query(int node, int st, int en , int val){
    if(lazy[ node ]){
        Propagate(node,st,en);
    }
    int mid = (st+en)>>1; int left = node<<1; int right = left + 1;
    if(tree[ node ] <= k){ return en ; }
    else{
        return query(left , st , mid , val);
    }
}

void update(int node, int st, int en, int i, int j){
    if(lazy[ node ]){
        Propagate(node,st,en);
    }
    if(i > en || j < st ){ return ; }
    if( st >= i && en <= j){
        tree[ node ] = 0;
        if(st!=en){
            lazy[ 2 * node ] = 1;
            lazy[ (2 * node) + 1 ] = 1;
        }
        return;
    }
    int mid = (st+en)>>1 ; int left = node<<1; int right = left + 1;
    update(left,st,mid,i,j); update(right,mid+1,en,i,j);
    tree[ node ] = tree[ left ] + tree[ right ];
}

int main(){
    ios_base::sync_with_stdio(false)  ; cin.tie(0);
//    IN;
    int tc;
    cin>>tc;
    while(tc--){
        cin>>k;
        cin>>n;
//        db2(k,n);
        for(int i = 1; i <= n; i++){
              cin>>arr[ i ];
//            string str;
//            getline(cin,str);
//            stringstream X(str);
//            vector< string > V ;
//            cout<<str<<endl;
//            while(getline(X, str, ' ')){
//                //V.push_back(str);
//                cout<<str<<endl;
//            }
//            for(auto ii : V){
//                cout<<ii<<endl;
//            }
//            if(V[0]=="b"){
//                int cnt = stoi(V[1]);
//                int cost = stoi(V[2]);
//                while(cnt--){
//                    arr[ i++ ] = cost;
//                }
//            }
//            else{
//                int cost = stoi(V[ 0 ]);
//                arr[ i ] = cost;
//            }

//            else{
//                string t = "";
//                for(int i = 0; str[ i ]!='\0'; i++){
//                    t+=str[ i ];
//                }
//                int amount = stoi(t);
//                arr[ i ] = amount;
//            }
              ///Input Formatting with String & habijabi. I haven't done it.
        }
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        build(1,1,n);
        ll sum = 0LL ;
        set< int > S ;
        for(int i = 1 ; i <= n; i++){
            sum+=arr[ i ];
            int pos = query(1,1,n,k);
            S.insert(pos);
            update(1,1,n,1,pos);
         //   if(tree[ 1 ]==0){ break ; }
        }
        int ships = S.size();
        cout<<ships<<" "<< (ships * k) - sum <<endl;
    }
    return 0;
}
