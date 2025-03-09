#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

int power(int base, int n){
  int res = 1;
  for(int i = 0; i<n; i++){
    res = res*base;
  }
 return res;
}

int main(){

  int num;
  int bin;
  int dec=0;

  printf("Please enter the number of digits \n");
  scanf("%d", &num);
  printf("The number of digits is %d\n", num);

  int arr[num];
  // int n = num;

  printf("Please enter the binary number\n");
  scanf("%d", &bin);
  int exp;
  int temp;

  temp = bin;

  int res = 0;

  for(int i=0; i<num; i++){ 
    temp = bin%10;
    arr[num - i -1] = temp;
    bin = bin/10; // truncates
  }

  // to look into: exp(log(a) * 2)
  // https://stackoverflow.com/questions/29787310/does-pow-work-for-int-data-type-in-c

  // printing out the number
  for(int i=0; i<num; i++){
    printf("%d", arr[i]);
  }
      
  for(int i=0; i<num; i++){
    exp = power(2, num -1 -i);
    res = exp * arr[i];
    dec = dec + res;
  }

  printf("The result is : %d", dec);
    
  return 0;
}
