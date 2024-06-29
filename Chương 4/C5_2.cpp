#include<iostream>
#include<algorithm>
#define MAX 100
using namespace std;
struct  Edge{
    int s, e, w;    //s: edge start; e: edge end; w: edge weight   
};
class   Graph{
    private:
        int     n, A[MAX][MAX], chuaxet[MAX], ne, neT, T[MAX][MAX], dH;
        Edge    eArr[MAX], eArr_T[MAX];
    public:
        void    readdata();
        void    init();
        void    reinit();
        void    T_DFS(int u);
        void    Kruskal();
};
void    Graph::readdata(){
    cin>>n;
    ne=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            cin>>A[i][j];
            if((A[i][j]!=0)&&(i<j)){
                ne++;
                eArr[ne].s=i;   eArr[ne].e=j;   eArr[ne].w=A[i][j];
            }
        }
}
void    Graph::init(){
    for(int i=1; i<=n; i++){
        chuaxet[i]=1;
        for(int j=1; j<=n; j++) T[i][j]=0;
    }
}
void    Graph::reinit(){
    for(int i=1; i<=n; i++) chuaxet[i]=1;
}
void    Graph::T_DFS(int u){
    chuaxet[u]=0;
    for(int v=1; v<=n; v++)
        if((T[u][v]==1)&&(chuaxet[v]==1))   T_DFS(v);
}
bool    eCompare(Edge e1,   Edge e2){
    if(e1.w==e2.w)
        return  e1.s<e2.s;
    return  e1.w<e2.w;
}
void    Graph::Kruskal(){
    dH=0;
    init();
    sort(eArr+1, eArr+ne+1, eCompare);
    neT=0;
    for(int e=1; e<=ne; e++){
        reinit();
        T_DFS(eArr[e].s);
        if(chuaxet[eArr[e].e]==1){
            neT++;
            eArr_T[neT].s=eArr[e].s;    eArr_T[neT].e=eArr[e].e;    //cap nhat ds canh cay
            T[eArr[e].s][eArr[e].e]=T[eArr[e].e][eArr[e].s]=1;      //cap nhat ma tran ke cay
            dH+=eArr[e].w;
        }
    }
    cout<<"dH = "<<dH<<endl;
    for(int e=1; e<=neT; e++)
        cout<<eArr_T[e].s<<" "<<eArr_T[e].e<<endl;
}
int main(){
    Graph   g;
    g.readdata();   g.Kruskal();
}