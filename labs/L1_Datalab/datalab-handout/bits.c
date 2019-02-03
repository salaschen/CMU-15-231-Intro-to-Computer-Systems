/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(x & y) & (~(~x & ~y));
  // debug
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return (1 << 31);
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    int t1 = (x+1) ;    // t1 should be TMin and not 0
    int t2 = !t1 ;   // t2 should be 0 if t1 is not 0.
    int t3 = t1 ^ x ;   // t3 should be all 1's
    int t4 = ~t3 ;      // t4 should be all 0's
    // total op is 7.
  return  (!(t4)) & !t2  ;
}

/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
    // t1 should be 0xAAAAAAAA
    int t1 = 0xAA + (0xAA << 8) + (0xAA << 16) + (0xAA << 24) ;
    // t2 will equal to t1 *if and only if* all the odd bits are set.
    int t2 = x & t1 ; 
    // t3 will be all 0's if t1 == t2.
    int t3 = t1 ^ t2 ; 
    // total ops is 9.
  return !t3;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return (~x+1);
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    // all the higher Bits should be 0
    // this variable will be 1 if the higher bits are 0, 0 otherwise.
    int t1 = ~(0xFF) & x ; 

    // For the lower 8 bits. The Higher 4 should be 0011
    int t2 = 0xF0 & x ; 
    int t3 = t2 ^ 0x30 ; // t3 should be all 0s
    // int t4 = !t3 ; // t4 should be 1.

    // For the lower 8 bits. The lower 4 should be from 0000 to 1001
    // check if the 1100 is set or 1010 is set.
    // if so t5 will be 1, else t5 will be 0.
    // same for t6.
    int t5 = !((x & 0xC)^(0xC)) ;
    int t6 = !((x & 0xA)^(0xA)) ;
    
    return !(t1 | t3) & !(t5 | t6);
    // total ops: 15
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    // will be either 0 or 1.
    int xcond = !(!x) ;

    // ymask will be 0xFFFFFFFF if xcond is 1
    // will be 0 if xcond is 0.
    int ymask = (~xcond)+1 ;
    int zmask = ~ymask ;

    return (y & ymask) | (z & zmask);
}

/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    // need to handle when y is Tmin.
    int negY = ~y + 1 ; 

    // test if x == y
    // 1 if x == y, 0 otherwise.
    int xEqualY = !(x^y) ; 

    // int highestBit = 0x1 << 31 ; 
    int DifferentSign = (((x ^ y) >> 31) & 0x1) ; 
    int xIsNeg = (x >> 31) & 0x1;
        
    // t1 = x-y
    int t1 = x+negY ; 

    // t2 = -t1, test if t2 >= 0
    int t2 = ~t1 + 1 ; 

    // test if the highest bit is set.
    // if highest bit is set, then t2 is negative and !t3 is 0. 
    // t3 is 1 if t2 is negative, 0 otherwise.
    int t3 = !(t2 & (0x1 << 31)) ; 

    // printf("t0=%X,t1=%X,t2=%X,t3=%X\n", t0,t1,t2,t3) ; // debug
    // printf("x=%d,y=%d,DifferentSign=%d, xIsNeg=%d\n", 
    //        x,y,DifferentSign, xIsNeg) ; // debug

    return  (((DifferentSign) & xIsNeg) | t3 | xEqualY) & !((DifferentSign) & !xIsNeg) ;
    // total ops: 22
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
    // implement the ! using all operators except !.
    // max ops: 12
    // rating: 4
    
    // try to test if x is zero
    // t0 is 1 when the highest bit of x is 0.
    int t0 = (x >> 31 & 0x1)^0x1 ; 
    // t1 = -t0
    int t1 = ~x+1; 
    // t2 is 1 when the highest bit of t1 is 0.
    int t2 = (t1 >> 31 & 0x1)^0x1 ;
    // only zero has the property of 1) highest bit is zero.
    // 2) its negation's highest bit is zero.
    int xIsZero = t0 & t2 ;

    return xIsZero ;
    // total ops: 9
}

/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    /**
    * Inspired by Nikita Chepanov - nchepano@andrew.cmu.edu
    * To find the number of bits needed, it's
    * 1) for negative number: find the most significant 0.
    * 2) for non-negative number: find the most significant 1.
    * But we're going to cast x to positive anyway.
    *
    * The basic idea is to use binary search to find the most
    * significant bit. Starting from the highest 16 bit.
    */

    // cast y to the positive number that has the same result bits
    // with x.
    int y = x^(x>>31) ;

    // setting up the bit masks
    int mask1 = 2 ;           // 10
    int mask2 = 12 ;          // 1100
    int mask4 = 0xF0 ;        // 0xF0
    int mask8 = (0xFF) << 8 ; // 0xFF00
    int mask16 = ((0xFF << 8) | (0xFF)) << 16 ; // 0xFFFF0000

    int bitnum ;
    int result = 1 ;

    // whether in the higher 16 bits has a 1.
    // if so, t0 will be 1, otherwise 0.
    int t0 = !!(mask16 & y) ;
    // bitnum is 16 if t0 is 1. meaning we can continue search 
    // in the higher 16 bits.
    // otherwise bitnum is 0 << 4 is still 0.
    bitnum = t0 << 4 ; 
    result += bitnum ; 
    // skip the lower bits if necessary.
    y = y >> bitnum ; 

    t0 = !!(mask8 & y) ; bitnum = t0 << 3 ; // same as above, bitnum = 8 if t0 = 1
    result += bitnum ; y = y >> bitnum ;

    t0 = !!(mask4 & y) ; bitnum = t0 << 2 ; result += bitnum ; y = y >> bitnum ;

    t0 = !!(mask2 & y) ; bitnum = t0 << 1 ; result += bitnum ; y = y >> bitnum ;

    t0 = !!(mask1 & y) ; bitnum = t0 ; result += bitnum ; y = y >> bitnum ;

    return result+(y&1) ;
   return result ;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int isNaN(unsigned uf) ;
int isDenormalized(unsigned uf)
{
    unsigned emask = ((1 << 8) - 1) << 23 ;
    if ((uf & emask) == 0) {
        return 1 ;
    }
    return 0 ;
}
unsigned floatScale2(unsigned uf)
{   
    if (isNaN(uf) == 1) {
       return uf ;
    }
    else if (isDenormalized(uf) == 1) {
        int topBit = !!(uf & (1 << 31)) ;
        unsigned result = (topBit << 31) | (uf << 1) ;
        return result ;
    }
    else {
        unsigned emask = ((1 << 8) - 1) << 23 ;
        unsigned epart = (((uf & emask) >> 23) + 1) << 23 ;
        unsigned other = (uf & (~emask)) ;
        unsigned all = epart | other ;
        return all ;
    }
}

int isNaN(unsigned uf) 
{
    int eMask = (~((1<<23)-1)) ^ (1 << 31) ;
    int mMask = (1 << 23) - 1 ;
    int exp = (uf & eMask) >> 23 ;
    int lowEMask = eMask >> 23 ;
    
    int t = ((~exp) & lowEMask)  ;
    if (t == 0) {
        return 1 ; 
    }
    else {
        return 0 ;
    }
}   

/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  return 2;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    return 2;
}
