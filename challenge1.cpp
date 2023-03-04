#include <complex>
#include <iostream>
#include <cmath>
#include <iterator>
using std::cout;
using std::endl;
using namespace std;

//ivan reversal
unsigned int bitReverse(unsigned int a,int b)
{
  unsigned int var1;
  unsigned int var2;
  int i;
  
  var2 = 0;
  var1 = a;
  for (i = 0; i < b; i = i + 1) {
    var2 = var2 << 1 | var1 & 1;
    var1 = var1 >> 1;
  }
  return var2;
}






// //zach reversal modified to compile 
template<class T>
void fft(T x1, T x2, int num)
{
    typedef typename iterator_traits<T>::value_type complex;
    complex func_com(0, 1);
    unsigned int shifted_num = 1 << (num);


    for(unsigned int i = 0; i < shifted_num; ++i)
    {
      x2[bitReverse(i, num)] = x1[i];
    }

    for (int j = 1; j <= num; ++j) {
      int first_shift = 1 << j;
      int second_shift = first_shift >> 1;
      complex loop_com(1, 0);
      complex loop_com2 = exp(-func_com * (3.1415/second_shift));
      for (int k=0; k < second_shift; ++k) {
        for (int l=k; l < shifted_num; l += first_shift) {
          complex a = loop_com * x2[l + second_shift];
          complex b = x2[l];
          x2[l] = a + b;
          x2[l + second_shift] = b - a;
        }
        loop_com *= loop_com2;
      }
  }
}



//zach reversal
int main()
{
    // basic_ostream *output;


    typedef complex<double> db;
    db x1[] = { db(0,0), db(1,1),db(3,3),db(4,4),db(4,4),db(3,3),db(1,1),db(0,0)};
    db x2[8];


    fft(x1, x2, 3);


    for(long int i = 0; i < 8; ++i)
    {
        cout << x2[i] << "\n";
    }
}


// //first attempt

// // void fft(std::complex<double> *a, std::complex<double> *b, int c)
// // {
// // //   unsigned int reversedbit;
// // //   int loopnum2;
// // //   unsigned int loopnum1;
// // //   int loopnum3;
// // //   long conditionalvar2;
// // //   undefined8 out1;
// // //   undefined8 out2;
// // //   undefined8 out3;
// // //   double picalc;
// // //   unsigned int i;
// // //   int j;
// // //   int k;
// // //   int l;
// // //   double picalctemp1;
// // //   undefined8 num1;
// // //   undefined8 bignumconstant1;
// // //   undefined8 bignumconstant2;
// // //   undefined8 numthatstores0;
// // //   std::complex<double> local_58 [8];
// // //   double picalctemp4;
// // //   std::complex<double> local_48 [8];
// // //   double picalctemp2;
// // //   undefined8 calcvar;
// // //   double picalctemp3;
// // //   long conditionalvar1;
  
