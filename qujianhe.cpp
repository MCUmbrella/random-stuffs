#include<iostream>
#include<map>

using namespace std;
/**
 * 假定有一个无限长的数轴 每个坐标上的数都是0，
 * 先进行n次操作，每次把x位置上数加上c，
 * 再进行m次查询，输出查询左区间l和右区间r之间（包括区间端点）所有数的和。
 * 示例输入：
 * -> 5 2
 * -> -1000000000 -10000
 * -> 1000000000 10000
 * -> 0 2000
 * -> 666 -3000
 * -> -283929 4000
 * -> -1000000000 1000000000
 * <- 3000
 * -> -666 666
 * <- -1000
 */
int main(int argc, char** argv)
{
    map<int, int> map;//模拟数轴
    int n;//操作数
    int m;//询问数
    cin>>n>>m;
    //printf("n=%d, m=%d\n", n, m);
    for(int i=0; i!=n; i++)
    {
        int x;//偏移量
        int c;//加量
        cin>>x>>c;
        map[x]+=c;
    }
    //for(const pair<int,int> &p:map) printf("map[%d] = %d\n",p.first,p.second);
    for(int i=0; i!=m; i++)
    {
        int l;//区间左边界
        int r;//区间右边界
        cin>>l>>r;
        int sum(0);//区间和
        for(auto a:map)
            if(a.first>=l&&a.first<=r)
                sum+=a.second;
        cout<<sum<<endl;
    }
}
