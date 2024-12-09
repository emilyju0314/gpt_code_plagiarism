void f_2(){

    Stek<vector<int> > s;
   vector<int> a;
   for (int i(1); i<6; i++) a.push_back(i);
   vector<int> b;
   b.push_back(6);
   b.push_back(8);
   vector<int> c;
   c.push_back(9);
   c.push_back(10);
   c.push_back(130);
   vector<int> d;
   d.push_back(157);
   d.push_back(226);
   d.push_back(1337);
   s.stavi(a);
   s.stavi(b);
   s.stavi(c);
   s.stavi(d);
   pretraga(s,225256);

   cout << endl;
}