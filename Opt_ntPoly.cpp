/* 
 *  牛顿法解多项式的根
 *  输入:多项式系数c[],多项式度数n,求在[a,b]间的根
 *  输出:根 要求保证[a,b]间有根
 */
#include<bits/stdc++.h>
using namespace std;
double fabs(double x)//求绝对值
{
    return (x < 0) ? -x : x;
}

double f(int m, double c[], double x)//计算函数c(x)前m项的值
{
    int i;
    double p = c[m];
    for (i = m; i > 0; i--)
    {
        p = p * x + c[i - 1];
    }
    return p;
}

int newton(double x0, double *r, double c[], double cp[], int n, double a, double b, double eps)//
{
    int MAX_ITERATION = 1000;//规定最大迭代次数
    int i = 1;
    double x1, x2, fp, eps2 = eps / 10.0;
    x1 = x0;
    while (i < MAX_ITERATION)
    {
        x2 = f(n, c, x1);//c(x1)的值
        fp = f(n - 1, cp, x1);//c的导函数cp(x1)的值
        
        //判断不合法的情况：
        if ((fabs(fp) < 0.000000001) && (fabs(x2) > 1.0))
        {
            return 0;
        }
        
        x2 = x1 - x2 / fp;//开始迭代
        if (fabs(x1 - x2) < eps2)//如果两次得到的点的间距小于规定的误差限区间则进入判断
        {
            if (x2 < a || x2 > b)//如果解不在规定的区间内则放弃
            {
                return 0;
            }
            *r = x2;
            return 1;
        }
        x1 = x2;//一次迭代完成
        i++;
    }
    return 0;
}

double Polynomial_Root(double c[], int n, double a, double b, double eps)//n为项数，eps为误差限区间
{
    double *cp;
    int i;
    double root;
    
    cp = (double *)calloc(n, sizeof(double));//给cp分配n容量的double型内存空间
    
    for (i = n - 1; i >= 0; i--)//求导，cp存入导函数的系数
    {//由于第一项为常数项，所以最后一项x的次数是项数-1
        cp[i] = (i + 1) * c[i + 1];
    }

    if (a > b)//使a在b的左边
    {
        root = a;
        a = b;
        b = root;
    }

    if ((!newton(a, &root, c, cp, n, a, b, eps)) && (!newton(b, &root, c, cp, n, a, b, eps)))
    {
        newton((a + b) * 0.5, &root, c, cp, n, a, b, eps);
    }
    free(cp);
    if (fabs(root) < eps)
    {
        return fabs(root);
    }
    else
        return root;
}

int main()
{
    double c[100010];
    double a,b,eps;
    int n;
    cout<<"Enter number of items:"<<endl;
    cin>>n;
    cout<<"Enter coefficient:"<<endl;
    for(int i=1 ; i<=n ; i++){
        cin>>c[i];
    }
    cout<<"Enter x/y/eps:"<<endl;
    cin>>a>>b>>eps;
    double temp = Polynomial_Root(c,n,a,b,eps);
    cout<<"The proximity root is:"<<temp<<endl;
    cout<<"Error range:"<<f(n,c,temp)<<endl;
    return 0;
}