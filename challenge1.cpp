#include <complex>
#include <iostream>
using std::cout;
using std::endl;
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


//first attempt

// void fft(std::complex<double> *a, std::complex<double> *b, int c)
// {
// //   unsigned int reversedbit;
// //   int loopnum2;
// //   unsigned int loopnum1;
// //   int loopnum3;
// //   long conditionalvar2;
// //   undefined8 out1;
// //   undefined8 out2;
// //   undefined8 out3;
// //   double picalc;
// //   unsigned int i;
// //   int j;
// //   int k;
// //   int l;
// //   double picalctemp1;
// //   undefined8 num1;
// //   undefined8 bignumconstant1;
// //   undefined8 bignumconstant2;
// //   undefined8 numthatstores0;
// //   std::complex<double> local_58 [8];
// //   double picalctemp4;
// //   std::complex<double> local_48 [8];
// //   double picalctemp2;
// //   undefined8 calcvar;
// //   double picalctemp3;
// //   long conditionalvar1;
  
// //   conditionalvar1 = *(long *)(conditionalvar2 + 40);
// //   num1 = 0;
// //   bignumconstant1 = 4607182418800017408;
// //   loopnum1 = 1 << ((byte)c & 31);
// //   for (i = 0; i < loopnum1; i = i + 1) {
// //     reversedbit = bitReverse(i,c);
// //     *(undefined8 *)(b + (unsigned long int)reversedbit * 16) = *(undefined8 *)(a + (unsigned long int)i * 16);
// //     *(undefined8 *)((long)(b + (unsigned long int)reversedbit * 16) + 8) =
// //          *(undefined8 *)((long)(a + (unsigned long int)i * 16) + 8);
// //   }
// //   for (j = 1; j <= c; j = j + 1) {
// //     loopnum3 = 1 << ((byte)j & 31);
// //     loopnum2 = loopnum3 >> 1;
// //     bignumconstant2 = 4607182418800017408;
// //     numthatstores0 = 0;
// //     picalc = 3.1415926536 / (double)loopnum2;
// //     picalctemp1 = picalc;
// //     std::operator-((complex *)&num1);
// //     picalctemp2 = picalc;
// //     std::operator*(local_48,&picalctemp1);
// //     calcvar = out1;
// //     picalctemp3 = picalc;
// //     std::exp<double>((complex *)&calcvar);
// //     picalctemp4 = picalc;
// //     for (k = 0; k < loopnum2; k = k + 1) {
// //       for (l = k; l < (int)loopnum1; l = l + loopnum3) {
// //                     /* try { // try from 00101056 to 00101108 has its CatchHandler @ 00101153 */
// //         std::operator*((complex *)&bignumconstant2,b + (long)(loopnum2 + l) * 16);
// //         calcvar = *(undefined8 *)(b + (long)l * 16);
// //         picalctemp3 = *(double *)((long)(b + (long)l * 16) + 8);
// //         picalctemp2 = picalc;
// //         std::operator+((complex *)&calcvar,local_48);
// //         *(undefined8 *)(b + (long)l * 16) = out2;
// //         *(double *)((long)(b + (long)l * 16) + 8) = picalc;
// //         std::operator-((complex *)&calcvar,local_48);
// //         *(undefined8 *)(b + (long)(loopnum2 + l) * 16) = out3;
// //         *(double *)((long)(b + (long)(loopnum2 + l) * 16) + 8) = picalc;
// //       }
// //       std::complex<double>::operator*=((complex<double> *)&bignumconstant2,local_58);
// //     }
// //   }
// //   if (conditionalvar1 != *(long *)(conditionalvar2 + 40)) {
// //                     /* WARNING: Subroutine does not return */
// //     __stack_chk_fail();
// //   }
// //   return;


//     //changing undefined 
//     unsigned int reversedbit;
    
//     unsigned int loopnum1;
//     int loopnum2;
//     int loopnum3;
    
//     long conditionalvar1;
//     long conditionalvar2;
    
//     long int out1;
//     long int out2;
//     long int out3;
    
//     double picalc;
   
//     double picalctemp1;
//     double picalctemp2;
//     double picalctemp3; 
//     double picalctemp4;
    
//     long int num1;
    
//     long int bignumconstant1;
//     long int bignumconstant2;
    
//     long int numthatstores0;
    
//     std::complex<double> local_58 [8]; //array of complex numbers
//     std::complex<double> local_48 [8]; //array of complex numbers //8 numbers on output //8 numbers on array
    
    

//     long int calcvar;
    
//     conditionalvar1 = *(long *)(conditionalvar2 + 40);
    
//     num1 = 0;
    
//     bignumconstant1 = 4607182418800017408;
    
