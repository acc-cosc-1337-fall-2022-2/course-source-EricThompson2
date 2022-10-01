//add include statements

//add function(s) code here
int factorial(int num) {
    int sum = 1;
    while (num > 0) {
      sum *= num;
      num--;
    }
    return sum;
}

int gcd(int num1, int num2) {
  int numSwap;
  while (num1 != num2) {
    if (num1 < num2){
      numSwap = num1;
      num1 = num2;
      num2 = numSwap;
    }
    else if (num1 > num2) {
      num1 -= num2;
    }
  }
  return num1;
}