// // //   conditionalvar1 = *(long *)(conditionalvar2 + 40);
// // //   num1 = 0;
// // //   bignumconstant1 = 4607182418800017408;
// // //   loopnum1 = 1 << ((byte)c & 31);
// // //   for (i = 0; i < loopnum1; i = i + 1) {
// // //     reversedbit = bitReverse(i,c);
// // //     *(undefined8 *)(b + (unsigned long int)reversedbit * 16) = *(undefined8 *)(a + (unsigned long int)i * 16);
// // //     *(undefined8 *)((long)(b + (unsigned long int)reversedbit * 16) + 8) =
// // //          *(undefined8 *)((long)(a + (unsigned long int)i * 16) + 8);
// // //   }
// // //   for (j = 1; j <= c; j = j + 1) {
// // //     loopnum3 = 1 << ((byte)j & 31);
// // //     loopnum2 = loopnum3 >> 1;
// // //     bignumconstant2 = 4607182418800017408;
// // //     numthatstores0 = 0;
// // //     picalc = 3.1415926536 / (double)loopnum2;
// // //     picalctemp1 = picalc;
// // //     std::operator-((complex *)&num1);
// // //     picalctemp2 = picalc;
// // //     std::operator*(local_48,&picalctemp1);
// // //     calcvar = out1;
// // //     picalctemp3 = picalc;
// // //     std::exp<double>((complex *)&calcvar);
// // //     picalctemp4 = picalc;
// // //     for (k = 0; k < loopnum2; k = k + 1) {
// // //       for (l = k; l < (int)loopnum1; l = l + loopnum3) {
// // //                     /* try { // try from 00101056 to 00101108 has its CatchHandler @ 00101153 */
// // //         std::operator*((complex *)&bignumconstant2,b + (long)(loopnum2 + l) * 16);
// // //         calcvar = *(undefined8 *)(b + (long)l * 16);
// // //         picalctemp3 = *(double *)((long)(b + (long)l * 16) + 8);
// // //         picalctemp2 = picalc;
// // //         std::operator+((complex *)&calcvar,local_48);
// // //         *(undefined8 *)(b + (long)l * 16) = out2;
// // //         *(double *)((long)(b + (long)l * 16) + 8) = picalc;
// // //         std::operator-((complex *)&calcvar,local_48);
// // //         *(undefined8 *)(b + (long)(loopnum2 + l) * 16) = out3;
// // //         *(double *)((long)(b + (long)(loopnum2 + l) * 16) + 8) = picalc;
// // //       }
// // //       std::complex<double>::operator*=((complex<double> *)&bignumconstant2,local_58);
// // //     }
// // //   }
// // //   if (conditionalvar1 != *(long *)(conditionalvar2 + 40)) {
// // //                     /* WARNING: Subroutine does not returshifted_num*/
// // //     __stack_chk_fail();
// // //   }
// // //   return;


// //     //changing undefined 
// //     unsigned int reversedbit;
    
// //     unsigned int loopnum1;
// //     int loopnum2;
// //     int loopnum3;
    
// //     long conditionalvar1;
// //     long conditionalvar2;
    
// //     long int out1;
// //     long int out2;
// //     long int out3;
    
// //     double picalc;
   
// //     double picalctemp1;
// //     double picalctemp2;
// //     double picalctemp3; 
// //     double picalctemp4;
    
// //     long int num1;
    
// //     long int bignumconstant1;
// //     long int bignumconstant2;
    
// //     long int numthatstores0;
    
// //     std::complex<double> local_58 [8]; //array of complex numbers
// //     std::complex<double> local_48 [8]; //array of complex numbers //8 numbers oshifted_numoutput //8 numbers oshifted_numarray
    
    

// //     long int calcvar;
    
// //     conditionalvar1 = *(long *)(conditionalvar2 + 40);
    
// //     num1 = 0;
    
// //     bignumconstant1 = 4607182418800017408;
    
// //     //loopnum1 = 1 << ((byte)c & 31);
// //     loopnum1 = 1 << (c & 31);
// //     for (int i = 0; i < loopnum1; i = i + 1) {
// //         reversedbit = bitReverse(i,c);
// //         *(long int *)(b + (unsigned long int)reversedbit * 16) = *(long int *)(a + (unsigned long int)i * 16);
// //         *(long int *)((long)(b + (unsigned long int)reversedbit * 16) + 8) = *(long int *)((long)(a + (unsigned long int)i * 16) + 8);
// //     }
// //     for (unsigned int j = 1; j <= c; j = j + 1) {
// //         // loopnum3 = 1 << ((byte)j & 31);
// //         loopnum3 = 1 << (j & 31);

// //         loopnum2 = loopnum3 >> 1;
// //         bignumconstant2 = 4607182418800017408;
// //         numthatstores0 = 0;
// //         picalc = 3.1415926536 / (double)loopnum2;
// //         picalctemp1 = picalc;
        
// //         //std::operator-((complex *)&num1); //cehck asm to translate 
// //         //guess translatioshifted_num
// //         picalctemp1 -= num1;


// //         picalctemp2 = picalc;
        
// //         std::operator*(local_48,&picalctemp1); //cehck asm to translate