//     //loopnum1 = 1 << ((byte)c & 31);
//     loopnum1 = 1 << (c & 31);
//     for (int i = 0; i < loopnum1; i = i + 1) {
//         reversedbit = bitReverse(i,c);
//         *(long int *)(b + (unsigned long int)reversedbit * 16) = *(long int *)(a + (unsigned long int)i * 16);
//         *(long int *)((long)(b + (unsigned long int)reversedbit * 16) + 8) = *(long int *)((long)(a + (unsigned long int)i * 16) + 8);
//     }
//     for (unsigned int j = 1; j <= c; j = j + 1) {
//         // loopnum3 = 1 << ((byte)j & 31);
//         loopnum3 = 1 << (j & 31);

//         loopnum2 = loopnum3 >> 1;
//         bignumconstant2 = 4607182418800017408;
//         numthatstores0 = 0;
//         picalc = 3.1415926536 / (double)loopnum2;
//         picalctemp1 = picalc;
        
//         //std::operator-((complex *)&num1); //cehck asm to translate 
//         //guess translation 
//         picalctemp1 -= num1;


//         picalctemp2 = picalc;
        
//         std::operator*(local_48,&picalctemp1); //cehck asm to translate


//         calcvar = out1;
//         picalctemp3 = picalc;
//         std::exp<double>((complex *)&calcvar); //cehck asm to translate
        
//         picalctemp4 = picalc;
//         for (int k = 0; k < loopnum2; k = k + 1) {
//             for (int l = k; l < (int)loopnum1; l = l + loopnum3) {
//                             /* try { // try from 00101056 to 00101108 has its CatchHandler @ 00101153 */
//                 std::operator*((complex *)&bignumconstant2,b + (long)(loopnum2 + l) * 16);
//                 calcvar = *(long int *)(b + (long)l * 16);
//                 picalctemp3 = *(double *)((long)(b + (long)l * 16) + 8);
//                 picalctemp2 = picalc;
//                 std::operator+((complex *)&calcvar,local_48);
//                 *(long int *)(b + (long)l * 16) = out2;
//                 *(double *)((long)(b + (long)l * 16) + 8) = picalc;
//                 std::operator-((complex *)&calcvar,local_48);
//                 *(long int *)(b + (long)(loopnum2 + l) * 16) = out3;
//                 *(double *)((long)(b + (long)(loopnum2 + l) * 16) + 8) = picalc;
//             }
//             std::complex<double>::operator*=((complex<double> *)&bignumconstant2,local_58);
//         }
//     }

//     //possible compiler generated background line 
//     // if (conditionalvar1 != *(long *)(conditionalvar2 + 40)) {
//     //                     /* WARNING: Subroutine does not return */
//     //     __stack_chk_fail();
//     // }
//     return;
// }
//first attempt
// int main(void)
// {
// //   basic_ostream *resultoutput;
//   long j;
//   long int *loopnum;
//   long offsetvar;
//   int i;
//   long int input1;
//   long int zero1;
//   long int bignum1;
//   long int bignum2;
//   long int bignum3;
//   long int bignum4;
//   long int bignum5;
//   long int bignum6;
//   long int bignum7;
//   long int bignum8;
//   long int bignum9;
//   long int bignum10;
//   long int bignum11;
//   long int bignum12;
//   long int zero2;
//   long int zero3;
//   long int input2 [17];
//   long conditionalvar;
  
//   conditionalvar = *(long *)(offsetvar + 0x28);
//   input1 = 0;
//   zero1 = 0;
//   bignum1 = 4607182418800017408;
//   bignum2 = 4607182418800017408;
//   bignum3 = 4613937818241073152;
//   bignum4 = 4613937818241073152;
//   bignum5 = 4616189618054758400;
//   bignum6 = 4616189618054758400;
//   bignum7 = 4616189618054758400;
//   bignum8 = 4616189618054758400;
//   bignum9 = 4613937818241073152;
//   bignum10 = 4613937818241073152;
//   bignum11 = 4607182418800017408;
//   bignum12 = 4607182418800017408;
//   zero2 = 0;
//   zero3 = 0;
//   loopnum = input2;
//   for (j = 16; j != 0; j = j + -1) { //manipulating data setting array values to zero
//     *loopnum = 0;
//     loopnum = loopnum + 1;
//   }
//   //fft<std::complex<double>*>((complex *)&input1,(complex *)input2,3);
//   fft((std::complex<double>*)&input1,(std::complex<double>*)input2,3);
//   for (i = 0; i < 8; i = i + 1) {
//     // resultoutput = std::operator<<((basic_ostream *)std::cout,(complex *)(input2 + (long)i * 2));
//     // std::operator<<(resultoutput,"\n");
//     std::cout << (std::complex<double>*)(input2 + (long)i * 2) << endl;
//   }

