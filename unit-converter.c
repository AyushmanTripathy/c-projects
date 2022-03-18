#include <stdio.h>

double conversion_decimal[][4] = {
  {1,0.621371,3280.84,1000}, //km
  {1.60934,1,5280,1609.34}, //mile
  {3280.84,0.000189394,1,0.3048}, //feet
  {0.001,0.0621371,3.28084,1} // metre
};

char *names[] = {"km","mi","ft","m"};

int main() {
  printf("1. kilometre\n2. mile\n3. feet\n4. metre\nfrom : ");

  int from,to,input;
  double output;

  scanf("%d", &from);
  printf("to : ");
  scanf("%d", &to);
  from--; to--;
  if (from > 4 || to > 4) {
    printf("invalid input\n");
    return 1;
  }

  printf("number to convert : ");
  scanf("%d",&input);
  output = input * conversion_decimal[from][to];

  printf("%d%s = %.10g%s\n",(int)input,names[from],output,names[to]);
  return 0;
}
