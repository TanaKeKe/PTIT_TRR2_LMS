#include <iostream>
#define Max 100
#define INF 10000000
using namespace std;
class Dothi{
    int n, s;
    int a[Max][Max];
    bool chuaxet[Max];
    int trace[Max];
    int dist[Max];
    public:
    void readData();
    void init();
    void Bell();
    void print();
};
void Dothi:: readData(){
    cin >>n>>s;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cin >>a[i][j];
    }
}
void Dothi::init(){
    for(int i=1; i<=n; i++){
        dist[i]=INF;
    }
}
void Dothi::print(){
    for(int i=1; i<=n; i++){
        if(dist[i] != INF){
            cout <<"K/c " <<s<<" -> "<<i<<" = "<<dist[i]<<";    ";
            int tmp=i; 
            cout <<tmp;
            do{
                cout <<" <- "<<trace[tmp];
                tmp = trace[tmp];
                
            }while(trace[tmp] != tmp);
                cout <<endl;
        }
        else cout << "K/c " <<s<<" -> "<<i<<" = INF"<<endl;
    }
}

void Dothi ::Bell(){
    dist[s]=0;
    trace[s]=s;
    for(int k=1; k <=n; k++){
        for(int i=1; i<=n; i++){
            for(int v=1; v<=n; v++){
                if(a[i][v] != 0 && dist[i]+ a[i][v] <dist[v]){
                    dist[v]= dist[i]+ a[i][v];
                    trace[v]=i;
                }
            }
        }
    }
}
int main(){
    Dothi g;
    g.readData();
    g.init();
    g.Bell();
    g.print();
    return 0;
}