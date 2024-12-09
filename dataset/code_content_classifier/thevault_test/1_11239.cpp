string multiply(string num1, string num2, int lowerBound, int upperBound)
{
  int len1 = num1.length();
  int len2 = num2.length();
  //cout << (len1 + len2) << endl;
   if (len1 == 0 || len2 == 0)
    return "0";

  // Below two indexes are used to find positions
  // in result.
  int i_n1 = lowerBound;
  int i_n2 = 0;

  // Go from right to left in num1
  for (int i=upperBound; i >=lowerBound; i--)
    {
      int carry = 0;
      int n1 = num1[i] - '0';

      // To shift position to left after every
      // multiplication of a digit in num2
      i_n2 = 0;

      // Go from right to left in num2
      for (int j=len2-1; j>=0; j--)
        {
          // Take current digit of second number
          int n2 = num2[j] - '0';
 // Store result

          // Multiply with current digit of first number
          // and add result to previously stored result
          // at current position.
          int sum = n1*n2 + result[i_n1 + i_n2] + carry;

          // Carry for next iteration
          carry = sum/10;
          sem_wait(&semaphore);
          result[i_n1 + i_n2] = sum % 10;
          sem_post(&semaphore);

          i_n2++;
        }

      // store carry in next cell
      if (carry > 0){
        sem_wait(&semaphore);
        result[i_n1 + i_n2] += carry;
        sem_post(&semaphore);
      }
      // To shift position to left after every
      // multiplication of a digit in num1.
      i_n1++;
    }

  return "\n";
 }