//   //possible compiler generated background line 
// //   if (conditionalvar != *(long *)(offsetvar + 40)) {
// //                     /* WARNING: Subroutine does not return */
// //     __stack_chk_fail();
// //   }
//   return 0;
// }
/* void fft<std::complex<double>*>(std::complex<double>*, std::complex<double>*, int) */

void fft<std::complex<double>*>(complex *param_1,complex *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  long in_FS_OFFSET;
  undefined8 extraout_XMM0_Qa;
  undefined8 extraout_XMM0_Qa_00;
  undefined8 extraout_XMM0_Qa_01;
  double dVar5;
  uint local_9c;
  int local_98;
  int local_94;
  int local_90;
  double local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  complex local_58 [8];
  double local_50;
  complex local_48 [8];
  double local_40;
  undefined8 local_38;
  double local_30;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_78 = 0;
  local_70 = 0x3ff0000000000000;
  uVar3 = 1 << ((byte)param_3 & 0x1f);
  for (local_9c = 0; local_9c < uVar3; local_9c = local_9c + 1) {
    uVar1 = bitReverse(local_9c,param_3);
    *(undefined8 *)(param_2 + (ulong)uVar1 * 0x10) =
         *(undefined8 *)(param_1 + (ulong)local_9c * 0x10);
    *(undefined8 *)((long)(param_2 + (ulong)uVar1 * 0x10) + 8) =
         *(undefined8 *)((long)(param_1 + (ulong)local_9c * 0x10) + 8);
  }
  for (local_98 = 1; local_98 <= param_3; local_98 = local_98 + 1) {
    iVar4 = 1 << ((byte)local_98 & 0x1f);
    iVar2 = iVar4 >> 1;
    local_68 = 0x3ff0000000000000;
    local_60 = 0;
    dVar5 = 3.1415926536 / (double)iVar2;
    local_80 = dVar5;
    std::operator-((complex *)&local_78);
    local_40 = dVar5;
    std::operator*(local_48,&local_80);
    local_38 = extraout_XMM0_Qa;
    local_30 = dVar5;
    std::exp<double>((complex *)&local_38);
    local_50 = dVar5;
    for (local_94 = 0; local_94 < iVar2; local_94 = local_94 + 1) {
      for (local_90 = local_94; local_90 < (int)uVar3; local_90 = local_90 + iVar4) {
                    /* try { // try from 00101056 to 00101108 has its CatchHandler @ 00101153 */
        std::operator*((complex *)&local_68,param_2 + (long)(iVar2 + local_90) * 0x10);
        local_38 = *(undefined8 *)(param_2 + (long)local_90 * 0x10);
        local_30 = *(double *)((long)(param_2 + (long)local_90 * 0x10) + 8);
        local_40 = dVar5;
        std::operator+((complex *)&local_38,local_48);
        *(undefined8 *)(param_2 + (long)local_90 * 0x10) = extraout_XMM0_Qa_00;
        *(double *)((long)(param_2 + (long)local_90 * 0x10) + 8) = dVar5;
        std::operator-((complex *)&local_38,local_48);
        *(undefined8 *)(param_2 + (long)(iVar2 + local_90) * 0x10) = extraout_XMM0_Qa_01;
        *(double *)((long)(param_2 + (long)(iVar2 + local_90) * 0x10) + 8) = dVar5;
      }
      std::complex<double>::operator*=((complex<double> *)&local_68,local_58);
    }
  }
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



undefined8 main(void)

{
  basic_ostream *pbVar1;
  long lVar2;
  undefined8 *puVar3;
  long in_FS_OFFSET;
  int local_11c;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98 [17];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_118 = 0;
  local_110 = 0;
  local_108 = 0x3ff0000000000000;
  local_100 = 0x3ff0000000000000;
  local_f8 = 0x4008000000000000;
  local_f0 = 0x4008000000000000;
  local_e8 = 0x4010000000000000;
  local_e0 = 0x4010000000000000;
  local_d8 = 0x4010000000000000;
  local_d0 = 0x4010000000000000;
  local_c8 = 0x4008000000000000;
  local_c0 = 0x4008000000000000;
  local_b8 = 0x3ff0000000000000;
  local_b0 = 0x3ff0000000000000;
  local_a8 = 0;
  local_a0 = 0;
  puVar3 = local_98;
  for (lVar2 = 0x10; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  fft<std::complex<double>*>((complex *)&local_118,(complex *)local_98,3);
  for (local_11c = 0; local_11c < 8; local_11c = local_11c + 1) {
    pbVar1 = std::operator<<((basic_ostream *)std::cout,(complex *)(local_98 + (long)local_11c * 2))
    ;
    std::operator<<(pbVar1,"\n");
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



