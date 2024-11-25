// 2.2
int main()
{

   int x[100];

   int *ptr = x;

   // ptr +=20000;//KO
   // ptr +=20;//OK
   ptr += 200;
   *ptr = 2;
}