// //         calcvar = out1;
// //         picalctemp3 = picalc;
// //         std::exp<double>((complex *)&calcvar); //cehck asm to translate
        
// //         picalctemp4 = picalc;
// //         for (int k = 0; k < loopnum2; k = k + 1) {
// //             for (int l = k; l < (int)loopnum1; l = l + loopnum3) {
// //                             /* try { // try from 00101056 to 00101108 has its CatchHandler @ 00101153 */
// //                 std::operator*((complex *)&bignumconstant2,b + (long)(loopnum2 + l) * 16);
// //                 calcvar = *(long int *)(b + (long)l * 16);
// //                 picalctemp3 = *(double *)((long)(b + (long)l * 16) + 8);
// //                 picalctemp2 = picalc;
// //                 std::operator+((complex *)&calcvar,local_48);
// //                 *(long int *)(b + (long)l * 16) = out2;
// //                 *(double *)((long)(b + (long)l * 16) + 8) = picalc;
// //                 std::operator-((complex *)&calcvar,local_48);
// //                 *(long int *)(b + (long)(loopnum2 + l) * 16) = out3;
// //                 *(double *)((long)(b + (long)(loopnum2 + l) * 16) + 8) = picalc;
// //             }
// //             std::complex<double>::operator*=((complex<double> *)&bignumconstant2,local_58);
// //         }
// //     }

// //     //possible compiler generated background line 
// //     // if (conditionalvar1 != *(long *)(conditionalvar2 + 40)) {
// //     //                     /* WARNING: Subroutine does not returshifted_num*/
// //     //     __stack_chk_fail();
// //     // }
// //     return;
// // }
// //first attempt
// // int main(void)
// // {
// // //   basic_ostream *resultoutput;
// //   long j;
// //   long int *loopnum;
// //   long offsetvar;
// //   int i;
// //   long int input1;
// //   long int zero1;
// //   long int bignum1;
// //   long int bignum2;
// //   long int bignum3;
// //   long int bignum4;
// //   long int bignum5;
// //   long int bignum6;
// //   long int bignum7;
// //   long int bignum8;
// //   long int bignum9;
// //   long int bignum10;
// //   long int bignum11;
// //   long int bignum12;
// //   long int zero2;
// //   long int zero3;
// //   long int input2 [17];
// //   long conditionalvar;
  
// //   conditionalvar = *(long *)(offsetvar + 0x28);
// //   input1 = 0;
// //   zero1 = 0;
// //   bignum1 = 4607182418800017408;
// //   bignum2 = 4607182418800017408;
// //   bignum3 = 4613937818241073152;
// //   bignum4 = 4613937818241073152;
// //   bignum5 = 4616189618054758400;
// //   bignum6 = 4616189618054758400;
// //   bignum7 = 4616189618054758400;
// //   bignum8 = 4616189618054758400;
// //   bignum9 = 4613937818241073152;
// //   bignum10 = 4613937818241073152;
// //   bignum11 = 4607182418800017408;
// //   bignum12 = 4607182418800017408;
// //   zero2 = 0;
// //   zero3 = 0;
// //   loopnum = input2;
// //   for (j = 16; j != 0; j = j + -1) { //manipulating data setting array values to zero
// //     *loopnum = 0;
// //     loopnum = loopnum + 1;
// //   }
// //   //fft<std::complex<double>*>((complex *)&input1,(complex *)input2,3);
// //   fft((std::complex<double>*)&input1,(std::complex<double>*)input2,3);
// //   for (i = 0; i < 8; i = i + 1) {
// //     // resultoutput = std::operator<<((basic_ostream *)std::cout,(complex *)(input2 + (long)i * 2));
// //     // std::operator<<(resultoutput,"\n");
// //     std::cout << (std::complex<double>*)(input2 + (long)i * 2) << endl;
// //   }

