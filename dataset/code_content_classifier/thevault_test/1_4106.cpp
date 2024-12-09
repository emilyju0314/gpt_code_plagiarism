void HugeInteger::addition(HugeInteger &adder, HugeInteger &sum) {
  sum.size = (size >= adder.size) ? size + 1 : adder.size + 1;
  delete[] sum.elems;
  sum.elems = new int[sum.size]();

  for (unsigned int i = 0; i < size; i++)
    sum.elems[i] = elems[i];

  for (unsigned int i = 0; i < adder.size; i++)
    sum.elems[i] += adder.elems[i];

  for (unsigned int i = 0; i < sum.size - 1; i++)
    if (sum.elems[i] > 9) // determine whether to carry a 1
    {
      sum.elems[i] -= 10; // reduce to 0-9
      sum.elems[i + 1]++;
    }

  if (sum.elems[sum.size - 1] == 0) {
    sum.size--;
    sum.shrink_to_fit();
  }
}