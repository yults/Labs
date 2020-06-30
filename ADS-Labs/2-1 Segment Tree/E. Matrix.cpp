//ТЛ предотвращается путем выбора С++11
/* но по-хорошему можно переписать и зайдет на любом
если сделать чтобы функция умножения матриц не возвращала матрицу,
а принимала в первом аргументе ссылку на матрицу и прям его умножала
Так мы не создаем новый объект
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
struct Matrix
{
    int a0;
    int a1;
    int a2;
    int a3;
};

Matrix t[800001];
Matrix a[200000];
Matrix E = {1, 0, 0, 1};

int r;

Matrix calc(Matrix A, Matrix B)
{
	Matrix ans;
    ans.a0 = (A.a0 * B.a0 + A.a1 * B.a2) % r;
    ans.a1 = (A.a0 * B.a1 + A.a1 * B.a3) % r;
    ans.a2 = (A.a2 * B.a0 + A.a3 * B.a2) % r;
    ans.a3 = (A.a2 * B.a1 + A.a3 * B.a3) % r;
    return ans;
}

Matrix ans (int left, int right, int x, int lx, int rx)
{
    if (left >= right)
        return E;
    if (left == lx && rx == right)
      return t[x];
    int m = (rx + lx) / 2;
    Matrix sl = ans(left, min(right, m), 2 * x + 1, lx, m);
    Matrix sr = ans(max(m, left), right, 2 * x + 2, m, rx);
    return calc(sl, sr);
}

 void build(int x, int lx, int rx)
{
  if (rx - lx == 1)
    {
    t[x] = a[lx];
    return;
    }
  int m = (rx + lx) / 2;
  build(2 * x + 1, lx, m);
  build(2 * x + 2, m, rx);
  t[x] = calc(t[2 * x + 1], t[2 * x + 2]);
  return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ifstream cin("crypto.in");
    ofstream cout("crypto.out");
    int n, m;
    cin >> r >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> a[i].a0 >> a[i].a1 >> a[i].a2 >> a[i].a3;
    build(0, 0, n);
    for (int i = 0; i < m; i++)
    {
        int left, right;
        cin >> left >> right;
        Matrix matrix = ans(left - 1, right, 0, 0, n);
        cout << matrix.a0 << ' ' << matrix.a1 << endl << matrix.a2 <<' ' << matrix.a3 << endl << endl;
    }
    return 0;
}