// //   //possible compiler generated background line 
// // //   if (conditionalvar != *(long *)(offsetvar + 40)) {
// // //                     /* WARNING: Subroutine does not returshifted_num*/
// // //     __stack_chk_fail();
// // //   }
// //   returshifted_num0;
// // }
// /* void fft<std::complex<double>*>(std::complex<double>*, std::complex<double>*, int) */


// second attempt reversal

// // int main(void)
// // {
// //   //basic_ostream *resultoutput; // cout out stream
// //   long j;
// //   double* iterator; //double //originally undefined8
// //   long offsetvar;
// //   int i;
// //   double input1; //double?

// //   //miguels reversal work
  
// //   //first reversal 
// //   // double input1 = 0;
// //   // double zero1 = 0.0; 
// //   // double bignum1 = 1.0;
// //   // double bignum2 = 1.0;
// //   // double bignum3 = 3.0;
// //   // double bignum4 = 3.0;
// //   // double bignum5 = 4.0;
// //   // double bignum6 = 4.0;
// //   // double bignum7 = 4.0;
// //   // double bignum8 = 4.0;
// //   // double bignum9 = 3.0;
// //   // double bignum10 = 3.0;
// //   // double bignum11 = 1.0;
// //   // double bignum12 = 1.0;
// //   // double zero2 = 0.0;
// //   // double zero3 = 0.0;

// //   //renamed variables 
// //   input1 = 0.0;
// //   double num1 = 0.0; 
// //   double num2 = 1.0;
// //   double num3 = 1.0;
// //   double num4 = 3.0;
// //   double num5 = 3.0;
// //   double num6 = 4.0;
// //   double num7 = 4.0;
// //   double num8 = 4.0;
// //   double num9 = 4.0;
// //   double num10 = 3.0;
// //   double num11 = 3.0;
// //   double num12 = 1.0;
// //   double num13 = 1.0;
// //   double num14 = 0.0;
// //   double num15 = 0.0;
// //   //16 doubles 



// //   double input2 [17]; //double
// //   long conditionalvar;
  
// //   //conditionalvar = *(long *)(offsetvar + 0x28); //mystery line

// //   //orginal decompile
// //   // input1 = 0;
// //   // zero1 = 0; //doubles
// //   // bignum1 = 4607182418800017408; //doubles
// //   // bignum2 = 4607182418800017408; //doubles
// //   // bignum3 = 4613937818241073152; //doubles
// //   // bignum4 = 4613937818241073152; //doubles
// //   // bignum5 = 4616189618054758400; //doubles
// //   // bignum6 = 4616189618054758400; //doubles
// //   // bignum7 = 4616189618054758400; //doubles
// //   // bignum8 = 4616189618054758400; //doubles
// //   // bignum9 = 4613937818241073152; //doubles
// //   // bignum10 = 4613937818241073152; //doubles
// //   // bignum11 = 4607182418800017408; //doubles
// //   // bignum12 = 4607182418800017408; //doubles
// //   // zero2 = 0; //doubles
// //   // zero3 = 0; //doubles

// //   //fixed errors and renamed variable to something that makes more sense
// //   iterator = input2;
// //   for(j = 16; j != 0; j = j -1) { // setting array(input2) to 0;
// //     *iterator = 0;
// //     iterator = iterator + 1;
// //   }

// //   //fft functioshifted_numcall

// //   //input1 is pointer to start of memory block that stores doubles or array? 
// //   // fft<std::complex<double>*>((complex *)&input1,(complex *)input2,3); //original
// //   fft<std::complex<double>*>((std::complex<double>*)&input1,(std::complex<double>*)input2,3);
  
// //   for (i = 0; i < 8; i = i + 1) {
// //     // resultoutput = std::operator<<((basic_ostream *)std::cout,(complex *)(input2 + (long)i * 2));
// //     // std::operator<<(resultoutput,"\n");
// //     cout << (input2 + (long)i * 2) << endl; //????

// //   }


// //   // if (conditionalvar != *(long *)(offsetvar + 40)) {
// //   //                   /* WARNING: Subroutine does not returshifted_num*/
// //   //   __stack_chk_fail();
// //   // }
// //   returshifted_num0;
// // }