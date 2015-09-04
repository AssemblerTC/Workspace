#include <stdio.h>
#define min(a, b) (a)<(b)?(a):(b)
using namespace std;

const int inf = 1<<27;
int x[41], y[41], n, dp[301][301];
int recursive(int X, int Y){
    if(X==0 && Y==0)
        return 0;
    //put here the memoization
    int ans = inf;
    for(int i=0; i<n; i++)
        if(X>=x[i] && Y>=y[i])
            ans = min(ans, 1 + recursive(X-x[i], Y-y[i]));
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int S;
        scanf("%d %d", &n, &S);
        for(int i = 0; i < n; i++)
            scanf("%d %d", &x[i], &y[i]);

        for(int X=0; X<=S; X++)
            for(int Y=0; Y<=S; Y++){
                if(X==0 && Y==0){
                    dp[X][Y]=0;
                    continue;
                }
                dp[X][Y]=inf;
                for(int i=0; i<n; i++)
                    if(X>=x[i] && Y>=y[i])
                        dp[X][Y]=min(dp[X][Y], 1 + dp[X-x[i]][Y-y[i]]);
            }
    
        int ans=inf;
        for(int X=0; X<=S; X++)
            for(int Y=0; Y<=S; Y++) 
                if(S*S==X*X + Y*Y)
                    ans=min(ans, dp[X][Y]);
        if (ans>=inf)
            printf("not possible\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
