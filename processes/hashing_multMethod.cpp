#include <iostream>


int main()
{
   int k = 123456;
   int p = 14;
   int m = (1 << 14);
   int w = 32;
   long long A = 2654435769;
   long long k_times_s = k * A;
   int hash = k_times_s >> (32-p);
   std::cout << (hash & ((1 << p) - 1));
   




   return 0;
}
