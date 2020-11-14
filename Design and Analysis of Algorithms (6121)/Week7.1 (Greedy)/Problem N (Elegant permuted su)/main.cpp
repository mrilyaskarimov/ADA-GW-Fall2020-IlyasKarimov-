//
//  main.cpp
//  Problem N (Elegant permuted su)
//
//  Created by Ilyas Karimov on 11.11.20.
//
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

priority_queue<long, vector<long>, greater<long> > pq;

int main() {
    long n, num, res, i;
    scanf("%ld", &n);
    for (res = i = 0; i < n; i++){
        scanf("%ld", &num);
        pq.push(num);
    }

    //В переменной res накапливаем стоимость сложений. Пока не осталось одно число
    //(размер очереди pq больше 1), складываем два наименьших числа и заносим их сумму в pq.
    //Стоимость сложения чисел a и b равно a + b.
    while (pq.size() > 1)
    {
        long a = pq.top(); pq.pop();
        long b = pq.top(); pq.pop();
        printf("a + b = %ld\n", a+b);
        pq.push(a + b);
        res += a + b;
        printf("res: %ld",res);
    }
    printf("%ld\n", res);
    return 0;
}
